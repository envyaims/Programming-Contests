#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define read(x) trav(i,x) cin >> i
#define sz(x) (int)x.size()
#define make_unique(v) sort(all(v)); v.erase(unique(all(v)), v.end())
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
	
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
void solve() {
	vector<vector<int>> g(3, vector<int>(3));
	FOR(i,0,3) FOR(j,0,3) cin >> g[i][j];
	set<vector<vector<int>>> s;
	s.insert(g);
	map<vector<vector<int>>, int> moves;
	queue<vector<vector<int>>> q;
	q.push(g);
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int d = moves[cur];
		int r, c;
		FOR(i,0,3) FOR(j,0,3) if(cur[i][j] == 0){
			r = i; c = j;
		}
		FOR(i,0,4){
			int nr = r + dx[i], nc = c + dy[i];
			if(nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;
			swap(cur[r][c], cur[nr][nc]);
			if(!s.count(cur)){
				s.insert(cur);
				moves[cur] = d + 1;
				q.push(cur);
			}
			swap(cur[r][c], cur[nr][nc]);
		}
	}
	// debug(s);
	int t; cin >> t;
	while(t--){
		vector<vector<int>> gr(3, vector<int>(3));
		FOR(i,0,3) FOR(j,0,3) cin >> gr[i][j];
		assert(moves.count(gr));
		cout << moves[gr] << "\n";
	}
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
