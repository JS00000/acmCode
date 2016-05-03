program d072;
const n=1000;
var i,j,s:longint;
    a:array[0..n] of longint;
begin
  for i:=2 to n do
    begin
      s:=0;
      for j:=1 to i div 2 do if i mod j=0 then s:=s+j;
      a[i]:=s;
    end;
  for i:=2 to n do
    for j:=i+1 to n do
      if (a[i]=j) and (a[j]=i) then writeln(i,' ',j);
end.