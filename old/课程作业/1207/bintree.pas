program bintree;
const maximum=100000;
var
  a:array[0..1000] of longint;
  p:array[-maximum..maximum] of boolean;
  i,t,b,q,h:longint;

procedure pre(i:integer);
begin
  if i>t then exit;
  write(a[i],' ');
  pre(i*2);
  pre(i*2+1);
end;

procedure mid(i:integer);
begin
  if i>t then exit;
  mid(i*2);
  write(a[i],' ');
  mid(i*2+1);
end;

procedure bac(i:integer);
begin
  if i>t then exit;
  bac(i*2);
  bac(i*2+1);
  write(a[i],' ');
end;

begin
  assign(input,'bintree.in');
  reset(input);
  assign(output,'bintree.out');
  rewrite(output);
  readln(h,q);
  t:=1;
  for i:=1 to h do t:=t*2;
  t:=t-1;
  for i:=1 to maximum do p[i]:=true;
  i:=0;
  repeat
    read(b);
    if p[b] then
      begin
        p[b]:=false;
        i:=i+1;
        a[i]:=b;
      end;
  until i=t;
  if q=1 then pre(1);
  if q=2 then mid(1);
  if q=3 then bac(1);
  close(input);
  close(output);
end.