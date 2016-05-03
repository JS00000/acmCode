program d064;
var n,i:integer;s:int64;
begin
  readln(n);
  s:=1;
  for i:=1 to n do s:=s*2;
  writeln(s-1);
end.