program d087;
type atype=array[1..3] of integer;
var i,j,k,a,m,n:integer;
    b:array[0..10000] of atype;
begin
  readln(m,n);
  k:=0;
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(a);
          if a<>0 then
            begin
              k:=k+1;
              b[k][1]:=i;
              b[k][2]:=j;
              b[k][3]:=a;
            end;
        end;
      readln;
    end;
  writeln(k);
  for i:=1 to k do writeln(b[i][1],' ',b[i][2],' ',b[i][3]);
end.