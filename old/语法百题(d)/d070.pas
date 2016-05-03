program d070;
var c:char;a,b:integer;
begin
  a:=0;b:=0;
  while not eoln do
    begin
      read(c);
      if c='(' then a:=a+1;
      if c=')' then b:=b+1;
    end;
  if a=b then writeln('Yes') else
    if a>b then writeln('Left') else writeln('Right');
end.