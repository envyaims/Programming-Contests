// hi

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif

using namespace std;
using ll = int_fast64_t;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

const int N = 10;
vector<vector<int>> five, seven;

vector<vector<int>> generate(int lim){
	vector<vector<int>> out;
	auto get = [&](auto self, int last, int cursum, vector<int> v) -> void{
		if(cursum == lim){
			out.push_back(v);
			return;
		}
		for(int i = last; i <= lim - cursum; i++){
			v.push_back(i);
			self(self, i, cursum + i, v);
			v.pop_back();
		}
	};
	get(get, 1, 0, {});
	return out;
}

void test_case(){
	int n; cin >> n;
	vector<vector<string>> words(N);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		string s; cin >> s;
		words[x].push_back(s);
	}
	
	for(int i = 0; i < sz(five); i++){
		for(int j = 0; j < sz(seven); j++){
			for(int k = 0; k < sz(five); k++){
				vector<int> req(N);
				for(int kk: five[i]) req[kk]++;
				for(int kk: seven[j]) req[kk]++;
				for(int kk: five[k]) req[kk]++;
				
				bool ok = true;
				for(int kk = 0; kk < N; kk++){
					ok &= req[kk] <= sz(words[kk]);
				}
				
				if(ok){
					// we hav answer!!
					for(auto kk: five[i]){
						cout << words[kk].back() << " ";
						words[kk].pop_back();
					}
					cout << "\n";
					for(auto kk: seven[j]){
						cout << words[kk].back() << " ";
						words[kk].pop_back();
					}
					cout << "\n";
					for(auto kk: five[k]){
						cout << words[kk].back() << " ";
						words[kk].pop_back();
					}
					cout << "\n";
					return;
				}
			}
		}
	}
	
	cout << "IMPOSSIBLE\nIMPOSSIBLE\nIMPOSSIBLE\n";
}

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	five = generate(5);
	seven = generate(7);
	
	int t; cin >> t;
	while(t--){
		test_case();
	}
}
