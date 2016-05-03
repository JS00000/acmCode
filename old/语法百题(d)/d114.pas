program d114;
var p:array[0..2001] of 0..1;
    i,k,n,l:integer;
    st:string;
begin
  readln(n);
  fillchar(p,sizeof(p),0);
  k:=1;
  repeat
    k:=k+1;
    if p[k]=0 then if k+k<n then
      begin
        i:=k;
        repeat
          i:=i+k;
          p[i]:=1;
        until i+k>n;
      end;
  until k=n div 2;
  if n>=11 then writeln('11');
  for i:=10 to n do
    if p[i]=0 then
      begin
        str(i,st);
        l:=length(st);
        if l=3 then
          if st[1]=st[3] then writeln(i);
        if l=4 then
          if (st[1]=st[4]) and (st[2]=st[3]) then writeln(i);
      end;

end.
