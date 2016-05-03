program d084;
var n,a,b,c,i:longint;
begin
  readln(n);
  a:=1;
  b:=2;
  for i:=3 to n do
    begin
      c:=a+b;
      a:=b;
      b:=c;
    end;
  writeln(c);
end.