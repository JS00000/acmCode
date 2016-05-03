program e532;
const dx:array[1..8] of integer=(0,1,1,1,0,-1,-1,-1);
      dy:array[1..8] of integer=(1,1,0,-1,-1,-1,0,1);
var i,r,f,x,y,x1,x0,y1,y0,n,m,j:longint;
    ax,ay,ap,astep:array[0..10000] of longint;
    t:boolean;
    map:array[0..1001,0..1001] of integer;
procedure print(r:integer);
  begin
    if r=1 then writeln(ax[r],' ',ay[r]) else
      begin
        print(ap[r]);
        writeln(ax[r],' ',ay[r]);
      end;
  end;
begin
  assign(input,'e532.in');
  reset(input);
  assign(output,'e532.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do read(map[i,j]);
      readln;
    end;
  readln(x0,y0);
  readln(x1,y1);
  for i:=0 to m+1 do
    begin
      map[0,i]:=1;
      map[n+1,i]:=1;
    end;
  for i:=0 to n+1 do
    begin
      map[i,0]:=1;
      map[i,m+1]:=1;
    end;
  if (map[x0,y0]=1) or (map[x1,y1]=1) then
    begin
      writeln('No!');
      halt;
    end;
  x:=x0;y:=y0;ax[1]:=x0;ay[1]:=y0;
  r:=1;f:=0;r:=1;t:=true;
  while (f<=r) and t do
    begin
      f:=f+1;
      for i:=1 to 8 do
        begin
          x:=ax[f]+dx[i];
          y:=ay[f]+dy[i];
          if map[x,y]=0 then
            begin
              r:=r+1;
              ax[r]:=x;
              ay[r]:=y;
              ap[r]:=f;
              astep[r]:=astep[f]+1;
              map[x,y]:=1;
            end;
          if (x=x1) and (y=y1) then
            begin
              print(r);
              t:=false;
            end;
        end;
    end;
  if t then writeln('No000');
  close(input);
  close(output);
end.