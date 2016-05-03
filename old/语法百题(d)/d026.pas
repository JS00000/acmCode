program d026;
var i,n,a,b,s:longint;
begin
  b:=0;s:=0;
  repeat
    read(a);
    if a>b then b:=a;
    s:=s+1;
  until eoln;
  writeln(s,' ',b);
end.
