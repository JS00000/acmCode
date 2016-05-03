program d021;
var i:integer;
begin
  for i:=1000 to 9999 do
    if ((i div 100)+(i mod 100))*((i div 100)+(i mod 100))=i then writeln(i);
  readln;
end.