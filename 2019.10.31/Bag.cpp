#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n; //количество предметов
    cin >> n;
    int w[n]; //веса предметов
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    int v[n]; //ценности предметов
    for(int j = 0; j < n; j++){
        cin >> v[j];
    }
    int W; //вместительность рюкзака
    cin >> W;
    int m[n+1][W+1];
    for(int j = 0; j <= W; j++){
        m[0][j] = 0;
    }
    for(int i = 0; i <= n; i++){
        m[i][0] = 0;
    }
    for(int k = 1; k <= n; k++){
        for(int s = 1; s <= W; s++){
            if(s >= w[k-1]){
                m[k][s] = max(m[k-1][s], m[k-1][s-w[k-1]] + v[k-1]);
            } else{
                m[k][s] = m[k-1][s];
            }
        }
    }
    cout << m[n+1][W+1];
    return 0;
}
