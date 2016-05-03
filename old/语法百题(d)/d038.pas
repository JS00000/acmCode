program d038;
var i,j,n:integer;
begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n*2+1-i*2 do write('*');
      for j:=1 to i*2-
      1 do write('$');
      writeln;
    end;
end.