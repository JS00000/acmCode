program d071;
var i,j,k:integer;
begin
  for i:= 1 to 60 do
    for j:= i to 60 do
      for k:=1 to i do
        begin
          if (i*i+j*j)*k*k=i*i*j*j then writeln(i,' ',j,' ',k);
        end;
end.