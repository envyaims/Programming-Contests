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
	int n = 9;
	vector<int> a(n);
	for(int& i: a) cin >> i;
	sort(all(a));
	vector<int> b(n);
	iota(all(b), 1);
	puts(a == b ? "YES" : "NO");
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
