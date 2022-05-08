import java.io.*;
import java.util.*;
public class Main {

	public static int toNum(String[] s, int i){
		if(i >= s.length || i < 0){
			return 0;
		}
		String cur = s[i];
		if(cur.equals("heaven")){
			return 1;
		} else if (cur.equals("earth")){
			return 2;
		}
		return 0;
	}	

	public static String toStringNotTrue(int x){
		switch(x){
			case 0:
				return "life";
			case 1:
				return "heaven";
			case 2:
				return "earth";
		}
		return "hell";
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String base = in.nextLine();
		String str1 = in.nextLine();
		String str2 = in.nextLine();
		String[] token1 = str1.split(" ");
		String[] token2 = str2.split(" ");
		
		ArrayList<String> outputReversed = new ArrayList<String>();

		int carry = 0;

		for(int i = 0; i < Math.max(token1.length, token2.length); i++){
			int a = toNum(token1, token1.length - i - 1);
			int b = toNum(token2, token2.length - i - 1);
			int cur = a + b + carry;
			carry = cur / 3;
			cur %= 3;
			outputReversed.add(toStringNotTrue(cur));
		}
		if(carry != 0){
			outputReversed.add(toStringNotTrue(carry));
		}
		for(int i = outputReversed.size() - 1; i >= 0; i--){
			if(i != outputReversed.size() - 1){
				System.out.print(" ");
			}
			System.out.print(outputReversed.get(i));
		}
	}
}
