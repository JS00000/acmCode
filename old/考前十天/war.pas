program war;
type
  atype=record
    x,y,z:longint;
  end;
var
  a:array[0..50001] of atype;
  i,k,fx,fy,n,m:longint;
  tot:int64;
  fa:array[0..50001] of longint;
procedure init;
begin
  assign(input,'war.in');
  reset(input);
  readln(n,m);
  for i:=1 to n do fa[i]:=i;
  for i:=1 to m do readln(a[i].x,a[i].y,a[i].z);
  close(input);
end;

procedure qsort(l,r: longint);
      var
         i,j,x: longint;
         y:atype;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2].z;
         repeat
           while a[i].z<x do
            inc(i);
           while x<a[j].z do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           qsort(l,j);
         if i<r then
           qsort(i,r);
      end;

function find(x:longint):longint;
begin
  if fa[x]<> x then fa[x]:=find(fa[x]);
  find:=fa[x];
end;

procedure union(x,y:longint);
var sx,sy:longint;
begin
  sx:=find(x);
  sy:=find(y);
  fa[sx]:=sy;
end;

procedure kruskal;
begin
  i:=0;tot:=0;k:=0;
  while k<n-1 do
    begin
      i:=i+1;
      fx:=find(a[i].x);
      fy:=find(a[i].y);
      if fx<>fy then
        begin
          union(a[i].x,a[i].y);
          tot:=tot+a[i].z;
          k:=k+1;
        end;
    end;
end;




begin
  assign(output,'war.out');
  rewrite(output);
  init;
  qsort(1,m);
  kruskal;
  writeln(tot);
  close(output);
end.