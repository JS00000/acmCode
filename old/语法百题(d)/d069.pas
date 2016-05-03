program d069;
var c:char;l,i,j,k:integer;
begin
  read(c);
  l:=ord(c)-64;
  k:=64;
  for i:=1 to l do
    begin
      k:=k+1;
      c:=chr(k);
      for j:=1 to l-i do write(' ');
      for j:=1 to i*2-1 do write(c);
      writeln;
    end;
  for i:=1 to l-1 do
    begin
      k:=k-1;
      c:=chr(k);
      for j:=1 to i do write(' ');
      for j:=1 to l*2-i*2-1 do write(c);
      writeln;
    end;
end.