program d025;
var i,n,a,b:longint;
begin
  readln(n);
  b:=0;
  for i:=1 to n do
    begin
      read(a);
      if a>b then b:=a;
    end;
  writeln(b);
end.