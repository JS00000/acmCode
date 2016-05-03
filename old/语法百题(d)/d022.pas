program d022;
var c:char;s:longint;
begin
  s:=0;
  repeat
    read(c);
    if (c='a') or (c='A') then s:=s+1;
  until c='#';
  writeln(s);
end.