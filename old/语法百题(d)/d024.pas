program d024;
var n,m,a,b,c,i:longint;p:boolean;
begin
  read(n,m);
  if n<m then begin b:=m;a:=n;end else begin b:=n;a:=m; end;
  i:=1; p:=false;c:=b;
  repeat
    b:=c*i;
    if b mod a=0 then begin writeln(b);p:=true;end;
    i:=i+1;
  until p;
end.