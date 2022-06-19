#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const long double M_PI = 3.14159265358979323846;
main() {
	long double r; cin >> r;
	long double x1, y1, d1d, p1, x2, y2, d2d, p2; cin >> x1 >> y1 >> d1d >> p1 >> x2 >> y2 >> d2d >> p2;
	long double x = x2-x1;
	long double y = y2-y1;
	long double d1 = d1d;
	d1 /= 180.0;
	d1 *= M_PI;
	long double d2 = d2d;
	d2 /= 180.0;
	d2 *= M_PI;
	long double dx = p2*cosl(d2) - p1*cosl(d1);
	long double dy = p2*sinl(d2) - p1*sinl(d1);
	//cur_x = x+tdx
	//cur_y = y+tdy
	//cur_y-y = tdy
	//(cur_y-y)/dy=t
	//cur_x = x + (cur_y-y)*(dx/dy)
	//cur_x^2 + cur_y^2 == r
	//x^2 + 2(tdx)x + (tdx)^2 + (y+tdy)^2 == r^2
	//x^2 + 2xtdx + tdx^2 + y^2 + 2ytdy + tdy^2 == r^2
	//a=dx^2 + dy^2
	//b = 2xdx + 2ydy
	//c = x^2 + y^2
	long double a = dx*dx + dy*dy;
	long double b = 2.0*(x*dx + y*dy);
	long double c = x*x + y*y - r*r;
	long double desc = b*b - 4.0*a*c;
	if(desc < 0.0) {
		cout << -1 << endl;
		return 0;
	}
	desc = sqrtl(desc);
	long double _x1 = (-b - desc)/(2.0*a);
	long double _x2 = (-b + desc)/(2.0*a);
	//cout << _x1 << " " << _x2 << endl;
	long double ans1d = min(_x1,_x2);
	long double ans2d = max(_x1,_x2);
	if(ans2d < 0.0) {
		cout << -1 << endl;
		return 0;
	}
	ans1d *= 1000;
	ans2d *= 1000;
	ll ans1 = round(ans1d);
	ll ans2 = round(ans2d);
	ans1 = max(0ll, ans1);
	cout << ans1 << endl << ans2;
}
