program d103;
var i,a:integer;
begin
  i:=0;
 repeat
   read(a);
   if a mod 2=0 then i:=i+1;
 until a=-1;
 writeln(i);
end.