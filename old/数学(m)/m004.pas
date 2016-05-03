program m004;
type atype=array[0..300] of integer;
var n,x,y,m,i,j,ll,lr,lx,ly:integer;
    tx,ty,tl,tr:atype;
    a:array[0..101,0..101] of atype;
    gc:array[0..300,0..300] of 0..101;
    l:array[0..101,0..101] of integer;
procedure hplus(a,b:atype;m:integer;var c:atype;var l:integer);
var i,j:integer;
begin
  fillchar(c,sizeof(c),0);
  for i:=m downto 1 do c[i]:=a[i]+b[i];
  for i:=1 to m do if c[i]>=10 then
    begin
      c[i]:=c[i]-10;
      c[i+1]:=c[i+1]+1;
    end;
  if c[m+1]=1 then l:=m+1 else l:=m;
end;
procedure hcf(a,b:atype;l1,l2:integer;var c:atype;var l:integer);
  var i,j:integer;
  begin
    fillchar(gc,sizeof(gc),0);
    fillchar(c,sizeof(c),0);
    for i:=1 to l1 do
      for j:=1 to l2 do gc[i,i+j-1]:=a[i]*b[j];
    for j:=1 to l1+l2 do
      for i:=1 to l1 do c[j]:=c[j]+gc[i,j];
    for j:=1 to l1+l2 do
      if c[j]>=10 then
        begin
          c[j+1]:=c[j+1]+c[j] div 10;
          c[j]:=c[j] mod 10;
        end;
    if c[l1+l2]<>0 then l:=l1+l2 else l:=l1+l2-1;
  end;
begin
  readln(n,x,y,m);
        if x<10 then
          begin
            tx[1]:=x;
            lx:=1;
          end
        else if x<100 then
          begin
            tx[1]:=x mod 10;tx[2]:=x div 10;
            lx:=2;
          end
        else if x<1000 then
          begin
            tx[1]:=x mod 10;tx[2]:=(x mod 100) div 10;tx[3]:=x div 100;
            lx:=3;
          end;
        if y<10 then
          begin
            ty[1]:=y;
            ly:=1;
          end
        else if y<100 then
          begin
            ty[1]:=y mod 10;ty[2]:=y div 10;
            ly:=2;
          end
        else if y<1000 then
          begin
            ty[1]:=y mod 10;ty[2]:=(y mod 100) div 10;ty[3]:=y div 100;
            ly:=3;
          end;
  a[1,1][1]:=1;l[1,1]:=1;
  for i:=2 to n+2-m do
    hcf(a[i-1,1],tx,l[i-1,1],lx,a[i,1],l[i,1]);
  for i:=2 to m do
    hcf(a[i-1,i-1],ty,l[i-1,i-1],ly,a[i,i],l[i,i]);
  for i:=3 to n+1 do
    for j:=2 to m do if i-j<n-m+2 then
      begin
        hcf(a[i-1,j-1],ty,l[i-1,j-1],ly,tl,ll);
        hcf(a[i-1,j],tx,l[i-1,j],lx,tr,lr);
        if ll>lr then hplus(tl,tr,ll,a[i,j],l[i,j])
                 else hplus(tr,tl,lr,a[i,j],l[i,j]);
      end;
  for i:=l[n+1,m] downto 1 do write(a[n+1,m][i]);writeln;
end.
