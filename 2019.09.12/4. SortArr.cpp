#include <iostream>

using namespace std;

void sortArr(int *Ar, int n){
    int *p = &Ar[0];
    for(int i=0; i<n-1; i++){
        if(p[i]>p[i+1]){
            int temp1 = p[i];
            int temp2 = p[i+1];
            p[i] = temp2;
            p[i+1] = temp1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *Ar = new int[n];
    for(int i=0; i<n; i++){
        cin >> Ar[i];
    }
    sortArr(Ar, n);
    for(int i=0; i<n; i++){
        cout << Ar[i];
    }
    delete [] Ar;
    return 0;
}
