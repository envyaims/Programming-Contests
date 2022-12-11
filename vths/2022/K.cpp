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

const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void solve() {
	int n,m,d; cin >> n >> m >> d;
	vt<2,char> grid(n,m);
	FOR(i,0,n) FOR(j,0,m) cin >> grid[i][j];
	
	auto bfs = [&](int sr, int sc){
		queue<pair<int, int>> q;
		q.push({sr, sc});
		vt<2,int> dist(n,m,1e9+1);
		dist[sr][sc] = 0;
		while(!q.empty()){
			auto [r, c] = q.front();
			q.pop();
			FOR(i,0,4){
				int nr = dx[i] + r, nc = dy[i] + c;
				if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
				if(dist[nr][nc] == 1e9+1 && grid[nr][nc] != '#'){
					dist[nr][nc] = dist[r][c] + 1;
					q.push({nr, nc});
				}
			}
		}
		return dist;
	};
	
	map<char, int> mapping = {{'T', 0}, {'L', 1}, {'B' , 2}, {'C', 3} , {'W', 4}, {'M', 5}};
	vt<2,int> mindist(n,m, 1e9), iddist(n,m, 1e9);
	FOR(i,0,n) FOR(j,0,m){
		if(grid[i][j] >= '0' && grid[i][j] <= '9'){
			int id = grid[i][j] - '0';
			auto d = bfs(i, j);
			FOR(ii,0,n) FOR(jj,0,m){
				if(d[ii][jj] < mindist[ii][jj]){
					mindist[ii][jj] = d[ii][jj];
					iddist[ii][jj] = id;
				}
				else if(d[ii][jj] == mindist[ii][jj]){
					if(id < iddist[ii][jj]){
						iddist[ii][jj] = id;
					}
				}
			}
		}
	}
	
	vector<vector<int>> res(d, vector<int>(6));
	int v = 0;
	FOR(i,0,n) FOR(j,0,m){
		if(mapping.count(grid[i][j]) && mindist[i][j] != 1e9){
			ckmax(v, mindist[i][j]);
			res[iddist[i][j]][mapping[grid[i][j]]]++;
		}
	}
	cout << v << endl;
	trav(i, res){
		trav(j, i){
			cout << j << " ";
		}
		cout << "\n";
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
