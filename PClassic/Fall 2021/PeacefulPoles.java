import java.io.*;

public class Main {
  public static int maxPoints(String s, String t) {
	int n = s.length(), m = t.length();
	if (n == 0 && m == 0) return 0;
	if (n == 0)
		return 2 * m;
	if (m == 0)
		return 2 * n;
	char[] a = new char[s.length()];
	char[] b = new char[t.length()];
	for (int i = 0; i < n; i++) a[i] = s.charAt(i);
	for (int i = 0; i < m; i++) b[i] = t.charAt(i);
	int[][] dp = new int[s.length() + 1][t.length() + 1];
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int match = 0;
			if (a[i - 1] == b[j - 1]) match = 1;
			else match = -1;
			dp[i][j] = Math.max(dp[i - 1][j - 1] + match,  Math.max(dp[i - 1][j] - 2, dp[i][j - 1] - 2));
		}
	}
    return dp[n][m];
  }

  // Do not modify below this line
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int tests = Integer.parseInt(br.readLine());
    for (int i = 0; i < tests; i++) {
      String s = br.readLine();
      String t = br.readLine();
      System.out.println(maxPoints(s, t));
    }
    br.close();
  }
}
