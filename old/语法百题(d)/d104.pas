program d104;
var i,j,n:integer;
begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n-i do write(' ');
      for j:=1 to n do write('*');
      writeln;
    end;
end.