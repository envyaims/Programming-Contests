#include<bits/stdc++.h>
using namespace std;
using ll = long long;
main() {
	ll N, M; cin >> N >> M;
	vector<string> v(N);
	for(string & s : v) cin >> s;
	vector<vector<ll>> dist(N, vector<ll>(M, -1));
	vector<pair<ll,ll>> bfs;
	for(ll i = 0; i < N; i++) for(ll j = 0; j < M; j++) {
		if(v[i][j]=='0') {
			dist[i][j] = 0;
			bfs.push_back({i,j});
		}
	}
	if(bfs.size()==0) {
		for(ll i = 0; i < N; i++) {
			for(ll j = 0; j < M; j++) {
				vector<pair<ll,ll>> opts = {{0,0}, {0,M-1},{N-1,0},{N-1,M-1}};
				ll ans = 0;
				for(pair<ll,ll> & p : opts) {
					ll dx = abs(p.first-i);
					ll dy = abs(p.second-j);
					ans = max(ans,dx+dy);
				}
				cout << ans+1 << " ";
			}
			cout << endl;
		}
		return 0;
	}
	ll qidx = 0;
	while(qidx < bfs.size()) {
		pair<ll,ll> cur = bfs[qidx++];
		ll ans = 0;
		ll i = cur.first;
		ll j = cur.second;
		vector<pair<ll,ll>> opts = {{i+1,j},{i,j+1},{i-1,j},{i,j-1}};
		for(pair<ll,ll> & p : opts) {
			if(p.first<0 || p.second<0 || p.first==N || p.second==M) continue;
			if(dist[p.first][p.second]==-1) {
				bfs.push_back(p);
				dist[p.first][p.second]=dist[i][j]+1;
			} else dist[p.first][p.second] = min(dist[p.first][p.second], dist[i][j]+1);
		}
	}
	for(ll i = 0; i < N; i++) {
		for(ll j = 0; j < M; j++) cout << dist[i][j]+1 << " ";
		cout << endl;
	}
}
