import java.io.*;
import java.util.*;
public class Cipher{
  public static void inverseCaesar(char[] ciphertext, int offset){
    for(int i = 0; i < ciphertext.length; i++){
      char cipherchar = ciphertext[i];
      if(cipherchar < 'a' || cipherchar > 'z'){
        continue;
      }
      int tempchar = (cipherchar - 'a' - offset);
      if(tempchar < 0){
        tempchar += 26;
      }
      if(tempchar >= 26){
        tempchar %= 26;
      }
      tempchar += 'a';
      ciphertext[i] = (char)(tempchar);
    }
  }
  public static void inverseAtbash(char[] ciphertext){
    for(int i = 0; i < ciphertext.length; i++){
      char cipherchar = ciphertext[i];
      if(cipherchar < 'a' || cipherchar > 'z'){
        continue;
      }
      ciphertext[i] = ((char)((25 - (cipherchar - 'a')) + 'a'));
    }
  }
  public static void inverseReverse(char[] ciphertext){
    int pointerOne = 0;
    int pointerTwo = ciphertext.length - 1;
    while(pointerOne < pointerTwo){
      char temp = ciphertext[pointerOne];
      ciphertext[pointerOne] = ciphertext[pointerTwo];
      ciphertext[pointerTwo] = temp;
      pointerOne++;
      pointerTwo--;
    }
  }
  public static void inverseCipher(char[] ciphertext, String cipherinstr){
    //System.out.println("CIPHERINSTR: " + cipherinstr);
    switch(cipherinstr){
      case "A":
        inverseAtbash(ciphertext);
        break;
      case "R":
        inverseReverse(ciphertext);
        break;
      default:
        //System.out.println(cipherinstr);
        inverseCaesar(ciphertext, Integer.parseInt(cipherinstr.substring(1)));
    }
  }
  public static void main(String[] args) throws IOException{
    //char[] DEBUG = new char[] {'t', 'e', ' ', 'm', 'p'};
    //inverseReverse(DEBUG);
    //System.out.println(Arrays.toString(DEBUG));
    //System.out.println(inverseAtbash("az by"));
    //System.out.println(inverseCaesar("lipps asvph", 4));
    //System.out.println(inverseAtbash("iatcqsa lq cetwcq mpnwry 22 qrtwra!"));
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String temp = in.readLine();
    int T = Integer.parseInt(temp);
    for(int i = 0; i < T; i++){
      temp = "";
      while(temp.equals("")){
        temp = in.readLine();
      }
      //String cipher = temp;
      char[] cipher = new char[temp.length()];
      for(int j = 0; j < temp.length(); j++){
        cipher[j] = temp.charAt(j);
      }
      temp = in.readLine();
      int N = Integer.parseInt(temp);
      String ciphers = in.readLine();
      String[] cipherlist = ciphers.split(" ");
      for(int j = cipherlist.length - 1; j >= 0; j--){
        inverseCipher(cipher, cipherlist[j]);
      }
      for(int j = 0; j < cipher.length; j++){
        System.out.print(cipher[j]);
      }
      System.out.print("\n");
    }
  }
}
