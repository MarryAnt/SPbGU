#include <iostream>

using namespace std;

bool prime(int n){
    for (int i=2; i*i<=n; i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}

int dividors(int n, int sum){
    int sum1 = sum;
    int n1 = n;
    if(n%2 == 0){
        sum1++;
        while(n1%2 == 0){
            n1 = n1/2;
        }
        return dividors(n1, sum1);
    }
    else{
        for(int i=3; i*i <= n; i+=2){
            if(n%i == 0){
                sum1++;
                while(n1%i == 0){
                    n1 = n1/i;
                }
                return dividors(n1, sum1);
            }
        }
    }
    if(sum1 == sum && prime(n) == true && n!=1){
        sum1++;
    }
    return sum1;
}

int main(){
    int n, sum = 0;
    cin >> n;
    if (prime(n) == true){
        sum = 1;
    }
    else{
        sum = dividors(n, sum);
    }
    cout << sum;
    return 0;
}
