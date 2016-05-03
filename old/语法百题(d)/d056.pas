program d056;
var i,j,n:integer;
begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n-i do write(' ');
      for j:=1 to i*2-1 do write('*');
      writeln;
    end;
  for i:=n-1 downto 1 do
    begin
      for j:=1 to n-i do write(' ');
      for j:=1 to i*2-1 do write('*');
      writeln;
    end;
end.