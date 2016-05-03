program d122;
var i,j,k,n,s:longint;
    a:array[0..100001] of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to 3 do
    begin
      s:=-maxlongint;
      for j:=1 to n do if a[j]>s then begin s:=a[j];k:=j;end;
      write(s,' ');
      a[k]:=-maxlongint;
    end;
  writeln;
end.