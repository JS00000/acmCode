program d029;
var i,j:integer;p:boolean;
begin
  for i:=2 to 100 do
  begin
    p:=true;
    for j:=2 to trunc(sqrt(i)) do
      if i mod j=0 then p:=false;
    if p then writeln(i);
  end;
end.