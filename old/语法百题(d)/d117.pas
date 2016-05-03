program d117;
var n,i:integer;
    a:array[0..50] of int64;
begin
  readln(n);
  a[1]:=2;
  a[2]:=3;
  for i:=3 to n do a[i]:=a[i-1]+a[i-2];
  writeln(a[n]);
end.