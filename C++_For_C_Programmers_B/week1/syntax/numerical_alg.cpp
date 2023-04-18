/*
   Syntax
   Numerical algorithms Prototypes
*/


//Standard accumulation algorithm whose sum is initially t
//Successive elements from the range b to e are added to sum
template<class InputIter, class T>
T accumulate(InputIter b, InputIter e, T t);

//Accumulation whose sum is initially t
//Succesive elements from range b to e are summed with sum=bop(sum,element)
template<class InputIter, class T, class BinOp>
T accumulate(InputIter b, InputIter e, T t, BinOp bop);

