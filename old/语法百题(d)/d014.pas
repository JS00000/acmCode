program d014;
  var a,b,c,d:longint;
  begin
    read(a,b,c);
    if a<b then begin d:=a;a:=b;b:=d;end;
    if a<c then begin d:=a;a:=c;c:=d;end;
    if b<c then begin d:=b;b:=c;c:=d;end;
    if a>=b+c then writeln('Error!') else
      if a*a=b*b+c*c then writeln('Yes!') else writeln('No!');
  end.