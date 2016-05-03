program d023;
var st:string;s,l,i:longint;
begin
  read(st);
  s:=0;
  l:=length(st);
  for i:=1 to l do s:=s+ord(st[i])-48;
  writeln(s);
end.