program d110;
var map:array[0..5,0..5] of 0..1;
    color:array[0..5] of 0..5;
    a,b,i,s,m:longint;
procedure dg(n:integer);
var i,j:integer;p:boolean;
begin
  if n=6 then s:=s+1 else
    for i:=1 to 4 do
      begin
        p:=true;
        for j:=1 to 5 do
          if (map[n,j]=1) and (color[j]=i) then p:=false;
        if p then
          begin
            color[n]:=i;
            dg(n+1);
            color[n]:=0;
          end;
      end;
end;
begin
  readln(m);
  fillchar(map,sizeof(map),0);
  fillchar(color,sizeof(color),0);
  for i:=1 to m do
    begin
      readln(a,b);
      map[a,b]:=1;
      map[b,a]:=1;
    end;
  s:=0;
  dg(1);
  writeln(s);
end.