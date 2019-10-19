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

bool Germ(int n){
    if(prime(n)==0){
        return 0;
    }
    int k = 2*n+1;
    if(prime(k)==1){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << Germ(n);
    return 0;
}
