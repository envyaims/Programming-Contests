// i love amogus <3

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "../template/debug.cpp"
#endif

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define int ll

const int P1 = 1000000007;
const int P2 = 998244353;
const int P3 = 1000000009;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

#define poly vector<int>

bool eval (poly a, int val){
	int res1=0, res2=0, res3=0;
	int cur1=1, cur2=1, cur3=1;
	for (int i=0; i<sz(a); i++){
		res1 += a[i]*cur1;
		res2 += a[i]*cur2;
		res3 += a[i]*cur3;
		cur1 *= val;
		cur1 %= P1;
		cur2 *= val;
		cur2 %= P2;
		cur3 *= val;
		cur3 %= P3;
		res1 %= P1;
		res2 %= P2;
		res3 %= P3;
	}
	res1 = ((res1%P1)+P1)%P1;
	res2 = ((res2%P2)+P2)%P2;
	res3 = ((res3%P3)+P3)%P3;
	return (res1+res2+res3 == 0);
	
}

poly mul(poly a, poly b){
	poly c;
	c.resize(sz(a)+sz(b)-1);
	for (int i=0; i<sz(a); i++){
		for (int j=0; j<sz(b); j++){
			c[i+j] += a[i]*b[j];
		}
	}
	return c;
}

poly add(poly a, poly b) {
	poly c(max(a.size(),b.size()));
	for(int i=0;i<c.size();i++) {
		int sum = 0;
		if(i<a.size()) {
			sum += a[i];
		}
		if(i<b.size()) {
			sum += b[i];
		}
		c[i] = sum;
	}
	return c;
}

poly f(string s) {
	poly ans;
	for(int i=s.size()-1;i>=0;i--) {
		ans.push_back(s[i]-'0');
	}
	return ans;
}

vector<int> fact(int num){
	num = abs(num);
	vector<int> ret;
	for (int i=1; i*i<=num; i++){
		if(num%i) continue;
		ret.push_back(i);
		if(i*i != num) ret.push_back(num/i);
	}
	return ret;
}

void uwu(){
	string s;
	cin >> s;
	int mx = 1;
	for (int i=0; i<s.size(); i++){
		if(s[i] == '=') continue;
		if(s[i] == '+') continue;
		if(s[i] == '*') continue;
		mx = max(mx,(ll)(s[i]-'0'));
	}
	vector<string> a = split(s,"=");
	poly x; poly y;
	for(int i=0;i<2;i++) {
		stack<poly> stk;
		vector<string> b = split(a[i],"+");
		vector<poly> polys;
		for(int j=0;j<b.size();j++) {
			vector<string> c = split(b[j],"*");
			poly ans = f(c[0]);
			for(int k=1;k<c.size();k++) {
				ans = mul(ans,f(c[k]));
			}
			polys.push_back(ans);
		}
		poly ans = polys[0];
		for(int j=1;j<polys.size();j++) {
			ans = add(ans,polys[j]);
		}
		if(!i) {
			x = ans;
		} else {
			y = ans;
		}
	}
	for (int& z: y) z = -z;
	x = add(x,y);
	bool allz = true;
	for (int i: x) if(i != 0) allz = false;
	if(allz){
		mx++;
		cout << mx << "+" << endl;
		return;
	}
	vector<int> divs = fact(x[0]);
	sort(all(divs));
	vector<int> ans;
	for (int d: divs){
		if(d <= mx) continue;
		if(eval(x,d)){
			ans.push_back(d);
		}
	}
	if(sz(ans) == 0) cout << "IMPOSSIBLE" << endl;
	else{
		for (int uwu: ans) cout << uwu << " ";
		cout << endl;
	}
}

signed main(){
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
