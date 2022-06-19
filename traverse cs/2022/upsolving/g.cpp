#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1000][1000];
main() {
    ll N; cin >> N;
    vector<string> v(N);
    for(string & s : v) cin >> s;
    for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
        if(v[i][j]=='#') dp[i][j] = 0;
        else dp[i][j] = 1;
    }
    for(ll i = 0; i < N; i++) {
        for(ll j = N-2; j >= 0; j--) {
            if(v[i][j]=='.') dp[i][j] += dp[i][j+1];
        }
    }
    for(ll i = 0; i < N; i++) {
        if(v[N-1][i]=='.') dp[N-1][i] = min(dp[N-1][i],1ll);
    }
    for(ll i = N-2; i >=0; i--) {
        for(ll j = 0; j < N; j++) if(v[i][j]=='.') dp[i][j] = min(dp[i+1][j]+1,dp[i][j]);
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans;
}
