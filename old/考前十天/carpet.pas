program carpet;
type atype=array[0..10000] of longint;
var i,n,nn,mx,my:longint;
    zx,zy,lx,ly:atype;

begin
  assign(input,'carpet.in');
  reset(input);
  assign(output,'carpet.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    readln(zx[i],zy[i],lx[i],ly[i]);
  readln(mx,my);
  nn:=-1;
  for i:=1 to n do
    if (mx>=zx[i]) and  (mx<=zx[i]+lx[i])
      and (my>=zy[i]) and  (my<=zy[i]+ly[i]) then nn:=i;
  writeln(nn);
  close(input);
  close(output);
end.