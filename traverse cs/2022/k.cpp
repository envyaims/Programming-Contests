#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007LL;
ll bin_exp(ll b, ll e) {
	ll r= 1;
	while(e) {
		if(e&1) r = (r*b)%mod;
		b = (b*b)%mod;
		e /= 2;
	}
	return r;
}
main() {
	ll N; cin >> N;
	vector<ll> nums(N);
	for(ll & i : nums) cin >> i;
	set<pair<ll,pair<ll,ll>>> edges;
	for(ll i = 0; i < N; i++) for(ll j = i+1; j < N; j++) {
		ll dist = max(bin_exp(nums[i],nums[j]),bin_exp(nums[j],nums[i]));
		edges.insert({-dist,{i,j}});
		edges.insert({-dist,{j,i}});
	}
	vector<ll> group_ids(N);
	for(ll i = 0; i < N; i++) group_ids[i] = i;
	vector<vector<ll>> groups(N);
	ll ans = 0;
	for(ll i = 0; i < N; i++) groups[i].push_back(i);
	for(pair<ll,pair<ll,ll>> p : edges) {
		pair<ll,ll> edge = p.second;
		ll cst = -p.first;
		if(group_ids[edge.first]==group_ids[edge.second]) continue;
		for(ll & i : groups[group_ids[edge.second]]) {
			groups[group_ids[edge.first]].push_back(i);
			group_ids[i] = group_ids[edge.first];
		}
		ans += cst;
	}
	//max_spanning_tree
	cout << ans % mod << endl;
}
