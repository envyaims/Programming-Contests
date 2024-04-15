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
	int ans = 0;
	int n; cin>>n;
	for (int i = 0; i < n; i++) {
		int a[n];
		for (int j = 0; j < n; j++) {
			cin>>a[j];
			if (i!=j) ans += a[j];
		}
	}
	cout<<ans<<endl;
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
