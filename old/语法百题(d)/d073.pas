program d073;
var i,n:integer;
    a:array[0..10000] of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=n downto 1  do write(a[i],' ');
end.