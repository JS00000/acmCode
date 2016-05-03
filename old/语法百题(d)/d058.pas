program d058;
var i,j,k:integer;
begin
  for i:=1 to 20 do
    for j:=i to 20 do
      for k:=j to 20 do
        if i*i+j*j=k*k then writeln(i,' ',j,' ',k);
end.