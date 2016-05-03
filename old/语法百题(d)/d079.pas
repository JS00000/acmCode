program d079;
var c,tt:char;i,j,t:integer;
    a:array[1..4] of integer;
    b:array[1..4] of char;
begin
  repeat
    read(c);
    case c of
      'A','a':a[1]:=a[1]+1;
      'B','b':a[2]:=a[2]+1;
      'C','c':a[3]:=a[3]+1;
      'D','d':a[4]:=a[4]+1;
    end;
  until c='#';
  b[1]:='A';
  b[2]:='B';
  b[3]:='C';
  b[4]:='D';
  for i:=1 to 3 do
    for j:=i to 4 do
      if a[i]<a[j] then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          tt:=b[i];
          b[i]:=b[j];
          b[j]:=tt;
        end;
  for i:=1 to 3 do
    for j:=i to 4 do
      if (a[i]=a[j]) and (ord(b[i])>ord(b[j])) then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          tt:=b[i];
          b[i]:=b[j];
          b[j]:=tt;
        end;
  for i:=1 to 4 do writeln(b[i],' : ',a[i]);
end.