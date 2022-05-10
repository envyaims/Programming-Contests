#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define F first
#define S second
#define all(x) x.begin(), x.end()
using ll = long long;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}


void solve(){
	int n,m,t; 
	cin >> n >> m >> t;
	vector<vector<int>> grid(m,vector<int>(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}
	
	
	vector<int> bruh;
	
	int max_problems = 0; 
	ll min_pen = 1e18;
	
	auto cs = [&](pair<int,int> a, pair<int,int> b){
		return grid[a.F][a.S] < grid[b.F][b.S];
	};
	
	auto upd = [&](int problems, ll pen){
		if(problems > max_problems){
			max_problems = problems;
			min_pen = pen;
		}
		else if(problems == max_problems){
			min_pen = min(min_pen,pen);
		}
	};
	
	auto check = [&](){
		vector<int> pen(m);
		vector<pair<int,int>> probbytime;
		for(int i = 0; i < n; i++){
			probbytime.push_back({bruh[i],i});
		}
		sort(all(probbytime),cs);
		ll curpen = 0;
		for(int i = 0; i < n; i++){
			int member = probbytime[i].F, probno = probbytime[i].S;
			int cost = grid[member][probno];
			if(pen[member] + cost > t){
				upd(i,curpen);
				return;
			}
			pen[member] += cost;
			curpen += pen[member];
		}
		upd(n,curpen);
		
	};
	
	auto rec = [&](auto self){
		if(bruh.size() == n){
			check();
			return;
		}
		for(int i = 0; i < m; i++){
			bruh.push_back(i);
			self(self);
			bruh.pop_back();
		}
	};
	
	rec(rec);
	
	cout << max_problems << " " << min_pen << "\n";
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}

