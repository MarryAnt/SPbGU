#include <iostream>
#include <cmath>

using namespace std;

bool Mers(int n){
    int k = n+1;
    int s = 0;
    while(k%2 == 0){
        k = k/2;
        s++;
    }
    if(pow(2,s) == n+1){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << Mers(n);
    return 0;
}
