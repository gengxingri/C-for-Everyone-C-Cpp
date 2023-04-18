/* 
  Syntax
  Deduce the return value to be double
*/

[](int n) {return n*5.5;}

//explicit
[](int n)->int {return ++n;} 