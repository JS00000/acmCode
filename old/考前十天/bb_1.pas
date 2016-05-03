program bb_1;
var i:int64;
begin
  i:=0;
  repeat
    i:=i+1;
  until i=200000000;
  writeln(i);
  readln;
end.
