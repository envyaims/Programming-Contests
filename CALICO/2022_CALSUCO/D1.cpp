// uwu <3

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif
using namespace std;
using ll = int_fast64_t;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x) cin >> i
#define sz(x) (int)x.size()
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	
struct euler_tour {
    vector<int> enter, exit, depth, sz;
    vector<vector<int>> graph, up;
    int n, t = 0, e;
    void dfs(int i, int p) {
        enter[i] = t++;
        up[i][0] = p;
        depth[i] = depth[p]+1;
        for (int j = 1; j <= e; j++)
            up[i][j] = up[up[i][j-1]][j-1];
        for (auto& j : graph[i])
            if (j != p){
				dfs(j, i);
				sz[i] += sz[j];
			}
        exit[i] = t-1;
    }
    euler_tour(vector<vector<int>> g = {}, int root = 0) : graph(g), n(g.size()) {
        if (g.empty()) return;
        enter.resize(n), exit.resize(n), depth.assign(n, 0), sz.assign(n, 1);
        e = ceil(log2(n));
        up.assign(n, vector<int>(e+1));
        dfs(root, root);
    }
    bool is_ancestor(int i, int j) const {
        return enter[i] <= enter[j] && exit[i] >= exit[j];
    }
    int goup(int i, int k) const {
        while (k) {
            int j = k&-k;
            i = up[i][__builtin_ctz(j)];
            k -= j;
        }
        return i;
    }
    int lca(int i, int j) const {
        if (is_ancestor(i, j)) return i;
        if (is_ancestor(j, i)) return j;
        for (int k = e; k >= 0; k--)
            if (!is_ancestor(up[i][k], j))
                i = up[i][k];
        return up[i][0];
    }
    int step(int i, int j) const {
        return is_ancestor(i, j) ? goup(j, depth[j]-depth[i]-1) :up[i][0];
    }
    int dist(int i, int j) {
        return depth[i]+depth[j]-2*depth[lca(i, j)];
    }
};

void uwu(){
	int n; cin >> n;
	vector<vector<int>> graph(n);
	FOR(i,0,n){
		int x; cin >> x;
		graph[x].pb(i);
	}
	euler_tour anc(graph);
	vector<int> res(n);
	FOR(i,0,n)FOR(j,i+1,n) res[anc.lca(i,j)]++;
	cout << *max_element(all(res)) << "\n";
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	cin>>t;
	while(t--){
		uwu();
	}
}
