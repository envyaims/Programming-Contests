// uwu <3

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif
using namespace std;
using ll = int_fast64_t;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x) cin >> i
#define sz(x) (int)x.size()
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};

void uwu(){
	ll n; cin >> n;
	
	
	ll l = 0, r = 1e9;
	while(l < r - 1){
		ll x = l + (r - l) / 2;
		if(x * (x + 1) / 2 <= n){
			l = x;
		}
		else r = x;
	}
	
	cout << l << "\n";
	
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin>>t;
	while(t--){
		uwu();
	}
}
