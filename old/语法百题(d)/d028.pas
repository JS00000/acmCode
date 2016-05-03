program d028;
var n,i,j:integer;
begin
  read(n);
  for i:=1 to n do
    begin
      for j:=2 to i do write(' ');
      for j:=i*2 to n*2 do write('#');
      writeln;
    end;
end.