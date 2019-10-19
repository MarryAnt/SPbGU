#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool Er[n+1];
    Er[0]=0;
    Er[1]=0;
    for(int i=2; i<n+1; i++){
        Er[i] = 1;
    }
    for(int i=2; i<n+1; i++){
        if(Er[i]){
            for(int j=2*i; j<n+1; j+=i){
                Er[j]=0;
            }
        }
    }
    for(int i=0; i<n+1; i++){
        if(Er[i]==1){
            cout<<i<<endl;
        }
    }
    return 0;
}
