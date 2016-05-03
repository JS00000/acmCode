program d095;
var c:char;x1,x2,x3,n:integer;
begin
  x1:=0;x2:=0;x3:=0;
  repeat
    read(c);
    n:=ord(c);
    if ((n>=65) and (n<=90)) or ((n>=97) and (n<=122)) then x1:=x1+1 else
      if (n>=48) and (n<=57) then x2:=x2+1 else x3:=x3+1;
  until c='?';
  x3:=x3-1;
  writeln(x1);
  writeln(x2);
  writeln(x3);
end.