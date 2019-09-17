#include <iostream>

using namespace std;

int divisers(int a){
    int s = 0;
    if (a == 1){
        return 1;
    }
    else if (a%2 == 0){
       for(int i=2; i<a; i++){
            if(a%i==0){
                s++;
            }
       }
    }
    else{
        for(int i=3; i<a; i+=2){
            if(a%i==0){
                s++;
            }
        }
    }
    return s+2;
}

int main(){
    int a;
    cin >> a;
    cout << divisers(a);
    return 0;
}
