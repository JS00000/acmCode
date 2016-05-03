program d111;
var i,a,b,c,a0,b0,c0,f1,f2,f3,n:integer;
begin
  readln(a0);
  readln(b0);
  readln(c0);
  readln(n);
  f1:=0;f2:=0;f3:=0;
  for i:=1 to n do
    begin
      readln(a);
      readln(b);
      readln(c);
      if a-a0>f1 then f1:=a-a0;
      if b-b0>f2 then f2:=b-b0;
      if c-c0>f3 then f3:=c-c0;
    end;
  writeln(f1,' ',f2,' ',f3);
end.