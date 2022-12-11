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
	int n; cin >> n;
	string s; cin >> s;
	vector<int> bad(n+1);
	vector<int> cnt1(n+1);
	FOR(i,0,n){
		bad[i+1] += bad[i];
		cnt1[i+1] = cnt1[i];
		cnt1[i+1] += s[i] == '(' ? 1 : -1;
		if(cnt1[i+1] < 0){
			bad[i+1]++;
			cnt1[i+1] = 0;
		}
	}
	if(bad[n] == 0 && cnt1[n] == 0){
		cout << s << endl;
		return;
	}
	vector<int> bad2(n+2);
	vector<int> cnt2(n+2);
	ROF(i,n-1,0){
		bad2[i+1] += bad2[i+2];
		cnt2[i] = cnt2[i+1];
		cnt2[i] += s[i] == ')' ? 1 : -1;
		if(cnt2[i] < 0){
			bad2[i+1]++;
			cnt2[i] = 0;
		}
	}
	debug(bad, bad2);
	debug(cnt1, cnt2);
	int cut = -1;
	FOR(i,0,n){
		if(bad[i+1] == bad2[i+1] && cnt1[i+1] == 0 && cnt2[i+1] == 0){
			cut = i;
			break;
		}
	}
	if(cut == -1){
		cout << "Impossible" << endl;
		return;
	}
	FOR(i,cut+1,n) cout << s[i];
	FORE(i,0,cut) cout << s[i]; 
	// vector<int> pref(n+1), suff(n+2);
	// FORE(i,1,n){
		// pref[i] = pref[i-1] + (s[i-1] == '(' ? 1 : -1);
	// }
	// map<int, vector<int>> at;
	// FORE(i,1,n) at[pref[i]].pb(i);
	// ROF(i,n,1){
		// suff[i] = suff[i+1] + (s[i-1] == ')' ? 1 : -1);
	// }
	// int cut = -1;
	// FORE(i,1,n){
		// if(pref[i] == suff[i+1] == 0){
			// cut = i;
			// break;
		// }
	// }
	// debug(pref, suff);
	// debug(cut);
	// if(cut == -1){
		// cout << "impossible" << endl;
		// return;
	// }
	// string back = s.substr(0, cut);
	// cout << s.substr(cut) + back << endl;
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
