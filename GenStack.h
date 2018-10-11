#ifndef _GEN_STACK_H_
#define _GEN_STACK_H_

#include <iostream>
#include <stdexcept>

template <class T>
class GenStack {
public:
  GenStack() {}
  GenStack(int);
  ~GenStack() { delete[] data; }

  void push(T);
  T pop();
  T peek() const;
  bool isFull() const;
  bool isEmpty() const;
  void display() const;

private:
  int size;
  int top;
  T* data;
};

template <class T>
GenStack<T>::GenStack(int maxSize) {
  size = maxSize;
  data = new T[maxSize];
  top = -1;
}

template <class T>
void GenStack<T>::push(T d) {
  if ( isFull() ) {
    throw std::runtime_error("Pushing to filled stack");
  }

  data[++top] = d;
}

template <class T>
T GenStack<T>::pop() {
  if ( isEmpty() ) {
    throw std::runtime_error("Popping from empty stack");
  }

  return data[top--];
}

template <class T>
T GenStack<T>::peek() const {
  return data[top];
}

template <class T>
bool GenStack<T>::isFull() const {
  return (top == size - 1);
}

template <class T>
bool GenStack<T>::isEmpty() const {
  return (top == -1);
}

template <class T>
void GenStack<T>::display() const {
  if ( isEmpty() ) {
    std::cout << "Empty stack" << std::endl;
    return;
  }
  for (int i=0; i <= top; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

#endif
