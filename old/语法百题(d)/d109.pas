program d109;
var st:string;i,j,k,l,s,b,d:longint;
function p(c:char):boolean;
  begin
    if (ord(c)>=48) and (ord(c)<=57) then p:=true else p:=false;
  end;
begin
  readln(st);
  l:=length(st);d:=0;b:=0;
  for i:=1 to l do
    begin
      if p(st[i]) then
        begin
          if d=1 then
            begin
              s:=s*10+ord(st[i])-48;
              j:=j+1;
            end else begin s:=ord(st[i])-48;d:=1;j:=1; end;
          if s>b then begin b:=s;k:=i-j+1;end;
        end else d:=0;
    end;
  writeln(k);
end.