program d034;
var a,b,c,p,s:real;
begin
  readln(a,b,c);
  if (a+b<=c) or (a+c<=b) or (b+c<=a) then writeln('Data Error!') else
    begin
      p:=(a+b+c)/2;
      s:=sqrt(p*(p-a)*(p-b)*(p-c));
      writeln(s:0:2);
    end;
end.