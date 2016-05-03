program d106;
var h,h0,s:real;
begin
  readln(h);
  h0:=h/1000;
  s:=h;
  while h*0.7>=h0 do
    begin
      h:=h*0.7;
      s:=s+h*2;
    end;
  writeln(s:0:2);
end.
