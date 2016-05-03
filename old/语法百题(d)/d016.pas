program d016;
  var a,b,c,d:real;
  begin
    read(a,b,c);
    d:=b*b-4*a*c;
    if d<0 then writeln('No answer!') else
      if d=0 then writeln(-b/2/a:0:2) else
        begin
          writeln((-b+sqrt(d))/2/a:0:2);
          writeln((-b-sqrt(d))/2/a:0:2);
        end;
  end.
