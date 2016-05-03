program d040;
var n,i:integer;s:real;
begin
  readln(n);
  s:=0;
  for i:=1 to n do
    s:=s+(1/i);
  writeln(s:0:6);
end.