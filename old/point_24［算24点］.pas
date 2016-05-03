program point_24;
uses dos;
type
  atype=record
    data:real;
    ch:char;
  end;
var
  i,j,k,l,m,o,q,x,y,z,num:longint;
  c:array[0..10] of atype;
  p:array[0..10] of boolean;
  n:array[0..10] of real;
  fh:array[0..10] of char;
  nn:array[0..10] of longint;

function ans():real;
var i,j:longint;
    a:array[0..10] of real;
begin
  j:=0;
  for i:=1 to 7 do
    begin
      if p[i] then
        begin
          j:=j+1;
          a[j]:=c[i].data;
        end;
      if not(p[i]) then
        begin
          if j<2 then exit(0);
          case c[i].ch of
            '+':a[j-1]:=a[j-1]+a[j];
            '-':a[j-1]:=a[j-1]-a[j];
            '*':a[j-1]:=a[j-1]*a[j];
            '/':if a[j]=0 then exit(0) else a[j-1]:=a[j-1]/a[j];
          end;
          j:=j-1;
        end;
    end;
  ans:=a[1];
end;

begin
swapvectors;
repeat
  num:=0;
  p[1]:=true;p[2]:=true;p[7]:=false;
  writeln('______MyHair______');
  writeln;
  writeln('Input four number');
  read(n[1],n[2],n[3],n[4]);
  writeln;
  writeln;
  fh[5]:='+';fh[6]:='-';fh[7]:='*';fh[8]:='/';
  for i:=1 to 4 do
    for j:=1 to 4 do
      for k:=1 to 8 do
        for l:=1 to 8 do
          for m:=1 to 8 do
            for o:=1 to 8 do
              for q:=5 to 8 do
                begin
                  c[1].data:=n[i];

                  c[2].data:=n[j];

                  if k<5 then
                    begin
                      c[3].data:=n[k];
                      p[3]:=true;
                    end else
                    begin
                      c[3].ch:=fh[k];
                      p[3]:=false;
                    end;

                  if l<5 then
                    begin
                      c[4].data:=n[l];
                      p[4]:=true;
                    end else
                    begin
                      c[4].ch:=fh[l];
                      p[4]:=false;
                    end;

                  if m<5 then
                    begin
                      c[5].data:=n[m];
                      p[5]:=true;
                    end else
                    begin
                      c[5].ch:=fh[m];
                      p[5]:=false;
                    end;

                  if o<5 then
                    begin
                      c[6].data:=n[o];
                      p[6]:=true;
                    end else
                    begin
                      c[6].ch:=fh[o];
                      p[6]:=false;
                    end;
                  y:=0;
                  for z:=3 to 6 do if p[z] then
                    begin
                      case z of
                        3:x:=k;
                        4:x:=l;
                        5:x:=m;
                        6:x:=o;
                      end;
                      y:=y+1;
                      nn[y]:=x;
                    end;

                  c[7].ch:=fh[q];
                  if (y=2) and (i<>j) and (i<>nn[1]) and (i<>nn[2]) and (j<>nn[1]) and (j<>nn[2]) and (nn[1]<>nn[2]) then
                  begin
                  if (ans()>23.999) and (ans()<24.001) then
                   begin
                    num:=num+1;
                    write(num,':   ');
                    for z:=1 to 7 do
                      if p[z] then write(c[z].data:0:0,' ') else write(c[z].ch,' ');
                    writeln;

                   end;
                  end;
                end;
  writeln;
  writeln('__________________');
  writeln;
  exec('c:\windows\system32\cmd.exe','/c pause');
  for i:=1 to 12 do writeln;

until 1<0;
swapvectors;
end.
