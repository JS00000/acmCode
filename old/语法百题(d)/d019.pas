program d019;
var i,n,s:longint;
begin
  s:=0;
  read(n);
  for i:=1 to n do s:=s+i;
  writeln(s);
end.