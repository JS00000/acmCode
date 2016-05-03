program relation;
var
  fa,h:array[0..20001] of longint;
  i,n,m,q,c,d:longint;
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
  if h[u]<h[v] then fa[u]:=v
  else
    begin
      fa[v]:=u;
      if h[u]=h[v] then h[u]:=h[u]+1;
    end;
end;


begin
  assign(input,'relation.in');
  reset(input);
  assign(output,'relation.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      fa[i]:=i;
      h[i]:=0;
    end;
  for i:=1 to m do
    begin
      readln(c,d);
      union(c,d);
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(c,d);
      if find(c)=find(d) then writeln('Yes') else writeln('No');
    end;
  close(input);
  close(output);
end.