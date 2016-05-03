program d037;
var i,j,a,b:integer;
begin
  readln(a,b);
  for i:=0 to a do
    begin
      j:=a-i;
      if i*4+j*2=b then writeln(j,' ',i);
    end;
end.