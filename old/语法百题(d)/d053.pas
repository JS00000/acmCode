program d053;
var st:string;i,j,l:integer;s,a:int64;
    b:array[0..1000] of 0..15;
begin
  readln(st);
  l:=length(st);
  for i:=1 to l do
    case st[i] of
      '0':b[i]:=0;
      '1':b[i]:=1;
      '2':b[i]:=2;
      '3':b[i]:=3;
      '4':b[i]:=4;
      '5':b[i]:=5;
      '6':b[i]:=6;
      '7':b[i]:=7;
      '8':b[i]:=8;
      '9':b[i]:=9;
      'a','A':b[i]:=10;
      'b','B':b[i]:=11;
      'c','C':b[i]:=12;
      'd','D':b[i]:=13;
      'e','E':b[i]:=14;
      'f','F':b[i]:=15;
    end;


  s:=0;
  for i:=1 to l do
    begin
      a:=1;
      for j:=1 to l-i do a:=a*16;
      s:=s+b[i]*a;
    end;
  writeln(s);
end.