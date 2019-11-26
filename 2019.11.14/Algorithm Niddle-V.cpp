#include <iostream>
#include <cstring>

using namespace std;

int algth(string s1, string s2, int r, int d, int p){
    int a[s1.size()+1][s2.size()+1];
    for(int i = 0; i < s1.size()+1; i++){
        a[i][0] = p*i;
    }
    for(int j = 0; j < s2.size()+1; j++){
        a[0][j] = p*j;
    }
    for(int i = 1; i < s1.size()+1; i++){
        for(int j = 1; j < s2.size()+1; j++){
            int f;
            if(s1[i] == s2[j]){
                f = 0;
            } else{
                f = 1;
            }
            a[i][j] = min(a[i][j-1]+p, a[i-1][j]+d, a[i-1][j-1]+r*f);
        }
    }
    return a[s1.size()][s2.size()];
}

int main(){
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int r, d, p;
    cin >> r; //стоимость замены
    cin >> d; //стоимость удаления
    cin >> p; //стоимость добавления
    int res = algth(s1, s2, r, d, p);
    cout << res;
    return 0;
}
