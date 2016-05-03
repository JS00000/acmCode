program d108;
var n,i,j,c:longint;
    a:array[0..100001] of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  readln(c);
  j:=1;
  for i:=1 to n do if a[i]>c then j:=j+1;
  writeln(j);
end.