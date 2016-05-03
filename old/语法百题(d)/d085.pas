program d085;
type atype=array[0..20] of 0..1;
var a:atype;a5,a10,n,k,i,j:integer;
    b:array[0..2000] of atype;
procedure gc(i:integer);
begin
  if a5<n then
    begin
      a5:=a5+1;
      a[i]:=0;
      gc(i+1);
      a5:=a5-1;
    end;
  if a10<a5 then
    begin
      a10:=a10+1;
      a[i]:=1;
      if i=n*2 then
        begin
          k:=k+1;
          b[k]:=a;
        end;
      gc(i+1);
      a10:=a10-1;
    end;
end;
begin
  readln(n);
  gc(1);
  writeln(k);
  for i:=1 to k do
    begin
      for j:=1 to n*2 do write(b[i][j],' ');
      writeln;
    end;
end.