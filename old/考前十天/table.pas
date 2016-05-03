program table;
var n,i,j,v,ys:integer;
    ch:char;
    num:string;
begin
     assign(input,'table.in');
     reset(input);
     assign(output,'table.out');
     rewrite(output);
     readln(n);
     write('*');
     for i:=0 to n-1 do
        if i<10 then write(i:4)
                else  write(chr(ord('A')+i-10):4);
     writeln;
     for i:=0 to n-1 do
       begin
         if i<10 then write(i)
                else  write(chr(ord('A')+i-10));
         write(0:4);
         for j:=1 to i do
           begin
               v:=i*j;
               num:='';
               while v<>0 do
                  begin
                      ys:=v mod n;
                      if (ys>=0) and (ys<=9) then ch:=chr(ord('0')+ys)
                               else  ch:=chr(ord('A')+ys-10);
                      num:=ch+num;
                      v:=v div n
                  end;
               write(num:4);
            end;
         writeln;
        end;
     close(input);
     close(output);
end.
