program d027;
var a,b,c,i:integer;
begin
  for i:=100 to 999 do
    begin
      a:=i div 100;
      b:=(i mod 100) div 10;
      c:=i mod 10;
      if i=a*a*a+b*b*b+c*c*c then writeln(i);
    end;
end.