program students;
type stu=record
       num,nam:string;
       score:array[1..5] of byte;
       sum:integer;
     end;
var a:array[0..1001] of stu;
    i,j,k,n:longint;
    p:0..1;
  procedure sort(l,r: longint);
      var
         x,xy,i,j: longint;
         y:stu;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2].sum;
         xy:=a[(l+r) div 2].score[1];
         repeat
           while (a[i].sum>x) or ((a[i].sum=x) and (a[i].score[1]>xy)) do
            inc(i);
           while (x>a[j].sum) or ((x=a[j].sum) and (xy>a[j].score[1])) do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
  assign(input,'students.in');
  reset(input);
  assign(output,'students.out');
  rewrite(output);
  readln(n);
  k:=0;
  for i:=1 to n do a[i].sum:=0;
  for i:=1 to n do
    begin
      readln(a[i].num);
      readln(a[i].nam);
      p:=0;
      for j:=1 to 5 do
        begin
          read(a[i].score[j]);
          a[i].sum:=a[i].sum+a[i].score[j];
          if a[i].score[j]<60 then p:=1;
        end;
      if p=1 then k:=k+1;
      readln;
    end;
  sort(1,n);
  writeln(k);
  if n>20 then n:=20;
  for i:=1 to n do
    begin
      write(a[i].num,' ',a[i].nam,' ');
      for j:=1 to 5 do write(a[i].score[j],' ');
      writeln(a[i].sum);
    end;
  close(input);
  close(output);
end.
