#include <iostream>

using namespace std;

void del_odd(int* &Ar, int &n){
    int n1=0;
    for(int i=0; i<n; i++){
        if(Ar[i]%2!=0){
            n1++;
        }
    }
    int *NewAr = new int[n1];
    int j=0;
    for(int i=0; i<n; i++){
        if(Ar[i]%2!=0){
            NewAr[j]=Ar[i];
            j++;
        }
    }
    delete [] Ar;
    Ar = NewAr;
}

int main(){
    int n;
    cin >> n;
    int *Ar = new int[n];
    for(int i=0; i<n; i++){
        cin >> Ar[i];
    }
    int n1=0;
    for(int i=0; i<n; i++){
        if(Ar[i]%2!=0){
            n1++;
        }
    }
    del_odd(Ar, n);
    for(int i=0; i<n1; i++){
        cout << Ar[i] << endl;
    }
    return 0;
}
