import java.io.*;
public class Amogus{
  public static void main(String[] args) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String temp = in.readLine();
    int T = Integer.parseInt(temp);
    for(int i = 0; i < T; i++){
      temp = "";
      while(temp.equals("")){
        temp = in.readLine();
      }
      int N = Integer.parseInt(temp);
      int[] votes = new int[N+3]; // 1 indexed
      temp = in.readLine();
      String[] voteArr = temp.split(" ");
      for(int j = 0; j < N; j++){
        votes[Integer.parseInt(voteArr[j])]++;
      }
      int minCrewmateIndex = 0;
      int minCrewmateVoteCount = (1 << 30);
      int maxCrewmateIndex = 0;
      int maxCrewmateVoteCount = -1;
      for(int j = 1; j <= N; j++){
        if(votes[j] > maxCrewmateVoteCount){
          maxCrewmateIndex = j;
          maxCrewmateVoteCount = votes[j];
        }
        if(votes[j] < minCrewmateVoteCount){
          minCrewmateIndex = j;
          minCrewmateVoteCount = votes[j];
        }
      }
      int maxImposterVoteCount = Math.max(votes[N+1], votes[N+2]);
      if(maxImposterVoteCount - maxCrewmateVoteCount > 2){ // cant save them
        System.out.println("SKIP SKIP");
      } else if (maxImposterVoteCount - maxCrewmateVoteCount > 0){
        System.out.println("" + maxCrewmateIndex + " " + maxCrewmateIndex);
      } else if (maxImposterVoteCount == maxCrewmateVoteCount){
        System.out.println("" + maxCrewmateIndex + " SKIP");
      } else {
        System.out.println("" + minCrewmateIndex + " " + minCrewmateIndex);
      }
    }
  }
}
