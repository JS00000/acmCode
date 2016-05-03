program d015;
  var a,b,c:real;s:char;
  begin
    read(a,b,s,s);
    case s of
      '+':c:=a+b;
      '-':c:=a-b;
      '*':c:=a*b;
      '/':c:=a/b;
    end;
    writeln(c:0:2);
  end.