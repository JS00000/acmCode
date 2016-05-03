program d086;
var n,j,i,k:integer;
    a:array[0..12,0..12] of integer;
    p:array[0..12,0..12] of 0..1;
begin
    fillchar(p,sizeof(p),0);
    readln(n);
    i:=1;j:=(n+1) div 2;
    a[i,j]:=1;
    p[i,j]:=1;
    k:=1;
    repeat
      if p[i-1,j-1]=1 then i:=i+1 else
        if (i-1=0) and (j-1=0) then begin i:=2;j:=1; end else
          if i-1=0 then begin i:=n;j:=j-1;end else
            if j-1=0 then begin i:=i-1;j:=n;end else begin i:=i-1;j:=j-1;end;
      k:=k+1;
      a[i,j]:=k;
      p[i,j]:=1;
    until k=n*n;
    for i:=1 to n do
      begin
        for j:=1 to n do write(a[i,j],' ');
        writeln;
      end;
end.