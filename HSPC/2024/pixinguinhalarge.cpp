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
	int n, m; cin >> n >> m;
	map<int, int> mp;
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		mp[a]++;
		mp[b]--;
	}
	int ans = (mp.begin() -> first) - 1;
	int prev = 0;
	int cur = (mp.begin() -> second);
	for(auto it = mp.begin(), it2 = next(mp.begin()); it2 != mp.end(); it++, it2++){
		if(cur == 0){
			ans += it2 -> first - it -> first;
		}
		cur += it2 -> second;
	}
	int max_v = 0;
	for(auto [k, v] : mp) max_v = max(max_v, k);
	cout << ans + (n - max_v) + 1 << endl;
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
