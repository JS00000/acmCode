program d091;
var a,b,c,d,i,s:longint;
begin
  readln(a,b,c);
  s:=0;
  d:=1;
  if a=0 then s:=1 else begin
    for i:=a downto 2 do d:=d*i; s:=s+d; end;
  d:=1;
  for i:=b downto 2 do d:=d*i;
  s:=s+d;
  d:=1;
  for i:=c downto 2 do d:=d*i;
  s:=s+d;
  writeln(s);
end.