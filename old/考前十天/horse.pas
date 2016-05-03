program horse;
const
  dx:array[1..8] of integer=(1,2,2,1,-1,-2,-2,-1);
  dy:array[1..8] of integer=(-2,-1,1,2,2,1,-1,-2);
var
  map:array[-2..102,-2..102] of integer;
  n,x,y:integer;
  sx,sy:array[0..10001] of integer;
procedure init;
var i:integer;
begin
  readln(n);
  readln(sx[1],sy[1]);
  fillchar(map,sizeof(map),0);
  for i:=-1 to n+2 do
    begin
      map[-1,i]:=-1;
      map[0,i]:=-1;
      map[n+1,i]:=-1;
      map[n+2,i]:=-1;
      map[i,-1]:=-1;
      map[i,0]:=-1;
      map[i,n+1]:=-1;
      map[i,n+2]:=-1;
  end;
end;
procedure print;
var i,j:integer;
begin
  for i:=1 to n do
    begin
      for j:=1 to n do write(map[i,j]:3);
      writeln;
    end;
  halt;
end;
procedure try(i:integer);
var j,x,y:integer;
begin
    for j:=1 to 8 do
      begin
        x:=sx[i-1]+dx[j];
        y:=sy[i-1]+dy[j];
        if map[x,y]=0 then
          begin
            sx[i]:=x;
            sy[i]:=y;
            map[x,y]:=i;
            if i=n*n then print else try(i+1);
            map[x,y]:=0;
          end;
      end;
end;
begin
  init;
  map[sx[1],sy[1]]:=1;
  try(2);
end.
