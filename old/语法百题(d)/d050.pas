program d050;
var a,b,c,i:integer;s:char;
begin
  readln(a,b,c);
  read(s);
  for i:=1 to a do write(s);
  writeln;
  for i:=1 to b do write(s);
  writeln;
  for i:=1 to c do write(s);
end.