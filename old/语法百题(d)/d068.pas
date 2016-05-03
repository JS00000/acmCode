program d068;
var st:string;i,l:integer;
begin
  read(st);
  l:=length(st);
  for i:=1 to l do
    begin
      case st[i] of
        'a':write('f');
        'b':write('g');
        'c':write('h');
        'd':write('i');
        'e':write('j');
        'f':write('k');
        'g':write('l');
        'h':write('m');
        'i':write('n');
        'j':write('o');
        'k':write('p');
        'l':write('q');
        'm':write('r');
        'n':write('s');
        'o':write('t');
        'p':write('u');
        'q':write('v');
        'r':write('w');
        's':write('x');
        't':write('y');
        'u':write('z');
        'v':write('a');
        'w':write('b');
        'x':write('c');
        'y':write('d');
        'z':write('e');
      else write(st[i]) end;
    end;
end.
