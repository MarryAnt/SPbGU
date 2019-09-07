#include <iostream>

using namespace std;

int factorial(int n){
    if (n == 1) return 1;
    return n*factorial(n-1);
}

int main()
{
    int num, sum = 0;
    cin >> num;
    for(int i=0; i<num; i++){
        int n;
        cin >> n;
        sum+=factorial(n);
    }
    cout << (double)sum/num;
    return 0;
}
