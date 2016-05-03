program gjdjf;
type atype=array[0..102] of 0..20;
var st1,st2:string;l1,l2,l,i:integer;
    a,b,c:atype;
procedure hplus(a,b:atype;m:integer);
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
begin
  readln(st1);
  readln(st2);
  l1:=length(st1);
  l2:=length(st2);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=l1 downto 1 do a[i]:=ord(st1[l1-i+1])-48;
  for i:=l2 downto 1 do b[i]:=ord(st2[l2-i+1])-48;
  if l1>l2 then hplus(a,b,l1) else hplus(b,a,l2);
  for i:=l downto 1 do write(c[i]);writeln;
end.
