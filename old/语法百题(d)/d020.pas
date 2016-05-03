program d020;
var s,n,i:longint;
begin
  read(n);
  s:=0;
  for i:=1 to n do
    if n mod i=0 then s:=s+i;
  writeln(s);
end.