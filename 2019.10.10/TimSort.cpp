#include <iostream>

using namespace std;
const int R = 32;

void InsertionSort(int a[], int from, int to) {
    for (int i = from + 1; i <= to; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (a[j] > temp && j >= from)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void Merge(int a[], int from, int to, int mid){
    int i = from;
	int j = mid + 1;
	int k = 0;
	int temp[to - from + 1];
	while (i <= mid && j <= to) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++; i++;
		}
		else {
			temp[k] = a[j];
			k++; j++;
		}
	}
	while (i <= mid) {
		temp[k] = a[i];
		k++; i++;
	}
	while (j <= to) {
		temp[k] = a[j];
		k++; j++;
	}
	for (i = from; i <= to; i++) {
		a[i] = temp[i - from];
	}
}

void TimSort(int a[], int n) {
    for (int i = 0; i < n; i+=R){
        InsertionSort(a, i, min((i+31), (n-1)));
    }
    for (int s = R; s < n; s = 2*s) {
        for (int f = 0; f < n; f += 2*s){
            int mid = f + s - 1;
            int to = min((f + 2*s - 1), (n-1));
            Merge(a, f, to, mid);
        }
    }
}

int main(){
    int n = 10;
    int arr[10] = {17, 34, 63, 8, 341, 19, 53, 23, 14, 4};
    TimSort(arr, n);
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
    return 0;
}
