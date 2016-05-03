program d077;
var n,i,k,b:longint;p:boolean;
    a:array[0..100] of 0..1;
begin
  readln(n);p:=true;
  repeat
    i:=0;b:=1;
    while b*2<=n do
      begin
        i:=i+1;
        b:=b*2;
      end;
    a[i]:=1;
    if p then begin k:=i;p:=false;end;
    n:=n-b;
  until n=0;
  for i:=k downto 0 do write(a[i]);
end.