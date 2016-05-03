program d041;
var n,i:integer;s:int64;
begin
  readln(n);
  s:=1;
  for i:=2 to n do s:=s*i;
  writeln(s);
end.