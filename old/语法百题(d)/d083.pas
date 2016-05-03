program d083;
var i,j,n:integer;
    a:array[0..100,0..100] of integer;
begin
  readln(n);
  for i:=1 to n do begin a[i,1]:=1;a[i,i]:=1; end;
  for i:=3 to n do
    for j:=2 to i-1 do a[i,j]:=a[i-1,j]+a[i-1,j-1];
  for i:=1 to n do
    begin
      for j:=1 to i do write(a[i,j],' ');
      writeln;
    end;
end.