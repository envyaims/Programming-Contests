import java.io.*;
public class CalicoOne{
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String temp = in.readLine();
    int N = Integer.parseInt(temp);
    for(int i = 0; i < N; i++){
      if(i != 0){
        System.out.print("\n");
      }
      temp = "";
      while(temp.equals("")){
        temp = in.readLine();
      }
      String[] sizes = temp.split("x");
      int R = Integer.parseInt(sizes[0]);
      int C = Integer.parseInt(sizes[1]);
      for(int j = 0; j < R; j++){
        for(int k = 0; k < C; k++){
          if(j % 2 == 0 && k % 2 == 0){
            System.out.print("B");
          } else if (j % 2 == 1 && k % 2 == 1){
            System.out.print("R");
          } else {
            System.out.print("G");
          }
        }
        System.out.print("\n");
      }
    }
  }
}
