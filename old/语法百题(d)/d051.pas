program d051;
var t:0..6;
begin
  read(t);
  case t of
    0:writeln('Mon');
    1:writeln('Tue');
    2:writeln('Wed');
    3:writeln('Thu');
    4:writeln('Fri');
    5:writeln('Sat');
    6:writeln('Sun');
  end;

end.