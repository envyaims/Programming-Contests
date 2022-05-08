// curteosy to ben

#include <bits/stdc++.h>
using namespace std;
int dp[600005][2][2];
int maxx(int p, int q, int r)
{
    return max(p, max(q, r));
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        vector<int> a(n + 5), b(n + 5);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
        }
        dp[1][0][1] = a[1];
        dp[1][0][0] = a[1] * 2; 
        dp[1][1][1] = 0;
        dp[1][1][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // Skip i
            dp[i + 1][1][1] = max(dp[i][1][1], dp[i + 1][1][1]);
            dp[i + 1][0][1] = max(dp[i][1][1] + a[i + 1], dp[i + 1][0][1]);
            dp[i + 1][1][0] = max(dp[i][1][0], dp[i + 1][1][0]);
            dp[i + 1][0][0] = maxx(dp[i][1][0] + a[i + 1], dp[i + 1][0][0], dp[i][1][1] + 2 * a[i + 1]);
            if (i + b[i] + 1 <= n) 
            {
                int k = b[i] + 1;
                dp[i + k][1][1] = max(dp[i][0][1], dp[i + k][1][1]);
                dp[i + k][0][1] = max(dp[i][0][1] + a[i + k], dp[i + k][0][1]);
                dp[i + k][1][0] = max(dp[i][0][0], dp[i + k][1][0]);
                dp[i + k][0][0] = maxx(dp[i][0][0] + a[i + k], dp[i + k][0][0], dp[i][0][1] + 2 * a[i + k]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, max(max(dp[i][0][0], dp[i][0][1]), max(dp[i][1][0], dp[i][1][1])));
        }
        cout << ans << endl;
        
    }
}
