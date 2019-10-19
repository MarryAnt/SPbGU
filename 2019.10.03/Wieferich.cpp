#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n){
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0){
            return 0;
        }
    }
    return 1;
}

bool Wief(int n){
    if(prime(n)==0){
        return 0;
    }
    unsigned long int k = pow(2,n-1)-1;
    unsigned long int s = n*n;
    if(k%s == 0){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << Wief(n);
    return 0;
}
