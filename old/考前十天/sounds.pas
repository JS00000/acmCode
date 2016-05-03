
Uses

  WinCrt;




    var i,a:longint;

  begin

  //repeat
   // i:=i+500;sound(i);delay(10);
  //until i>20000;

  randomize;
  i:=0;
  repeat
    i:=i+1;
    a:=random(1000);
    sound(a);delay(50);

  until i=10;


 end.
