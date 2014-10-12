//Reverse a string with only arrays
#include <iostream>
using namespace std;

int main()
{

char str[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
int len = 0;
int cur = str[0];
int ix = 0;
cout << str << endl;
while(cur!=0){
  len += 1;
  ix += 1;
  cur = str[ix];
}
cout << len << endl;
int fst = 0;
int lst = len-1;
char hold;
while(fst < lst){
  hold = str[fst];
  str[fst] = str[lst];
  str[lst] = hold;
  fst += 1;
  lst -= 1;
}
cout << str <<endl;
}

