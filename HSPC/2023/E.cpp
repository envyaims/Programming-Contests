// i love amogus <3

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int n = 104;
vector<int> adj[104], adj_t[104];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

void uwu(){
	int m;
	cin >> m;
	map<string,int> mp;
	string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0;i<52;i++) {
		mp[alpha.substr(i,1)] = i;
	}
	for(int i=0;i<m;i++) {
		string s;
		cin >> s;
		if(s=="not") {
			cin >> s;
			string s2; cin >> s2;
			cin >> s2;
			if(s2=="not") {
				cin >> s2;
				int x = mp[s]; int y = mp[s2];
				add_disjunction(x,0,y,0);
			} else {
				assert(0);
			}
		} else {
			string s2; cin >> s2;
			cin >> s2;
			if(s2=="not") {
				cin >> s2;
				int x = mp[s]; int y = mp[s2];
				add_disjunction(x,1,y,0);
			} else {
				int x = mp[s]; int y = mp[s2];
				add_disjunction(x,1,y,1);
			}
		}
	}
	if(solve_2SAT()){
		for (int i=0; i<52; i++){
			if(assignment[i]) cout << alpha[i];
		}
		cout << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}
		
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	for(int _ = 0; _ < T; _++){
		uwu();
	}
}

/*   /\_/\
*   (= ._.)
*   / >  \>
*/
