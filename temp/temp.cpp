// set_intersection example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <algorithm>    // std::set_intersection, std::sort

using namespace std;

int main () {
  // int first[] = {5,10,15,20,25};
  // int second[] = {50,40,30,20,10};
  // std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
  // std::vector<int>::iterator it;

  // std::sort (first,first+5);     //  5 10 15 20 25
  // std::sort (second,second+5);   // 10 20 30 40 50

  // it=std::set_intersection (first, first+5, second, second+5, v.begin());
  //                                              // 10 20 0  0  0  0  0  0  0  0
  // v.resize(it-v.begin());                      // 10 20

  // std::cout << "The intersection has " << (v.size()) << " elements:\n";
  // for (it=v.begin(); it!=v.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';
  int a[100] = {1,10 ,2 ,3 ,5,  19, 23, 34};
  sort(a, a+8);
  for (int i = 0; i < 8; ++i)
  {
    cout << a[i] << " " ;
  }

  int j = 0;
  if (!(a[j = 1] == 4) && a[j] == 2)
  {
    cout << "Trick!" << endl;
  }
  return 0;
} 