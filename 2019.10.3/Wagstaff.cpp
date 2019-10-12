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

bool Wags(int n){
    if(prime(n) == 0){
        return 0;
    }
    int k = 3*n-1;
    int s = 0;
    while(k%2 == 0){
        k = k/2;
        s++;
    }
    if(pow(2,s) == 3*n-1){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << Wags(n);
    return 0;
}
