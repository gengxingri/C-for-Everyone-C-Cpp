/* 
  Syntax
  Non-mutating algorithms: Prototypes
*/


// Find a position of t in range b to e

template<class Inputlter, Class T>
Inputlter find(Inputlter b, Inputlter e, const T& t);

// Find a position of first element that makes predicate true in range b to e, otherwise position e returned

template<class Inputlter, Class Predicate>
Inputlter find(Inputlter b, Inputlter e, Predicate p);

// Apply f to each value found in range b to e
template<class Inputlter, Class Function>
void for_each(Inputlter b, Inputlter e, Function f);
