program m001;
var i,m,n,x,y,c,d:integer;
function max(a,b:integer):integer;
begin
  if a>b then max:=a else max:=b;
end;
function min(a,b:integer):integer;
begin
  if a<b then min:=a else min:=b;
end;
begin
  readln(x,y);
  n:=x;m:=y;
  repeat
    d:=min(x,y);
    c:=max(x,y)-min(x,y);
    x:=d;
    y:=c;
  until c=d;
  for i:=1 to m+n do if i mod x=0 then write(i,' ');
end.