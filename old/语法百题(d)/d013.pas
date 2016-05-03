program d013;
  var n,a:longint;
  begin
    read(n);
    if n>0 then writeln('1') else
      if n=0 then writeln('0') else
        writeln('-1');
  end.