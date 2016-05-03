program d102;
var n:real;
begin
  readln(n);
  if n<=3 then writeln('10.00') else
    if n<=5 then writeln((10+(n-3)*1.8):0:2) else
      writeln((13.6+(n-5)*2.7):0:2);
end.