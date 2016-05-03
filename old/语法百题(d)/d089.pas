program d089;
var i,k:integer;
    st:string;q:char;

begin
  readln(st);
  i:=0;k:=1;
  q:=st[1];
  repeat
    i:=i+1;
    if (st[i]=' ') and (q<>' ') then k:=k+1;
    q:=st[i];
  until st[i]='.';
  writeln(k);
end.