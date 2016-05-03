program d033;
const n=100;
var i,j,k,s:integer;
begin
  s:=1500;
  for i:=1 to 10 do
    for j:=1 to 50 do
      begin
        if i+j+(1500-i*150-j*30)=n then writeln(i,' ',j,' ',n-i-j);
      end;
end.