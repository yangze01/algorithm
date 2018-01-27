#include "Stack.h"

void Test(char actual, char expected){
  if(actual == expected)
    printf("Test passed.\n");
  else
    printf("Test failed.\n");
}

int main(){
  CStack<char> stack;
  stack.appendTail('a');
  stack.appendTail('b');
  stack.appendTail('c');

  char head = stack.deleteTail();
  Test(head, 'c');

  head = stack.deleteTail();
  Test(head, 'b');

  stack.appendTail('d');
  head = stack.deleteTail();
  Test(head, 'd');

  stack.appendTail('e');
  head = stack.deleteTail();
  Test(head, 'e');

  head = stack.deleteTail();
  Test(head, 'a');
  return 0;
}
