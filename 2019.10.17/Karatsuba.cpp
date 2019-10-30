#include <iostream>
#include <cmath>

using namespace std;

int Num(long int a){
    int r = 0;
    while (a!=0){
        r++;
        a = a/10;
    }
    return r;
}

long int Karatsuba(long int a, long int b){
    int r = max(Num(a), Num(b));
    int k = r/2;
    long int f = round(pow(10, k));
    long int m = round(pow(10, r));
    long int a2 = a%f;
    long int a1 = a/f;
    long int b2 = b%f;
    long int b1 = b/f;
    long int A = a1*b1;
    long int B = a2*b2;
    long int C = (a1+a2)*(b1+b2);
    return A*m+B+(C-A-B)*f;
}

int main(){
    long int a, b;
    cin >> a >> b;
    cout << Karatsuba(a, b);
    return 0;
}
