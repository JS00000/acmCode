program d118;
var i,j,k,a1,a2,a3,a4,a5,sub1,sub2,sub3,n:longint;
begin
  readln(k);
  sub1:=k;
  n:=0;
  repeat
    if (sub1>=100) and (sub1<300) then
      begin
        a1:=sub1 div 100;
        a2:=(sub1 mod 100) div 10;
        a3:=sub1 mod 10;
        sub2:=a2*100+a3*10;
        for i:=0 to 9 do
          if (sub2+i) mod k=0 then
            begin
              a4:=i;
              sub3:=a3*100+a4*10;
              for j:=0 to 9 do
                if (sub3+j) mod k=0 then
                  begin
                    a5:=j;
                    writeln(a1,a2,a3,a4,a5);
                    n:=n+1;
                  end;
            end;
      end;
    sub1:=sub1+k;
  until sub1>=300;
  if 300 mod k=0 then begin writeln('30000');n:=n+1;end;
  if n=0 then writeln('No');
end.