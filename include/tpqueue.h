// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
private: 
  T arr[size] = { 0 };
  int first, last;

public: 
void push(T temp) {
if ((first - last) >= 0) {
  throw std::string ("Full");
} else {
  int i = last;
  while ((i >= first) && arr[i % size].prior > temp.prior) {
    arr[(i + 1) % size] = arr[i % size];
    i -= 1;
  }
arr[(i + 1) % size] = temp;
last += 1;
}	
}
T pop() {
  return arr[(first++) % size];
}
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
