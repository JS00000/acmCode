program d062;
var n,i,j,k,b:integer;p:boolean;
    a:array[0..100] of integer;
function pd():boolean;
var i:integer;
begin
  pd:=true;
  for i:=2 to trunc(sqrt(b)) do if b mod i=0 then pd:=false;
end;
begin
  readln(n);
  b:=n;k:=0;
  repeat
    i:=2;
    p:=true;
    while (i<=b div 2) and p do
        if b mod i=0 then
          begin
            k:=k+1;
            a[k]:=i;
            p:=false;
            b:=b div i;
          end else i:=i+1;
  until pd;
  a[k+1]:=b;
  for i:=1 to k do write(a[i],'*');
  writeln(a[k+1]);
end.