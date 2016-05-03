program d115;
var n,k,ma,mi:longint;
    a:array[1..4] of 0..9;
procedure max;
var i,j,t:longint;
begin
  for i:=1 to 3 do
    for j:=i to 4 do
      if a[i]<a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
end;
procedure min;
var i,j,t:longint;
begin
  for i:=1 to 3 do
    for j:=i to 4 do
      if a[i]>a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
        end;
end;
begin
  readln(n);
  a[1]:=n div 1000;
  a[2]:=(n mod 1000) div 100;
  a[3]:=(n mod 100) div 10;
  a[4]:=n mod 10;
  k:=0;
  repeat
    k:=k+1;
    max;
    ma:=a[1]*1000+a[2]*100+a[3]*10+a[4];
    min;
    mi:=a[1]*1000+a[2]*100+a[3]*10+a[4];
    n:=ma-mi;
    a[1]:=n div 1000;
    a[2]:=(n mod 1000) div 100;
    a[3]:=(n mod 100) div 10;
    a[4]:=n mod 10;
  until n=6174;
  writeln(k);
end.