program d063;
var n,m,a,b,i,j,p:integer;
begin
  readln(n);
  a:=n div 10;
  b:=n mod 10;
  m:=b*10+a; p:=0;
  for i:=11 to 99 do
    begin
      a:=i div 10;
      b:=i mod 10;
      if b<>0 then
        begin
          j:=b*10+a;
          if (n+i=m+j) and (n<>j) then begin writeln(i);p:=1;end;
        end;
    end;
  if p=0 then writeln('No!');
end.