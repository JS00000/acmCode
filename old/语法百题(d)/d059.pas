program d059;
var i,j,s:integer;
    a:array[1..5] of integer;
begin
  for i:=1 to 5 do read(a[i]);
  for i:=1 to 5 do
    begin
      s:=1;
      for j:=2 to a[i] div 2 do
        if a[i] mod j=0 then s:=s+j;
      if s=a[i] then write('1 ') else write('0 ');
    end;
end.