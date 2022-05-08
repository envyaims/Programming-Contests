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
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

void solve() {
    int x; cin >> x;
    int live = 0;
    for(int i = 0; i < 8; i++){
    	int v; cin >> v;
    	live += v;
    }
    if(x){
    	if(live == 2 || live == 3)puts("1");
    	else puts("0");
    }
    else{
    	if(live == 3){
    		puts("1");
    	}
    	else puts("0");
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
