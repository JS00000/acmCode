program element;
type
  atype=record
    data,kk:longint;
  end;
var x,y,b:array[0..400002] of longint;
    a:array[0..400002] of atype;
    ty:atype;
    i,n,j,k,len:longint;
function get():atype;
var fa,son:longint;
    t:atype;
begin
  get:=a[1];
  a[1]:=a[len];
  len:=len-1;
  fa:=1;
  son:=2;
  while son<=len do
    begin
      if (a[son+1].data<a[son].data) and (son+1<=len) then son:=son+1;
      if a[fa].data>a[son].data then
        begin
          t:=a[fa];
          a[fa]:=a[son];
          a[son]:=t;
          fa:=son;
          son:=son*2;
        end else son:=len+1;
    end;
end;



procedure put(x,pk:longint);
var son,fa:longint;
    t:atype;
begin
  len:=len+1;
  a[len].data:=x;
  a[len].kk:=pk;
  son:=len;
  fa:=son div 2;
  while (a[fa].data>a[son].data) do
    begin
      t:=a[fa];
      a[fa]:=a[son];
      a[son]:=t;
      son:=fa;
      fa:=son div 2;
    end;
end;



begin
  assign(input,'element.in');
  reset(input);
  assign(output,'element.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(x[i]);
  readln;
  for i:=1 to n do read(y[i]);
  len:=0;a[0].data:=0;



  for i:=1 to n do b[i]:=1;
  for i:=1 to n do put(x[i]+y[1],i);
  for i:=1 to n do
    begin
      ty:=get();
      writeln(ty.data);
      b[ty.kk]:=b[ty.kk]+1;
      put(x[ty.kk]+y[b[ty.kk]],ty.kk);
    end;

  close(input);
  close(output);
end.
