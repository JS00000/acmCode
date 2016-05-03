program d047;
var c:char;s:integer;
begin
  s:=0;
  repeat
    read(c);
    if c=' ' then s:=s+1;
  until c='.';
  writeln(s+1);
end.