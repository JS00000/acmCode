program d081;
var s:set of 0..20;n:integer;
    a:array[0..20] of integer;
procedure gc(i:integer);
var j,k:integer;
begin
  for j:=1 to n do
    if not(j in s) then
      begin
        s:=s+[j];
        a[i]:=j;
        if i=n then
          begin
            for k:=1 to n do write(a[k],' ');
            writeln;
          end else gc(i+1);
        s:=s-[j];
      end;
end;
begin
  readln(n);
  gc(1);
end.