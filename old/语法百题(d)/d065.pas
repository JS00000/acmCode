program d065;
var i,k,a,b,c:integer;
begin
  readln(a,b,c);
  k:=0;i:=0;
  repeat
    i:=i+1;
    if (i mod a=1) and (i mod b=1) and (i mod c=1) then
      begin
        writeln(i);
        k:=k+1;
      end;
  until k=10;
end.