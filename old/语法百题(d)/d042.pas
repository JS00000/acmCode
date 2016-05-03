program d042;
var p:real;i:integer;
begin
  p:=1;
  for i:=1 to 1000 do
    begin
      if i mod 2=0 then p:=p+(1/(i*2+1)) else p:=p-(1/(i*2+1));
    end;
  writeln(p*4:0:4);
end.