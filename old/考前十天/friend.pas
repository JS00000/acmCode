program friend;
var
  fa,h,num:array[0..30000] of longint;
  n,m,c,d,max,i:longint;
function find(x:longint):longint;
begin
  if x<>fa[x] then fa[x]:=find(fa[x]);
  find:=fa[x];
end;

procedure union(x,y:longint);
var u,v:longint;
begin
  u:=find(x);
  v:=find(y);
  if v<>u then
  if h[u]<h[v] then
    begin
      fa[u]:=v;
      num[v]:=num[v]+num[u];
    end
  else
    begin
      fa[v]:=u;
      num[u]:=num[u]+num[v];
      if h[u]=h[v] then h[u]:=h[u]+1;
    end;
end;

begin
  assign(input,'friend.in');
  reset(input);
  assign(output,'friend.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      fa[i]:=i;
      h[i]:=0;
      num[i]:=1;
    end;
  for i:=1 to m do
    begin
      readln(c,d);
      union(c,d);
    end;
  max:=0;
  for i:=1 to n do if num[i]>max then max:=num[i];
  writeln(max);
  close(input);
  close(output);
end.