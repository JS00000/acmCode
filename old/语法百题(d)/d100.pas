program d100;
var y,m,s,w,i,c,b:longint;p:boolean;
    d:array[1..12] of 28..31;
begin
  readln(y,m);
  s:=y+trunc((y-1)/4)-trunc((y-1)/100)+trunc((y-1)/400);
  w:=s mod 7;
  p:=false;
  if (y mod 4=0) and (y mod 100<>0) or (y mod 400=0) then p:=true;
  if p then d[2]:=29 else d[2]:=28;
  for i:=1 to 12 do
    case i of
      1,3,5,7,8,10,12:d[i]:=31;
      4,6,9,11:d[i]:=30;
    end;
  b:=0;
  for i:=1 to m-1 do b:=b+d[i];
  b:=b mod 7;
  w:=(w+b) mod 7;
  writeln(' Sun Mon Tue Wed Thu Fri Sat');
  for i:=1 to w*4 do write(' ');
  c:=0;
  repeat
    c:=c+1;
    write(c:4);
    w:=w+1;
    if w=7 then
      begin
        w:=0;
        writeln;
      end;
  until c=d[m];

end.