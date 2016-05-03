program d017;
var y,m:longint;
begin
  read(y,m);
  if ((y mod 4=0) and (y mod 100<>0) or (y mod 400=0)) and (m=2) then writeln('29') else
    case m of
      1,3,5,7,8,10,12:writeln('31');
      2:writeln('28');
      4,6,9,11:writeln('30');
    end;
end.