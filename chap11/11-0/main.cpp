#include "vec.h"
#include <iostream>

int main()
{
  Vec<double> myvec;
  myvec.push_back(1.0);
  myvec.push_back(2.0);
  myvec.push_back(3.0);
  myvec.push_back(4.0);
  myvec.push_back(5.0);


  for (Vec<double>::const_iterator iter = myvec.begin(); iter != myvec.end(); ++iter)
    std::cout << *iter << std::endl;

  std::cout << std::endl;

  myvec.erase(myvec.begin()+1, myvec.begin()+3);

  for (Vec<double>::const_iterator iter = myvec.begin(); iter != myvec.end(); ++iter)
    std::cout << *iter << std::endl;

  std::cout << std::endl;

  myvec.clear();

  for (Vec<double>::const_iterator iter = myvec.begin(); iter != myvec.end(); ++iter)
    std::cout << *iter << std::endl;

  return 0;
}
