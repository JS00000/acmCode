program d046;
var x:real;i:integer;s:int64;
begin
  readln(x);
  i:=0;s:=0;
  repeat
    i:=i+1;
    s:=s+i*i;
  until s>x;
  writeln(i-1);

end.