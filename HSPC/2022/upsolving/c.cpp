// cum is the only solution

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif

using namespace std;
using ll = int_fast64_t;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void ckmin(ll& a, ll b){
	a = min(a, b);
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int n,m,t; cin >> n >> m >> t;
	vector<vector<int>> time(m, vector<int>(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> time[i][j];
		}
	}
	
	vector<vector<ll>> totaltime(m, vector<ll>(1 << n));
	vector<vector<ll>> totalpen(m, vector<ll>(1 << n));
	
	// precompute penalty and time
	for(int mask = 0; mask < (1 << n); mask++){
		for(int i = 0; i < m; i++){
			vector<ll> T;
			ll sum = 0;
			for(int j = 0; j < n; j++){
				if(mask & (1 << j)){
					sum += time[i][j];
					T.push_back(time[i][j]);
				}
			}
			ll pen = 0;
			sort(all(T));
			reverse(all(T));
			for(int j = 0; j < sz(T); j++){
				pen += (j + 1) * T[j];
			}
			totaltime[i][mask] = sum;
			totalpen[i][mask] = pen;
		}
	}
	
	vector<vector<ll>> dp(m, vector<ll>(1 << n, 1e18));
	// dp[member][problem mask] = min pen
	for(int i = 0; i < (1 << n); i++){
		if(totaltime[0][i] < t){
			dp[0][i] = totalpen[0][i];
		}
	}
	
	for(int i = 1; i < m; i++){
		for(int mask = 0; mask < (1 << n); mask++){
			for(int subset = mask; true; subset = (subset - 1) & mask){
				int solve = (~subset) & mask;
				if(totaltime[i][solve] <= t){
					ckmin(dp[i][mask], dp[i-1][subset] + totalpen[i][solve]);
				}
				if(subset == 0) break;
			}
		}
	}
	
	int maxsolve = 0;
	ll minpen = 1e18;
	for(int mask = 0; mask < (1 << n); mask++){
		int solve = __builtin_popcount(mask);
		if(solve > maxsolve && dp[m-1][mask] != 1e18){
			maxsolve = solve;
			minpen = dp[m-1][mask];
		}
		else if(solve == maxsolve && dp[m-1][mask] < minpen){
			minpen = dp[m-1][mask];
		}
	}
	cout << maxsolve << " " << minpen << endl;
}
