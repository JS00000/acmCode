program m005;
  var i,l:integer;s:int64;st:string;
      a:array[0..10] of 0..9;
function c9(n:integer):int64;
  var i:integer;
  begin
    c9:=1;
    for i:=1 to n do c9:=c9*9;
  end;
  begin
    readln(st);
    l:=length(st);
    for i:=1 to l do
      case st[i] of
          '0':a[i]:=0;
          '1':a[i]:=1;
          '2':a[i]:=2;
          '3':a[i]:=3;
          '5':a[i]:=4;
          '6':a[i]:=5;
          '7':a[i]:=6;
          '8':a[i]:=7;
          '9':a[i]:=8;
      end;
    s:=0;
    for i:=1 to l do s:=s+a[i]*c9(l-i);
    writeln(s);
  end.