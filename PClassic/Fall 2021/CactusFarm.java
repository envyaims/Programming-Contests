
   
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tests = Integer.parseInt(br.readLine());
        for (int i = 0; i < tests; i++) {
            String s = br.readLine();
            String t = br.readLine();
            if (matchable(s, t))
                System.out.println("1");
            else
                System.out.println("0");
        }
        br.close();
    }
    //Do not modify above this line
    
    public static boolean matchable(String initialPattern, String finalPattern) {
    	
    	int n = initialPattern.length();
    	int m = finalPattern.length();
    	
    	char[] init, fin;
    	init = new char[n];
    	fin = new char[m];
    	for(int i= 0; i < n; i++){
    		init[i] = initialPattern.charAt(i);
    	}
    	for (int i = 0; i < m; i++)
    	{
    		fin[i] = '0';
    	}
    	
    	for (int i = 0; i < n; i++)
    	{
    		fin[i] = init[i];
    	}
    	
    	for (int i = 1; i <= m - n; i++)
    	{
    		boolean flag = true;
    		for (int j = 0; j <= n - 1 && flag; j++)
    		{
    			if (finalPattern.charAt(i + j) == '0' && init[j] == '1') flag = false;
    		}
			if (flag) 
			{
				for (int j = 0; j <= n-1; j++)
					if (init[j] == '1')
						fin[i + j] = init[j];
			}
    		//for (int j = 0; j < m; j++) System.out.print(fin[j]);
    		//System.out.println();
    	}
    	
    	for (int i = 0; i < m; i++)
    	{
    		if (finalPattern.charAt(i) != fin[i])
    			return false;
    	}
        return true;
    }
}
