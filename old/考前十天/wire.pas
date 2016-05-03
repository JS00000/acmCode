program wire;
type
  atype=record
    vf:longint;
    ve:longint;
  end;
var
  n,i,j,k,evf,eve,min:longint;
  a:array[0..101,0..101] of longint;
  te:array[0..10001] of atype;
  s:array[0..101] of boolean;
procedure init;
begin
  assign(input,'wire.in');
  reset(input);
  readln(n);
  for i:=1 to n do
   begin
    for j:=1 to n do read(a[i,j]);
    readln;
   end;
  for i:=1 to n do s[i]:=false;
  s[1]:=true;
  close(input);
end;
procedure print;
var sum:longint;
begin
  assign(output,'wire.out');
  rewrite(output);
  sum:=0;
  for i:=1 to n-1 do
    sum:=sum+a[te[i].vf,te[i].ve];
  writeln(sum);
  close(output);
end;
procedure main;
begin
  for i:=1 to n-1 do
   begin
    min:=maxlongint;
    for j:=1 to n do
     if s[j] then
      begin
       for k:=1 to n do
        if (not s[k]) and (a[j,k]>0) and (a[j,k]<min) then
         begin
           evf:=j;
           eve:=k;
           min:=a[j,k];
         end;
      end;
    s[eve]:=true;
    te[i].vf:=evf;
    te[i].ve:=eve;
   end;
end;


begin
  init;
  main;
  print;
end.