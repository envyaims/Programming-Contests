// #pragma GCC optimize("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
#define all(x) x.begin(), x.end()

void solve(){
	ll n; cin>>n;
	int r; cin>>r;
	int q; cin>>q;
	ll a[r], b[r];
	for (int i = 0; i < r; i++) {
		cin>>a[i]>>b[i];
	}
	for (int z = 0; z < q; z++) {
		ll x; cin>>x;
		for (int i = r-1; i >= 0; i--) {
			if (x >= a[i] && x <= b[i]) {
				x = a[i] + (b[i] - x);
			}
		}
		cout<<x<<"\n";
	}
}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
