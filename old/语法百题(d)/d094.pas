program d094;
var n,i,j,k,m,pp:integer;
    p:array[0..101] of 0..1;
begin
  readln(n);
  if n=1 then writeln('1') else begin
  fillchar(p,sizeof(p),0);
  j:=n;
  pp:=0;
  while (j<>2) do begin
    k:=0;i:=0;
    repeat
      i:=i+1;
      if p[i]=0 then
        begin
          k:=k+1;
          if k=3 then
            begin
              p[i]:=1;
              j:=j-1;
              k:=0;
            end;
        end;
    until i=n;
    if j=2 then pp:=1;
    i:=n+1;k:=0;
    repeat
      i:=i-1;
      if p[i]=0 then
        begin
          k:=k+1;
          if k=3 then
            begin
              k:=0;
              j:=j-1;
              p[i]:=1;
            end;
        end;
    until i=1;
  end;
  if pp=1 then
    begin
      for i:=1 to n do if p[i]=0 then m:=i;
    end else for i:=n downto 1 do if p[i]=0 then m:=i;
  writeln(m);end;
end.