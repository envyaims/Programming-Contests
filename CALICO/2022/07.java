import java.io.*;
public class Cipher{
  public static String inverseCaesar(String ciphertext, int offset){
    String output = "";
    for(int i = 0; i < ciphertext.length(); i++){
      char cipherchar = ciphertext.charAt(i);
      if(cipherchar < 'a' || cipherchar > 'z'){
        output += ("" + cipherchar);
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
      output += ("" + (char)(tempchar));
    }
    return output;
  }
  public static String inverseAtbash(String ciphertext){
    String output = "";
    for(int i = 0; i < ciphertext.length(); i++){
      char cipherchar = ciphertext.charAt(i);
      if(cipherchar < 'a' || cipherchar > 'z'){
        output += ("" + cipherchar);
        continue;
      }
      output += ("" + ((char)((25 - (cipherchar - 'a')) + 'a')));
    }
    return output;
  }
  public static String inverseReverse(String ciphertext){
    String output = "";
    for(int i = ciphertext.length() - 1; i >= 0; i--){
      output += ciphertext.substring(i, i+1);
    }
    return output;
  }
  public static String inverseCipher(String ciphertext, String cipherinstr){
    switch(cipherinstr){
      case "A":
        return inverseAtbash(ciphertext);
      case "R":
        return inverseReverse(ciphertext);
      default:
        return inverseCaesar(ciphertext, Integer.parseInt(cipherinstr.substring(1)));
    }
  }
  public static void main(String[] args) throws IOException{
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
      String cipher = temp;
      temp = in.readLine();
      int N = Integer.parseInt(temp);
      String ciphers = in.readLine();
      String[] cipherlist = ciphers.split(" ");
      for(int j = cipherlist.length - 1; j >= 0; j--){
        cipher = inverseCipher(cipher, cipherlist[j]);
      }
      System.out.println(cipher);
    }
  }
}
