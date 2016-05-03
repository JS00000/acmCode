program d113;
var s,n,i:longint;
begin
  s:=1;
  readln(n);
  for i:=1 to n do s:=s+i*3+1;
  writeln(s);
end.