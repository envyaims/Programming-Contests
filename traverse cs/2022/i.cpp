#include<bits/stdc++.h>
using namespace std;
using ll = long long;
main() {
	cin.tie(0) -> sync_with_stdio(0);
	ll N, M, Q; cin >> N >> M >> Q;
	vector<ll> add(N);
	for(ll & i : add) cin >> i;
	ll tot = 0;
	for(ll & i : add) tot += i;
	vector<vector<ll>> mat(N, vector<ll>(N, 1e18));
	vector<vector<ll>> mat2(N, vector<ll>(N, 1e18));
	for(ll i = 0; i < M; i++) {
		ll a, b, x, y; cin >> a >> b >> x >> y;
		mat[a-1][b-1] = min(mat[a-1][b-1],x);
		mat2[a-1][b-1] = min(mat2[a-1][b-1],y);
	}
	vector<vector<ll>> dists((1ll<<N), vector<ll>(N,1e18));
	for(ll i = 0; i < N; i++) {
		dists[(1ll<<i)][i] = 0;
	}
	vector<vector<ll>> bitlengths(N+1);
	for(ll i = 0; i < (1ll<<N); i++) {
		bitlengths[__builtin_popcount(i)].push_back(i);
	}
	for(ll bits = 2; bits <= N; bits++) {
		vector<ll> & opts = bitlengths[bits];
		for(ll & i : opts) {
			vector<int> pos;
			for(int b = 0; b < N; b++) {
				if((i>>b)&1) pos.push_back(b);
			}
			for(int & end : pos) {
				int tmp = i ^ (1ll<<end);
				ll & val = dists[i][end];
				for(int & prev : pos) {
					if(prev==end)
						continue;
					val = min(val, dists[tmp][prev]+mat[prev][end]);
				}
			}
		}
	}
	vector<ll> mins = dists[(1ll<<N)-1];
	vector<vector<ll>> roar_dists(N);
	for(ll i = 0; i < N; i++) {
		vector<ll> dists(N, 1e18);
		dists[i] = 0;
		set<pair<ll,ll>> q;
		q.insert({0,i});
		vector<bool> vis(N, false);
		while(q.size()) {
			pair<ll,ll> c = *q.begin();
			vis[c.second] = true;
			q.erase(q.begin());
			for(ll j = 0; j < N; j++) {
				if(vis[j]) continue;
				ll dst = dists[c.second] + mat2[c.second][j];
				if(dst<dists[j]) {
					q.erase({dists[j],j});
					dists[j] = dst;
					q.insert({dists[j],j});
				}
			}
		}
		roar_dists[i] = dists;
	}
	vector<ll> max_req(N, 1e18);
	for(ll i = 0; i < N; i++) {
		ll ans = 0;
		for(ll b = 50; b >= 0; b--) {
			ll tmp = ans + (1ll<<b);
			bool cond = true;
			for(ll j = 0; j < N; j++) {
				if(dists.back()[j]==1e18) continue;
				if(roar_dists[i][j]+tmp>=dists.back()[j]+tot) cond = false;
			}
			if(cond == true) ans = tmp;
		}
		max_req[i] = ans;
	}
	ll ans = -1;
	ll idx = 0;
	while(Q--) {
		idx++;
		ll C, K; cin >> C >> K;
		if(ans!=-1) continue;
		if(K<=max_req[C-1]) ans = idx;
	}
	cout << ans << endl;
}
