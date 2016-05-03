program ugly;
var
  a:array[0..100000] of int64;
  i,j,ans,len,n:int64;
function get():int64;
var fa,son,t:int64;
begin
  get:=a[1];
  a[1]:=a[len];
  len:=len-1;
  fa:=1;son:=fa*2;
  while son<=len do
    begin
      if (a[son]>a[son+1]) and (son+1<=len) then son:=son+1;
      if a[fa]>a[son] then
        begin
          t:=a[fa];
          a[fa]:=a[son];
          a[son]:=t;
          fa:=son;
          son:=fa*2;
        end else son:=len+1;
    end;
end;

procedure put(x:int64);
var fa,son,t:int64;
begin
  len:=len+1;
  a[len]:=x;
  son:=len;
  fa:=son div 2;
  while a[son]<a[fa] do
    begin
      t:=a[son];
      a[son]:=a[fa];
      a[fa]:=t;
      son:=fa;
      fa:=son div 2;
    end;
end;



begin
  assign(input,'ugly.in');
  reset(input);
  readln(n);
  close(input);
  assign(output,'ugly.out');
  rewrite(output);

  len:=0;
  put(1);
  i:=0;j:=0;
  repeat
    j:=ans;
    ans:=get();
    if ans<>j then
      begin
        i:=i+1;
        put(ans*2);put(ans*3);put(ans*5);put(ans*7);
      end;
  until i=n;

  writeln(ans);
  close(output);
end.
