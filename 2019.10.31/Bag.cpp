#include <iostream>

using namespace std;

int Ssort(double arr[][2],int left,int right){
    int i = left;
    int j = right;
    double t = (arr[(left + right)/2][1])/(arr[(left + right)/2][0]);
    while (i <= j) {
        while ((arr[i][1]/arr[i][0]) < t){
            i++;
        }
        while ((arr[j][1]/arr[j][0]) > t){
            j--;
        }
        if (i <= j) {
            swap(arr[i][0],arr[j][0]);
            swap(arr[i][1],arr[j][1]);
            i++;
            j--;
        }
    }
    if (left < j){
        Ssort(arr, left, j);
    }
    if (i < right){
        Ssort(arr, i, right);
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int n;
    double M;
    cin >> n >> M;
    double arr[n][2];
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i=0;i<n;i++){
        cout << "[" << arr[i][0] << arr[i][1] << "]";
    }
    cout << endl;
    Ssort(arr,0,n-1); 
    double sum=0;
    for(int i=n-1;(i>=0)&&(M>0);i--){
        if(M>arr[i][0]){
            sum+=arr[i][1];
            M-=arr[i][0];
        } else{
            cout << M;
            sum+=(M/arr[i][0])*arr[i][1];
            M-=arr[i][0];
            cout << M;
        }
    }
    cout << sum;
    return 0;
}
