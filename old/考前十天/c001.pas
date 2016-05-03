program c001;
var i,t1,t2,max,min:integer;
    a,b,c:array[-10000..10000] of integer;
    p:boolean;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
  max:=-maxint;min:=maxint;
  repeat
    read(t1,t2);
    a[t2]:=a[t2]+t1;
    if t2>max then max:=t2;
    if t2<min then min:=t2;
  until eoln;
  readln;
  repeat
    read(t1,t2);
    b[t2]:=b[t2]+t1;
    if t2>max then max:=t2;
    if t2<min then min:=t2;
  until eoln;
  p:=true;
  for i:=max downto min do
    begin
      c[i]:=a[i]+b[i];
      if c[i]<>0 then p:=false;
    end;
  if p then writeln('0') else
    begin
      for i:=max downto min+1 do
        if c[i]<>0 then write(c[i],' ',i,' ');
      if c[min]<>0 then write(c[min],' ',min);
    end;
  end.

