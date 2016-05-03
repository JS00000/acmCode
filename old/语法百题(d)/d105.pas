program d105;
var i:integer;s,x:real;
begin
  readln(x);
  s:=13;i:=0;
  repeat
    i:=i+1;
    s:=s*(1+x/100);
  until s>20;
  writeln(i);
end.