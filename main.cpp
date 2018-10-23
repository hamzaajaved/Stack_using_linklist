#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
  int value;
  struct Node *next;
};

void push(int val);
void pop();
void print();
void top();

struct Node *start = NULL;
int main(int argc, char const *argv[])
{
  push(5);
  push(6);
  push(7);
  push(8);
  print();
  top();
  pop();
  print();
  
  system("pause");
  return 0;
}

void push(int val){
  struct Node *ptr;
  ptr = (struct Node*) malloc (sizeof(struct Node));
  ptr->next = NULL;
  ptr->value = val;

  ptr->next = start;
  start = ptr;
}

void pop(){
  if(start == NULL){
    cout << "List is Empty" << endl;
  }else{
    struct Node *curr = start;
    start = start->next;
    free(curr);
  }
}
void print(){
  cout << "STACK" << endl;
  if(start == NULL){
    cout << "Stack is Empty!" << endl;
  }else{
    struct Node *curr = start;
      while(curr != NULL){
        cout << curr->value << " ";;
        curr = curr->next;
      }
      cout << endl;
  }
}

void top(){

  if(start == NULL){
    cout << "Stack is Empty!" << endl;
  }else{
    cout << "Top is: ";
    cout << start->value << endl;
  }
}