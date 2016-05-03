program d061;
var i,n,j,s:integer;
    a:array[0..100,0..100] of integer;
begin
  readln(n);
  a[n,1]:=1;
  s:=0;
  for i:=n-1 downto 1 do
    begin
      s:=n-i;
      a[i,1]:=a[i+1,1]+s;
    end;
  for i:=2 to n do
    for j:=2 to i do a[i,j]:=a[i-1,j-1]+1;
  for i:=1 to n do
    begin
      for j:=1 to i do write(a[i,j],' ');
      writeln;
    end;

end.