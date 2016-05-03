program d120;
var n:integer;
begin
  readln(n);
  if n<=6 then writeln('3') else
    if n<=16 then writeln('4') else
      if n<=26 then writeln('5') else
        if n<=36then writeln('6');
end.