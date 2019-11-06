#include <iostream>
using namespace std;
void SortArr(int* p, int n){
  int m, t;
  for(int i = 0; i < n; i++){
    m = *(p + i);
    for(int j = i+1; j < n; j++){
      if(*(p + i) > *(p + j)){
        t = *(p + i);
        *(p + i) = *(p + j);
        *(p + j) = t;
      }
    }
  }
}
int main() {
  int n; 
  cin » n;
  int *p = new int;
  for(int i = 0; i < n; i++){
    cin » *(p + i);
  }
  SortArr(p,n);
  for(int i = 0; i < n; i++){
    cout « *(p + i) « ' ';
  }
return 0;
}
