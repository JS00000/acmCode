program m002;
var m,i:integer;s:int64;
begin
  readln(m);
  s:=1;
  for i:=1 to m do s:=(s+1)*2;
  writeln(s);
end.