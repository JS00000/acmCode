program d018;
  const n=3;
  var a:array[1..3] of integer;i,j,b:integer;
  begin
    for i:=1 to n do read(a[i]);
    for i:=1 to n do
      for j:=i+1 to n do
        if a[i]<a[j] then
          begin
            b:=a[i];
            a[i]:=a[j];
            a[j]:=b;
          end;
    for i:=1 to n do write(a[i],' ');
  end.