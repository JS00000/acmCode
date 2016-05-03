program gjdcf;
type atype=array[0..300] of integer;
var st1,st2:string;l1,l2,i,l,ll:integer;
    a,b,c,d:atype;
    gc:array[0..300,0..300] of 0..101;
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
  readln(st1);
  readln(st2);
  if (st1='0') or (st2='0') then writeln('0') else begin
  l1:=length(st1);
  l2:=length(st2);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=l1 downto 1 do a[i]:=ord(st1[l1-i+1])-48;
  for i:=l2 downto 1 do b[i]:=ord(st2[l2-i+1])-48;
  hcf(a,b,l1,l2,d,ll);
  for i:=ll downto 1 do write(d[i]);writeln; end;
end.
