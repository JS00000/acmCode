program d045;
var s:char;i,a,b,c,n:integer;
procedure wr(a,b,c:char;x,y,z:integer);
begin
  writeln(a,' ',x);
  writeln(b,' ',y);
  writeln(c,' ',z);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(s);
      case s of
        'a','A':a:=a+1;
        'b','B':b:=b+1;
        'c','C':c:=c+1;
      end;
    end;
  if (a>=b) and (b>=c) then wr('a','b','c',a,b,c) else
  if (a>=c) and (c>=b) then wr('a','c','b',a,c,b) else
  if (b>=a) and (a>=c) then wr('b','a','c',b,a,c) else
  if (b>=c) and (c>=a) then wr('b','c','a',b,c,a) else
  if (c>=a) and (a>=b) then wr('c','a','b',c,a,b) else
  if (c>=b) and (b>=a) then wr('c','b','a',c,b,a);
end.