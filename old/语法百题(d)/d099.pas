program d099;
var p:array[0..10001] of 0..1;
    i,k,n:integer;
begin
  readln(n);
  fillchar(p,sizeof(p),0);
  k:=1;
  repeat
    k:=k+1;
    if p[k]=0 then if k+k<n then
      begin
        i:=k;
        repeat
          i:=i+k;
          p[i]:=1;
        until i+k>n;
      end;
  until k=n div 2;
  for i:=2 to n div 2 do
    if p[i]=0 then
      if p[n-i]=0 then begin writeln(n,'=',i,'+',n-i);break;end;

end.