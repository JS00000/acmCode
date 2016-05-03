program d049;
var c:char;i,j,n:integer;
begin
  read(n,c,c);
  for i:=1 to n do
    begin
      for j:=1 to i do write(c);
      writeln;
    end;
end.