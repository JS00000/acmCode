program d035;
var n,y,m,a,i:longint;p:boolean;
begin
  readln(n);
  a:=n+365;
  for i:=0 to 100 do
    begin
      a:=a-i;
      if a mod 50=0 then
        begin
          a:=a div 50;
          a:=a-5;
          if a mod 2=0 then
            begin
              a:=a div 2;
              if (a>=1) and (a<=12) then p:=true;
            end;
        end;
      if p then begin y:=i;m:=a;writeln(y,' ',m); end;
      a:=n+365;
      p:=false;
    end;
end.