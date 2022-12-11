#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x) cin >> i
#define sz(x) (int)x.size()
#define make_unique(v) sort(all(v)); v.erase(unique(all(v)), v.end())
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	

void solve() {
	int c, h, m, n; cin >> c  >> h >> m >> n;
	m += 60 * h;
	vector<array<int, 3>> a(n);
	FOR(i,0,n) cin >> a[i][0] >> a[i][1] >> a[i][2];
	pair<int, int> cur = {1, 1};
	int news = c;
	ll ans = 0;
	trav(i, a){
		int d = abs(i[0] - cur.F) + abs(i[1] - cur.S);
		if(news < i[2]){
			d = cur.F - 1 + cur.S - 1 + i[0] - 1 + i[1] - 1;
			news = c;
		}
		debug(d);
		if(m >= d){
			m -= d;
			ans += i[2];
		}
		else{
			break;
		}
		news -= i[2];
		cur = {i[0], i[1]};
	}
	cout << ans << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
