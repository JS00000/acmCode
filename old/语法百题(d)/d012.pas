program d012;
  var a,b:real;
  begin
    read(a);
    if a<=1000 then b:=a*0.95 else b:=950+(a-1000)*0.9;
    writeln(b:0:2);
  end.