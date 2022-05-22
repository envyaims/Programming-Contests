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

vector<string> grid;

void print(int n, int m, int atn, int atm, bool hor, int len){
	if(hor){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i == atn && j >= atm && j < atm + len){
					cout << grid[i][j];
				}
				else cout << '#';
			}
			cout << "\n";
		}
	}
	else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(j == atm && i >= atn && i < atn + len){
					cout << grid[i][j];
				}
				else cout << '#';
			}
			cout << "\n";
		}
	}
}

void solve() {
	string s; cin >> s;
	int len = (int)s.length();
	string rev = s;
	reverse(all(rev));
	int n,m; cin >> n >> m;
	grid.resize(n);
	for(int i = 0; i < n; i++){
		cin >> grid[i];
	}
	
	// hor
	for(int i = 0; i < n; i++){
		if(grid[i].find(s) != string::npos){
			print(n,m,i,grid[i].find(s), true, len);
			return;
		}
		if(grid[i].find(rev) != string::npos){
			print(n,m,i,grid[i].find(rev), true, len);
			return;
		}
	}
	
	vector<string> vert(m);
	for(int i = 0; i < m; i++){
		string cur = "";
		for(int j = 0; j < n; j++){
			cur += grid[j][i];
		}
		if(cur.find(s) != string::npos){
			print(n,m,cur.find(s),i,false,len);
			return;
		}
		if(cur.find(rev) != string::npos){
			print(n,m,cur.find(rev),i,false,len);
			return;
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
