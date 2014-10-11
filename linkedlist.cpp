// Construct and reverse a linked list

#include <iostream>
using namespace std;

class node {
  public:
  int x;
  node *next;
  node(int val, node* next){
    x = val;
    this->next = next;
  }
};

class linkedlist {
  public:
  node *head;

  linkedlist(){//empty list constructor
    head = 0;
  }

  linkedlist(int *vals, int size){//from array of values
    if(size == 0){
      head = 0;
    } else {
      head = new node(vals[0], 0);
      node *current = head;
      for(int i=1; i<size;i++){
        current->next = new node(vals[i], 0);
        current = current->next;
      }
    }
  }

  void prepend(int val){
    node *newnode = new node(val, head); //put a new node linked before head
    this->head = newnode;//make this new node the head
  }
  
  node* pop(){//pop from front of list
    if(head == 0){
      return 0;
    } else {
      node *ret = head;
      head = head->next;
      ret->next = 0;//detatch the front of the list
      return ret;
    }
  }
  ~linkedlist(){
    node *current = head;
    while( current != 0) {
      node *next = current->next;
      delete current;
      current = next;
    }
  head = 0;
  }

  void reverse(){
    node *tail = pop();
    node *newhead = pop();
    while( tail != 0 && newhead != 0){
      newhead->next = tail;
      tail = newhead;
      newhead = pop();
    } 
    this->head = tail;
  }
  void print(){
    node *current = head;
    while(current != 0){
      cout << current->x <<",";
      current = current->next;
    }
    cout <<"END"<< "\n";
  }
};

int main()
{
  int foo [5] = {1,2,3,4,5};
  int size = sizeof(foo)/sizeof(*foo);
  cout << "constructing list from array of length " << size <<  endl;
  linkedlist* bar = new linkedlist(foo, size);
  cout << "prepending value" << endl;
  bar->prepend(0);
  bar->print();
  cout << "reversing" << endl;
  bar->reverse();
  bar->print();
  
};
