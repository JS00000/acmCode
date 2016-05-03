program d116;
var a,b:array[0..51] of 0..1;c,i,j,k,h,max,p,n:integer;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  readln(n);
  for i:=1 to n do
    begin
      read(c);
      if c mod 2=1 then a[c div 2+1]:=1 else b[c div 2]:=1;
    end;
  h:=0;max:=0;p:=1;
  for i:=1 to 50 do
    begin
      if a[i]=0 then
        begin
          if p=0 then
            begin
              h:=h+1;
              if h>max then begin max:=h;k:=(i-h+1)*2-1;end;
            end else
            begin
              p:=0;
              h:=1;
              if h>max then begin max:=h;k:=(i-h+1)*2-1;end;
            end;
        end else
        begin
          p:=1;
          h:=0;
        end;
    end;
  h:=0;p:=1;
  for i:=1 to 50 do
    begin
      if b[i]=0 then
        begin
          if p=0 then
            begin
              h:=h+1;
              if h>max then begin max:=h;k:=(i-h+1)*2;end;
            end else
            begin
              p:=0;
              h:=1;
              if h>max then begin max:=h;k:=(i-h+1)*2;end;
            end;
        end else
        begin
          p:=1;
          h:=0;
        end;
    end;
  writeln(k,' ',max);
end.