program d078;
const n=20;
var i,k,h,s:integer;
    a:array[0..20] of integer;
begin
  for i:=1 to n do read(a[i]);
  a[0]:=a[n];
  s:=0;
  for i:=1 to n do
    begin
      h:=a[i]+a[(i+1) mod n]+a[(i+2) mod n]+a[(i+3) mod n];
      if h>s then begin s:=h;k:=i;end;
    end;
  writeln(k,' ',s);

end.