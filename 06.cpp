// Author: envy <3 uwu
// Problem: 22SP - 06 Lantern Festival
// Attempted: 2022-05-06 22:29:30 EST

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
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

void solve() {
    int n; cin >> n;
    vector<vector<int>> graph(n);
    int m; cin >> m;
    vector<int> deg(n);
    for(int i = 0; i < m; i++){
    	int a,b; cin >> a >> b;
    	graph[a].push_back(b);
    	deg[b]++;
    }
    
    // assign the ones with no parents to ones who only has 1 child
    for(int i = 0; i < n; i++){
    	if(deg[i] == 0){
    		for(int j = 0; j < n; j++){
    			if(graph[j].size() == 1 && i != j){
    				graph[j].push_back(i);
    				deg[i]++;
    				break;
    			}
    		}
    	}
    }
    
    // there cant be more lanturns with only 1 child
    for(int i = 0; i < n; i++){
    	if(graph[i].size() == 1 || graph[i].size() > 2){
    		cout << -1 << endl;
    		return;
    	}
    }
    
    
    vector<int> no_parent;
    for(int i = 0; i < n; i++){
    	if(deg[i] == 0){
    		no_parent.push_back(i);
    	}
    }
    
    // there cant be an even number of lanturns left over (we have to start with one)
    if(no_parent.size() % 2 == 0){
    	cout << -1 << endl;
    	return;
    }
    
    // assign the rest to random ones with no children in pairs
	for(int i = 1; i < no_parent.size(); i++){
		bool found = false;
	   	for(int j = 0; j < n; j++){
	   		if(graph[j].size() == 1 && no_parent[i] != j){
	   			deg[no_parent[i]]++;
	   			graph[j].push_back(no_parent[i]);
	   			found = true;
	   			break;
	   		}
	   	}
	   	if(!found){
	   		for(int j = 0; j < n; j++){
	   			if(graph[j].empty() && no_parent[i] != j){
	   				deg[no_parent[i]]++;
	   				graph[j].push_back(no_parent[i]);
	   				break;
	   			}
	   		}
	   	}
	}
	
    for(int i = 0; i < n; i++){
    	sort(graph[i].begin(),graph[i].end());
    }
    
    vector<vector<int>> depth(n+1);
    vector<bool> hung(n);
    
    bool ok = true;
    
    auto dfs = [&](auto self, int node, int d){
    	depth[d].push_back(node);
    	for(int i: graph[node]){
    		if(hung[i]){
    			ok = false;
    			return;
    		}
    		hung[i] = true;
    		self(self, i, d+1);
    	}
    };
    for(int i = 0; i < n; i++){
    	if(deg[i] == 0){
    		hung[i] = true;
    		dfs(dfs,i,0);
    	}
    }
    
    if(!ok){
    	cout << -1 << endl;
    	return;
    }
    
    for(int i = 0; i <= n; i++){
    	for(int j: depth[i]){
    		cout<<j<<"\n";
    	}
    }
    
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
