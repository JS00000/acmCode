program d060;
var n,i,j,k:integer;
begin
  readln(n);
  k:=0;
  for i:=1 to n do
    begin
      for j:=1 to i do
        begin
          k:=k+1;
          write(k,' ');
        end;
      writeln;
    end;
end.