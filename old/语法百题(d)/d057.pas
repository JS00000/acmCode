program d057;
var s,a:real;i,j,n:integer;
begin
  readln(n);
  s:=1;
  for i:=1 to n do
    begin
      a:=1;
      for j:=1 to i do a:=a/j;
      s:=s+a;
    end;
  writeln(s:0:10);
end.