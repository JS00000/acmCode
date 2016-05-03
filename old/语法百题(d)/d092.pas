program d092;
var a,b,m,n:integer;
function jc(n:integer):int64;
var i:integer;d:int64;
begin
  d:=1;
  for i:=2 to n do d:=d*i;
  jc:=d;
  if n=0 then jc:=1;
end;
function c(n,r:integer):int64;
begin
  c:=jc(n) div (jc(r)*jc(n-r));
end;
begin
  readln(a,b,m,n);
  writeln(c(a,b)+c(m,n));
end.