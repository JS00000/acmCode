program d098;
var i,j,k,m,n,r:integer;
    a,b,c:array[0..101,0..101] of longint;
begin
  readln(m,n,r);
  for i:=1 to m do
    begin
      for j:=1 to n do read(a[i,j]);
      readln;
    end;
  for i:=1 to n do
    begin
      for j:=1 to r do read(b[i,j]);
      readln;
    end;
  for i:=1 to m do
      for j:=1 to r do
        for k:=1 to n do
          c[i,j]:=c[i,j]+a[i,k]*b[k,j];
  writeln(m,' ',r);
  for i:=1 to m do
    begin
      for j:=1 to r do write(c[i,j],' ');
      writeln;
    end;
end.