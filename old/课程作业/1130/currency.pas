program currency;
var i,j,k,w,n,nn:integer;
    a:array[0..3,0..9] of 0..1;
    p:array[0..1001] of boolean;

begin
  assign(input,'currency.in');
  reset(input);
  assign(output,'currency.out');
  rewrite(output);
  readln(n);
  nn:=n;
  if n=1000 then write('500') else
    begin
      if n<10 then w:=1 else
        if n<100 then w:=2 else w:=3;
      for i:=1 to 3 do
        for j:=1 to 9 do a[i,j]:=0;
      a[1,0]:=1;
      a[2,0]:=1;
      a[3,0]:=1;
      for i:=1 to w do
        begin
          case n mod 10 of
            1:a[i,1]:=1;
            2:a[i,2]:=1;
            3:begin a[i,1]:=1;a[i,2]:=1;a[i,3]:=1;end;
            4:begin a[i,2]:=1;a[i,4]:=1;end;
            5:a[i,5]:=1;
            6:a[i,6]:=1;
            7:begin a[i,2]:=1;a[i,5]:=1;a[i,7]:=1;end;
            8:begin a[i,2]:=1;a[i,6]:=1;a[i,8]:=1;end;
            9:begin a[i,2]:=1;a[i,4]:=1;a[i,5]:=1;a[i,7]:=1;a[i,9]:=1;end;
          end;
          n:=n div 10;
        end;
      for i:=1 to 1000 do p[i]:=false;
      for i:=1 to 9 do if a[1,i]=1 then p[i]:=true;
      if w>=2 then for i:=10 to 99 do if (a[1,i mod 10]=1) and (a[2,i div 10]=1) then p[i]:=true;
      if w=3 then for i:=100 to 999 do
        if (a[1,i mod 10]=1) and (a[2,(i div 10) mod 10]=1) and (a[3,i div 100]=1) then p[i]:=true;
      k:=0;
      for i:=1 to nn do if p[i] then
        begin
          k:=k+1;
          write(i:5);
          if k=5 then
            begin
              writeln;
              k:=0;
            end;
        end;


    end;
  close(input);
  close(output);
end.