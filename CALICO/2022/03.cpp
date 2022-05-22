#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

ll dp[200];
int start = 100;

void solve() {
	dp[100] = -1;
	dp[101] = 0;
	dp[102] = 1;
	for(int i = 103; i < 200; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	for(int i = 99; i >= 0; i--){
		dp[i] = dp[i+1] - dp[i+2] - dp[i+3];
	}
	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		cout << dp[100+x+1] << "\n";
	}
	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
