program d093;
var n:integer;
procedure gc(a,b,c:char;n:integer);
begin
  if n=1 then writeln(n,':',a,'->',c) else
    begin
      gc(a,c,b,n-1);
      writeln(n,':',a,'->',c);
      gc(b,a,c,n-1);
    end;
end;

begin
  readln(n);
  gc('A','B','C',n);
end.