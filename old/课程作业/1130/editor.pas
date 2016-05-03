program editor;
type
  atype=^pp;
  pp=record
    data:char;
    next,prev:atype;
  end;
var
  point,p,q,r,head:atype;
  i,n,j,t:longint;
  ch:char;

procedure move;
begin
  for i:=1 to 4 do read(ch);
  readln(n);
  point:=head;
  for i:=1 to n do point:=point^.next;
end;

procedure insert;
begin
  for i:=1 to 6 do read(ch);
  readln(n);
  q:=point;
  r:=point^.next;
  for i:=1 to n do
    begin
      read(ch);
      new(p);
      p^.data:=ch;
      p^.prev:=q;
      q^.next:=p;
      q:=p;
    end;
  if r<>nil then r^.prev:=q;
  q^.next:=r;
  readln;
end;

procedure delete;
begin
  for i:=1 to 6 do read(ch);
  readln(n);
  for i:=1 to n do
    begin
      q:=point^.next;
      point^.next:=q^.next;
      dispose(q);
    end;
  if point^.next<>nil then point^.next^.prev:=point;
end;

procedure get;
begin
  for i:=1 to 3 do read(ch);
  readln(n);
  q:=point^.next;
  for i:=1 to n do
    begin
      write(q^.data);
      q:=q^.next;
    end;
  writeln;
end;

procedure prevp;
begin
  readln;
  point:=point^.prev;
end;

procedure nextp;
begin
  readln;
  point:=point^.next;
end;


procedure main;
begin
  assign(input,'editor.in');
  reset(input);
  new(head);
  head^.next:=nil;
  head^.prev:=nil;
  point:=head;
  readln(t);
  for j:=1 to t do
    begin
      read(ch);
      case ch of
        'M':move;
        'I':insert;
        'D':delete;
        'G':get;
        'P':prevp;
        'N':nextp;
      end;
    end;
  close(input);
end;

begin
  assign(output,'editor.out');
  rewrite(output);
  main;
  close(output);
end.
