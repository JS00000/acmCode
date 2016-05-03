program tree;
var st,st1,st2:string;
procedure solve(pre,mid:string);
  var i:integer;
  begin
    if (pre='') or (mid='') then exit;
    i:=pos(pre[1],mid);
    solve(copy(pre,2,i-1),copy(mid,1,i-1));
    solve(copy(pre,i+1,length(pre)-i),copy(mid,i+1,length(mid)-i));
    st:=st+pre[1];
  end;
begin
  assign(input,'tree.in');
  reset(input);
  assign(output,'tree.out');
  rewrite(output);
  readln(st1);
  readln(st2);
  st:='';
  solve(st1,st2);
  writeln(st);
  close(input);
  close(output);
end.
