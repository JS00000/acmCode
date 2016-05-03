program d097;
var n,m,i,j,k:integer;
    p:array[0..10001] of 0..1;
begin
 readln(n,m);
 i:=0;k:=0;j:=n;
 repeat
   i:=i+1;
   if p[i]=0 then
     begin
       k:=k+1;
       if k=m then begin p[i]:=1;k:=0;j:=j-1;end;
     end;
   if i=n then i:=0;
 until j=1;
 for i:=1 to n do if p[i]=0 then writeln(i);

end.