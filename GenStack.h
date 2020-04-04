#include <iostream>
using namespace std;

class GenStack{

public:

  int stack[100];
  int n = 100;
  int top;

public:
  GenStack(){
    top = -1;
  }
    void push(int val) {
      if(top>=n-1)
      cout<<"Stack Overflow"<<endl;

   else {
      top++;
      stack[top]=val;
   }
}

int peak(){
  return stack[top];
}

void pop() {
   if(top<=-1)
      cout<<"Stack Underflow"<<endl;

   else {
      //cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
         cout<<stack[i]<<" ";
         cout<<endl;
   } else
      cout<<"Stack is empty";
    }

bool empty(){
  if (top<0){
    return true;
    cout<<"Stack is empty";
  }
  else{
    return false;
  }
}
  };
