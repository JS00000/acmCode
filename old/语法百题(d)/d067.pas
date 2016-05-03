program d067;
var st:string;i,l:integer;
begin
  read(st);
  l:=length(st);
  for i:=1 to l do
    begin
      case st[i] of
        'a':write('z');
        'b':write('y');
        'c':write('x');
        'd':write('w');
        'e':write('v');
        'f':write('u');
        'g':write('t');
        'h':write('s');
        'i':write('r');
        'j':write('q');
        'k':write('p');
        'l':write('o');
        'm':write('n');
        'n':write('m');
        'o':write('l');
        'p':write('k');
        'q':write('j');
        'r':write('i');
        's':write('h');
        't':write('g');
        'u':write('f');
        'v':write('e');
        'w':write('d');
        'x':write('c');
        'y':write('b');
        'z':write('a');
      else write(st[i]) end;
    end;
end.