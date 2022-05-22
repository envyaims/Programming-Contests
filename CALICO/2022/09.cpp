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
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

const int N = 305, M = 305;
int n,m;
string s;
char grid[N][M];
bool found = false;

const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

void ff(int r, int c, int idx, vector<pair<int,int>> mp){
	if(idx == s.length()){
		//debug(s,mp);
		found = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(find(all(mp),make_pair(i,j)) != mp.end()){
					cout << grid[i][j];
				}
				else cout << '#';
			}
			cout << "\n";
		}
		//cout << "\n";
	}
	if(found)return;
	for(int i = 0; i < 4; i++){
		int nr = dx[i] + r, nc = dy[i] + c;
		if(nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
		if(s[idx] == grid[nr][nc] && find(all(mp), make_pair(nr,nc)) == mp.end()){
			mp.push_back({nr,nc});
			ff(nr,nc,idx+1,mp);
			mp.pop_back();
		}
	}
}

void solve() {
	cin >> s >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == s[0]){
				vector<pair<int,int>> idx = {{i,j}};
				ff(i,j,1,idx);
				if(found)return;
			}
		}
	}
	
	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int test = 1; test <= t; test++){
		found = false;
		solve();
	}
}
