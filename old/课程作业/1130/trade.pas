program trade;
type atype=array[0..101] of integer;
var
  ans,xx,ax:atype;
  a:array[0..100001] of 0..101;
  x,n,a0,i:longint;
function cheng(c:atype;d:integer):atype;
var i,j:integer;
begin
  for i:=1 to 100 do cheng[i]:=0;
  if d=10 then
    begin
      for i:=100 downto 2 do cheng[i]:=c[i-1];
      cheng[1]:=0;
    end else
      for i:=1 to 100 do
        begin
          cheng[i]:=cheng[i]+c[i]*d;
          if cheng[i]>=10 then
            begin
              cheng[i+1]:=cheng[i] div 10;
              cheng[i]:=cheng[i] mod 10;
            end;
        end;
end;
function cheng2(c:atype;d:integer):atype;
var i,j,d1,d2:integer;
begin
  if d=100 then for i:=100 downto 3 do
    begin
      cheng2[i]:=c[i-2];
      cheng2[2]:=0;
      cheng2[1]:=0;
    end else begin
  for i:=1 to 100 do cheng2[i]:=0;
  d1:=d mod 10;
  d2:=d div 10;
      for i:=1 to 100 do
        begin
          cheng2[i]:=cheng2[i]+c[i]*d1;
          if cheng2[i]>=10 then
            begin
              cheng2[i+1]:=cheng2[i] div 10;
              cheng2[i]:=cheng2[i] mod 10;
            end;
        end;
      for i:=1 to 100 do
        begin
          cheng2[i+1]:=cheng2[i+1]+c[i]*d2;
          if cheng2[i+1]>=10 then
            begin
              cheng2[i+2]:=cheng2[i+1] div 10;
              cheng2[i+1]:=cheng2[i+1] mod 10;
            end;
        end; end;

end;
function plu(c,d:atype):atype;
var i:integer;
begin
  for i:=1 to 100 do plu[i]:=0;
  for i:=1 to 100 do
    begin
      plu[i]:=plu[i]+c[i]+d[i];
      if plu[i]>=10 then
        begin
          plu[i+1]:=plu[i] div 10;
          plu[i]:=plu[i] mod 10;
        end;
    end;
end;
begin
  assign(input,'trade.in');
  reset(input);
  assign(output,'trade.out');
  rewrite(output);
  readln(x,n);
  readln(a0);
  for i:=1 to n do readln(a[i]);
  for i:=1 to 100 do ans[i]:=0;
  xx:=ans;
  xx[1]:=1;
  ans[3]:=a0 div 100;
  ans[2]:=(a0 div 10) mod 10;
  ans[1]:=a0 mod 10;
  for i:=1 to n do
    begin
      xx:=cheng(xx,x);
      if a[i]>10 then ax:=cheng2(xx,a[i]) else ax:=cheng(xx,a[i]);
      ans:=plu(ans,ax);
    end;
  for i:=100 downto 1 do write(ans[i]);
  close(input);
  close(output);
end.