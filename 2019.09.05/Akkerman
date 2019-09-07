#include <iostream>

using namespace std;

long akker(int m, int n){
    if(m == 0){
        return n+1;
    }
    else if(m > 0 && n == 0){
        return akker(m-1, 1);
    }
    else if(m > 0 && n > 0){
        return akker(m-1, akker(m, n-1));
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << akker(m, n);
    return 0;
}
