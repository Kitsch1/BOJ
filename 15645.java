import java.util.*;
import java.lang.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] price = new int[n][3];
        int[][] dp = new int[n][3];
        for(int r=0;r<n;r++){
            for(int c=0;c<3;c++){
                price[r][c] = sc.nextInt();
            }
        }
        dp[0][0] = price[0][0];
        dp[0][1] = price[0][1];
        dp[0][2] = price[0][2];
        for(int r=1;r<n;r++){
            dp[r][0] = Math.max(dp[r-1][0],dp[r-1][1]) + price[r][0];
            dp[r][1] = Math.max(dp[r-1][0],Math.max(dp[r-1][1],dp[r-1][2])) + price[r][1];
            dp[r][2] = Math.max(dp[r-1][1],dp[r-1][2]) + price[r][2];
        }
        int max_ans = Math.max(dp[n-1][0],Math.max(dp[n-1][1],dp[n-1][2]));

        dp[0][0] = price[0][0];
        dp[0][1] = price[0][1];
        dp[0][2] = price[0][2];
        for(int r=1;r<n;r++){
            dp[r][0] = Math.min(dp[r-1][0],dp[r-1][1]) + price[r][0];
            dp[r][1] = Math.min(dp[r-1][0],Math.min(dp[r-1][1],dp[r-1][2])) + price[r][1];
            dp[r][2] = Math.min(dp[r-1][1],dp[r-1][2]) + price[r][2];
        }
        int min_ans = Math.min(dp[n-1][0],Math.min(dp[n-1][1],dp[n-1][2]));
        System.out.printf("%d %d\n",max_ans,min_ans);
    }
}