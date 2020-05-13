#include<iostream>
#include "Header.h"

int main()
{
  TString empty_str;
  std::cin >> empty_str;

  empty_str = empty_str;

  const char* str = "Hello";
  char arr[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };

  const char* ptr = str + 4;

  char ch = *ptr; 


  TString my_str("Hello");
  TString my_copy(my_str);
  std::cout << my_copy << std::endl;
  bool is_equal = my_str == my_copy;
  bool is_not_equal = my_str != my_copy;

  return 0;
}