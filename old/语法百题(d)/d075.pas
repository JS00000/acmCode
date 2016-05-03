program d075;   
var i,j,b,n,x:integer;p:boolean;   
    a:array[0..101] of integer;   
begin  
  i:=0;   
  while not(eoln) do  
    begin  
      i:=i+1;   
      read(a[i]);   
    end;   
  n:=i;   
  read(x);   
  p:=true;   
  for i:=1 to n do if x=a[i] then  
    begin  
      b:=i;   
      for j:=i to n-1 do a[i]:=a[i+1];   
      p:=false;   
      n:=n-1;   
    end;   
  if p then  
    begin  
      i:=0;   
      repeat  
        i:=i+1;   
      until a[i]>x;   
      b:=i;   
      for j:=n+1 downto i+1 do a[j]:=a[j-1];   
      a[i]:=x;   
      n:=n+1;   
    end;   
  writeln(b);   
  for i:=1 to n do write(a[i],' ');   
end.  
