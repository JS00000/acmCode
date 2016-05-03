program d082;
var s:set of 0..20;n,r:integer;
    a:array[0..20] of integer;
procedure gc(i:integer);
var j,k:integer;
begin
  for j:=1 to n do
    if not(j in s) and (j>a[i-1]) then
      begin
        s:=s+[j];
        a[i]:=j;
        if i=r then
          begin
            for k:=1 to r do write(a[k],' ');
            writeln;
          end else gc(i+1);
        s:=s-[j];
      end;
end;
begin
  readln(n,r);
  gc(1);
end.