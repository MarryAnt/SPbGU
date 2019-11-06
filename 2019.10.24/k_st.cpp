#include <iostream>
#include <cmath>

using namespace std;

int k_st(int arr[], int l, int r, int k){
    if(l >= r){
        return arr[l];
    }
    int i = l;
    int j = r;
    int p = arr[(l+r)/2];
    while(i < j){
        while(arr[i] < p){
            i++;
        }
        while(arr[j] > p){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if((k >= l) && (k < i)){
        return k_st(arr, l, i-1, k);
    }
    else if((j < k) && (k <= r)){
        return k_st(arr, j+1, r, k);
    }
    else{
        return arr[p];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << k_st(arr, 0, n-1, k-1);
    return 0;
}
