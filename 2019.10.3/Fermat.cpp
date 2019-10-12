#include <iostream>
#include <cmath>

using namespace std;

bool Ferm(int n){
    int k = n-1;
    int s = 0;
    while(k%2 == 0){
        s++;
        k = k/2;
    }
    if(pow(2,s)!= n-1){
        return 0;
    }
    int m = s;
    int l = 0;
    while(m%2 == 0){
        l++;
        m = m/2;
    }
    if(pow(2,l)==s){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << Ferm(n);
    return 0;
}
