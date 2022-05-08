import java.io.*;
import java.util.*;

public class PretentiousPeacocks {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            int n = Integer.parseInt(br.readLine());
            int[][] pvals = new int[n][2];
            int[] nout = new int[n];
            for (int j = 0; j < n; j++) {
                String[] tmp = br.readLine().split(" ");
                pvals[j][0] = Integer.parseInt(tmp[0]);
                pvals[j][1] = Integer.parseInt(tmp[1]);
            }
            for (int j = 0; j < n; j++) {
                nout[j] = Integer.parseInt(br.readLine());
            }
            System.out.println(unbeatable(n, pvals, nout));
        }
        br.close();
    }
    // Do not modify above this line

    public static int unbeatable(int n, int[][] pvals, int[] out) {
      int ans = 0;
      for(int i = 0; i < n; i++){
        boolean[] visited = new boolean[n];
        visited[i] = true;
        int cur = out[i]-1;
        boolean ok = true;
        while(!visited[cur]){
          if(pvals[i][0] <= pvals[cur][0] && pvals[i][1] <= pvals[cur][1]){
            ok = false;
          }
          visited[cur] = true;
          cur = out[cur]-1;
        }
        if(ok)ans++;

      }
      return ans;
    }



}
