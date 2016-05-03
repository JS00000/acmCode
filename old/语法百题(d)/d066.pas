program d066;
var st:string;k,i,l:integer;
begin
  read(st);
  l:=length(st);
  k:=0;
  for i:=1 to l do
    if st[i]<>' ' then
      begin
        k:=k+1;
        write(st[i]);
      end;
  writeln;
  writeln(k);
end.
