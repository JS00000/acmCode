program d121;
var a,b,c,i:integer;
function max(x,y,z:integer):integer;
begin
  if x<y then x:=y;
  if x<z then max:=z else max:=x;
end;
begin
  readln(a,b,c);
  for i:=1 to 9 do if max(a,b,c)*i<=9 then writeln(a*i,' ',b*i,' ',c*i);
end.