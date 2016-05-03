program d088;
var st1,st2:string;l1,l2,lmin,i,j:integer;m,p:1..2;
begin
  readln(st1);
  readln(st2);
  l1:=length(st1)-1;
  l2:=length(st2)-1;
  if l1<l2 then lmin:=l1 else lmin:=l2;
  i:=0;
  p:=2;
  repeat
    i:=i+1;
    if ord(st1[i])<ord(st2[i]) then
      begin
        m:=1;
        p:=1;
      end;
    if ord(st1[i])>ord(st2[i]) then
      begin
        m:=2;
        p:=1;
      end;
  until (p=1) or (i=lmin);
  if (i=lmin) and (p=2) then
    if l1>l2 then
      begin
        writeln(st2);
        writeln(st1);
      end else
      begin
        writeln(st1);
        writeln(st2);
      end else
    if m=1 then
      begin
        writeln(st1);
        writeln(st2);
      end else
      begin
        writeln(st2);
        writeln(st1);
      end;

end.