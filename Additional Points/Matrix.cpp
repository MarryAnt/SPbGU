#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ar[n][m];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> ar[i][j];
        }
    }
    int ans = 0;
    int b[m], b1[m], b2[m];
    for (int i = 0; i < m; i++){
        b[i] = -1;
    }
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
            if (ar[i][j] != 0){
                b[j] = i;
            }
        }
    while (!st.empty()) st.pop();
    for (int j = 0; j < m; ++j) {
        while (!st.empty() && b[st.top()] <= b[j]) st.pop();
        b1[j] = st.empty() ? -1 : st.top();
        st.push (j);
    }
    while (!st.empty()) st.pop();
    for (int j = m-1; j >= 0; --j) {
        while (!st.empty() && b[st.top()] <= b[j]) st.pop();
        b2[j] = st.empty() ? m : st.top();
        st.push (j);
    }
    for (int j = 0; j < m; ++j){
        ans = max (ans, (i - b[j]) * (b2[j] - b1[j] - 1));
    }
}

cout << ans;
}
