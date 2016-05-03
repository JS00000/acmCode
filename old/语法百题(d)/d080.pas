program d080;
var i,j,k,b,n,nn:integer;p:boolean;
    a,c:array[0..101] of integer;
begin
  i:=0;
  while not(eoln) do
    begin
      i:=i+1;
      read(a[i]);
    end;
  n:=i;
  i:=0;
  readln;
  while not(eoln) do
    begin
      i:=i+1;
      read(c[i]);
    end;
  nn:=i;
  for k:=1 to nn do
    begin
      p:=true;
      for i:=1 to n do if c[k]=a[i] then p:=false;
      if p then
        begin
          i:=0;
          repeat
            i:=i+1;
          until (a[i]>c[k]) or (i=n+1);
          if i=n+1 then
            begin
              n:=n+1;
              a[n]:=c[k];
            end else
            begin
              b:=i;
              for j:=n+1 downto i+1 do a[j]:=a[j-1];
              a[i]:=c[k];
              n:=n+1;
            end;
        end;
    end;
  for i:=1 to n do write(a[i],' ');
end.
