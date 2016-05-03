program martian;
var i,j,k,n,t,tot:integer;
    a:array[0..10001] of integer;
begin
  assign(input,'martian.in');
  reset(input);
  assign(output,'martan.out');
  rewrite(output);
  readln(n,tot);
  for i:=1 to n do read(a[i]);
  for k:=1 to tot do
    begin
      i:=n;
      while a[i-1]>a[i] do i:=i-1;
      i:=i-1;
      j:=n;
      while a[j]<a[i] do j:=j-1;
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      i:=i+1;
      j:=n;
      while i<j do
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          i:=i+1;
          j:=j-1;
        end;
    end;
  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);
  close(input);
  close(output);
end.
