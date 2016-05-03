program m003;
const maxn=2001;
      mi=1000;
type atype=array[0..mi] of integer;
var i,j,n,k,l1,l2:integer;
    gc:array[0..mi,0..mi] of 0..101;
    t,s:atype;
    yinb:array[0..maxn] of integer;

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
  readln(n);
  fillchar(yinb,sizeof(yinb),0);
  yinb[2]:=n-2;
  for i:=4 to n do
    begin
      k:=i*2-5;
      j:=2;
      repeat
        if k mod j=0 then
          begin
            k:=k div j;
            yinb[j]:=yinb[j]+1;
          end else j:=j+1;
      until k=1;
    end;
  for i:=2 to n-1 do
    begin
      k:=i;
      j:=2;
      repeat
        if k mod j=0 then
          begin
            k:=k div j;
            yinb[j]:=yinb[j]-1;
          end else j:=j+1;
      until k=1;
    end;
  fillchar(s,sizeof(s),0);
  s[1]:=1;l1:=1;
  for i:=2 to n*2-5 do
    if yinb[i]>0 then
      begin
        if i<10 then
          begin
            t[1]:=i;
            l2:=1;
          end
        else if i<100 then
          begin
            t[1]:=i mod 10;t[2]:=i div 10;
            l2:=2;
          end
        else if i<1000 then
          begin
            t[1]:=i mod 10;t[2]:=(i mod 100) div 10;t[3]:=i div 100;
            l2:=3;
          end
        else if i<10000 then
          begin
            t[1]:=i mod 10;t[2]:=(i mod 100) div 10;
            t[3]:=(i mod 1000) div 100;t[4]:=i div 1000;
            l2:=4;
          end;
        for j:=1 to yinb[i] do hcf(s,t,l1,l2,s,l1);
      end;


  for i:=l1 downto 1 do write(s[i]);writeln;
end.











