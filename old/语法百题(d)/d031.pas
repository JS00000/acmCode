program d031;
var i,n:integer;
    a:array[0..23] of longint;
begin
  readln(n);
  a[1]:=1;a[2]:=1;
  for i:=3 to n do
      a[i]:=a[i-1]+a[i-2];
  for i:=1 to n do
    begin
      write(a[i],' ');
      if i mod 5=0 then writeln;
    end;
end.