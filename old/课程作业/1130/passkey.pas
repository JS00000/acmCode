program passkey;
type
  atype=^poi;
  poi=record
    data:char;
    num:integer;
    next:atype;
  end;
var
  head,p,q:atype;
  i,l,key,j:integer;
  st:string;
  ans:array[0..255] of char;
begin
  assign(input,'passkey.in');
  reset(input);
  assign(output,'passkey.out');
  rewrite(output);
  readln(st);
  readln(key);
  l:=Length(st);
  for i:=1 to l do ans[i]:='_';
  head:=nil;
  for i:=1 to l do
    begin
      new(p);
      p^.data:=st[i];
      p^.num:=i;
      p^.next:=nil;
      if head=nil then head:=p else q^.next:=p;
      q:=p;
    end;
  q^.next:=head;
  p:=head;
  for i:=1 to l do
    begin
      j:=1;
      while j<key do
        begin
          j:=j+1;
          q:=p;
          p:=p^.next;
        end;
      ans[p^.num]:=st[i];
      q^.next:=p^.next;
      dispose(p);
      p:=q^.next;
    end;
  for i:=1 to l do write(ans[i]);
  close(input);
  close(output);
end.