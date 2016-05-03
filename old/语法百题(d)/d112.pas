program d112;
var i,n:longint;
begin
  readln(n);
  if n<23 then writeln('0') else writeln((n-23) div 105+1);
end.