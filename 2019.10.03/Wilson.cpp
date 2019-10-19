#include <iostream>
#include <cmath>

using namespace std;

int fact(int n){
    if (n == 1) return 1;
    return n*fact(n-1);
}

bool Wils(int n){
    if((fact(n-1)+1)%n == 0){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << Wils(n);
    return 0;
}
