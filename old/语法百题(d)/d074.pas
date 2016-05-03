program d074;
var i,n,b:integer;
    a:array[0..101] of integer;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do write(a[i],' ');
  writeln;
  b:=a[1];
  for i:=1 to n-1 do a[i]:=a[i+1];
  a[n]:=b;
  for i:=1 to n do write(a[i],' ');
end.
