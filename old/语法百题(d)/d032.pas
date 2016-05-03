program d032;
var i,b,n:integer;
    a:array[0..6] of integer;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(b);
      case b of
        100:a[0]:=a[0]+1;
        90,91,92,93,94,95,96,97,98,99:a[1]:=a[1]+1;
        89,88,87,86,85,84,83,82,81,80:a[2]:=a[2]+1;
        79,78,77,76,75,74,73,72,71,70:a[3]:=a[3]+1;
        69,68,67,66,65,64,63,62,61,60:a[4]:=a[4]+1;
        else a[5]:=a[5]+1;
      end;
    end;
  for i:=0 to 5 do writeln(a[i]);
end.