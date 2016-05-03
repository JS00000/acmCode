program d076;
var i,n:integer;
    a:array[0..1001] of integer;
procedure qsort(l,r:integer);
var i,j,x,t:integer;
begin
  i:=l;j:=r;
  x:=a[(i+j) div 2];
  repeat
    while x>a[i] do i:=i+1;
    while x<a[j] do j:=j-1;
    if i<=j then
      begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
        i:=i+1;
        j:=j-1;
      end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;
begin
  i:=0;
  while not(eoln) do
    begin
      i:=i+1;
      readln(a[i]);
    end;
  n:=i;
  qsort(1,n);
  for i:=1 to n do writeln(a[i]);
end.