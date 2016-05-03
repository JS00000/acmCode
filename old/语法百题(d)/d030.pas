program d030;
var n,m,a,i:integer;
begin
  read(n,m);
  if n>m then
    begin
      a:=n;
      n:=m;
      m:=a;
    end;
  for i:=n downto 1 do if (m mod i=0) and (n mod i=0) then
    begin
      writeln(i);
      break;
    end;
end.