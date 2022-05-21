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

const int X = 1e6;

void solve() {
	string name; cin >> name;
	cout << name <<":\n";
	int n; cin >> n;
	vector<pair<string,pair<ll,ll>>> a(n);
	for(int i = 0; i < n; i++){
		string s; ll x,y; cin >> s >> x >> y;
		a[i] = {s,{x,y}};
	}
	
	auto testify = [&](int time){
		string out;
		ll cost = 1e18, mrate = -1;
		for(int j = 0; j < n; j++){
			ll curcost = a[j].S.F + a[j].S.S * time;
			if(curcost < cost){
				cost = curcost;
				out = a[j].F;
				mrate = a[j].S.S;
			}
			else if(curcost == cost && a[j].S.S < mrate){
				cost = curcost;
				out = a[j].F;
				mrate = a[j].S.S;
			}
			
		}
		return out;
	};
	
	string last = testify(0);
	int lastfrom = 0;
	
	int t = 0;
	while(t <= X){
		int l = t, r = X;
		string out = last;
		while(l < r-1){
			int mid = (l+r)/2;
			string s = testify(mid);
			if(s != last){
				out = s;
				r = mid;
			}
			else l = mid;
		}
		if(out != last){
			if(r - lastfrom == 1){
				cout << lastfrom << ": " << last << "\n";
			}
			else{
				cout << lastfrom << "-" << r-1 <<": " << last <<"\n";
			}
			t = r;
			lastfrom = t;
			last = out;
		}
		else break;
		
	}
	cout << lastfrom << "+: " << last << "\n";
	cout << "\n";
	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
