// Author: envy <3 uwu
// Problem: D. pizza
// Attempted: 2022-06-19 12:24:07 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x)cin >> i
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	
const ld pi = 3.14159265358979323846;

ld area(ll r){
	return r * r * pi;
}

void solve() {
	ll n, r; ld k; cin >> n >> r >> k;
	vector<ll> a(n);
	read(a);
	ld need = area(r);
	
	vector<ld> areas(n);
	FOR(i,0,n){
		areas[i] = area(a[i]);
	}
	sort(all(areas));
	
	debug(need);
	debug(areas);
	
	ll ans = 0;
	FOR(i,0,n){
		ld search = k + need - areas[i];
		ld lowsearch = need - areas[i] - k;
		debug(areas[i], lowsearch, search);
		auto high = upper_bound(all(areas), search) - areas.begin();
		auto low = lower_bound(all(areas), lowsearch) - areas.begin();
		ll range = high - low;
		if(areas[i] >= lowsearch and areas[i] <= search){
			range--;
		}
		debug(low, high);
		ans += range;
	}
	cout << ans / 2 << endl;
	
	
	
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
