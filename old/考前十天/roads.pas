program roads;
var
  n,k,w:integer;
  a,m:array[0..101,1..101] of integer;
procedure init;
var i,s,d,l,t:integer;
begin
  assign(input,'roads.in');
  reset(input);
  readln(n,k,w);
  fillchar(a,sizeof(a),-1);
  fillchar(m,sizeof(m),-1);
  for i:=1 to k do
    begin
      readln(s,d,l,t);
      a[s,d]:=l;
      m[s,d]:=t;
    end;
  for i:=1 to n do p[i]:=true;
  p[1]:=false;
  close(input);
end;
procedure bfs;
begin
  b[1]:=1;ww[1]:=0;
  f:=1;r:=1;
  while f<=r do
    begin
      for i:=2 to n do
        if a[b[f],i]>0 then
          if (ww[b[f]+m[b[f],i]<w then
           begin
            if p[i] then
              begin
                r:=r+1;
                b[r]:=i;
                ww[i]:=ww[b[f]]+m[b[f],i];
              end;
            if (not(p[i])) and  then



           end;
          end;
    end;
end;

begin
  init;
  bfs;
end.