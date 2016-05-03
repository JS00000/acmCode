program d048;
var s,a:int64;
begin
  read(a);
  while a<>0 do
    begin
      if a<0 then s:=s+a;
      read(a);
    end;
  writeln(s);
end.