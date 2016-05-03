program d043;
var n,k,a:int64;
begin
  readln(n);
  k:=0;a:=1;
  repeat
    if (n>=a) and (n<a*3) then writeln(k);
    k:=k+1;
    a:=a*3;
  until a>n;
end.