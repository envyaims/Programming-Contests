import java.util.*;
public class Donuts2{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    boolean allSame = true;
    boolean oneSame = false;
    int[] tentativeOutput = new int[n];
    String first = null;
    String prev = null;
    for(int i = 0; i < n; i++){
      String temp = in.next();
      if(first == null){
        first = temp;
      }
      if(allSame && prev != null && (!temp.equals(prev))){
        allSame = false;
      }
      if(!oneSame && (n % 2 == 1) && prev != null && (temp.equals(prev))){
        oneSame = true;
        tentativeOutput[i] = tentativeOutput[i-1];
        continue;
      }
      prev = temp;
      if(i == 0){
        tentativeOutput[i] = 1;
        continue;
      }
      if(tentativeOutput[i-1] == 1){
        tentativeOutput[i] = 2;
      } else {
        tentativeOutput[i] = 1;
      }
    }
    if(!(prev.equals(first)) && tentativeOutput[n-1] == tentativeOutput[0]){
      tentativeOutput[n-1] = 3;
    }
    if(allSame && (!prev.equals(first))){
      allSame = false;
    }
    if(allSame){
      System.out.println("1");
      for(int i = 0; i < n; i++){
        if(i != 0){
          System.out.print(" ");
        }
        System.out.print("1");
      }
      return;
    }
    if(tentativeOutput[n-1] == 3){
      System.out.println("3");
    } else {
      System.out.println("2");
    }
    for(int i = 0; i < n; i++){
      if(i != 0){
        System.out.print(" ");
      }
      System.out.print(tentativeOutput[i]);
    }
  }
}
