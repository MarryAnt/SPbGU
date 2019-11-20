#include <iostream>

using namespace std;

int chip(int *a, int k, int f, int m){
    int s = 0;
    for(int i = k-1; i > 0; i--){
        while(f >= a[i]){
            s++;
            f = f - a[i];
            if ((f == 0) || (s > m)){
                break;
            }
        }
        if (s > m){
            break;
        }
    }
    return s;
}

void chipPrint(int *a, int k, int f){
    int s = 0;
    cout << f << "=";
    for(int i = k-1; i > 0; i--){
        while(f >= a[i]){
            s++;
            f = f - a[i];
            cout << a[i];
            if (f == 0){
                break;
            } else{
                cout << "+";
            }
        }
    }
}

int main(){
    int n;
    int l;
    int k = 1;
    cin >> n;
    int *a = new int;
    a[1] = 1;
    while(a[k] <= n){
        k++;
        a[k] = k*k;
    }
    int c = chip(a, k, n, n);
    int b = k;
    k--;
    while(k > 2){
        l = chip(a, k, n, c);
        if(l < c){
            b = k;
            c = l;
        }
        k--;
    }
    chipPrint(a, b, n);
    delete []a;
    return 0;
}
