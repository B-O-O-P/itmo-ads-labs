import java.util.Scanner;

public class C {

    static long HOOOOOOOOOOORSE(int n) {
        long dp[][] = new long[10][n + 1];
        int mod = 1000000000;
        for (int i = 0; i < 10; i++) {
            dp[i][1] = 1;
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i < 10; i++) {
                switch (i) {
                    case 0:
                        dp[0][j] = (dp[4][j - 1] + dp[6][j - 1]) % mod;
                        break;
                    case 1:
                        dp[1][j] = (dp[6][j - 1] + dp[8][j - 1]) % mod;
                        break;
                    case 2:
                        dp[2][j] = (dp[9][j - 1] + dp[7][j - 1]) % mod;
                        break;
                    case 3:
                        dp[3][j] = (dp[8][j - 1] + dp[4][j - 1]) % mod;
                        break;
                    case 4:
                        dp[4][j] = (dp[0][j - 1] + dp[3][j - 1] + dp[9][j - 1]) % mod;
                        break;
                    case 6:
                        dp[6][j] = (dp[0][j - 1] + dp[1][j - 1] + dp[7][j - 1]) % mod;
                        break;
                    case 7:
                        dp[7][j] = (dp[6][j - 1] + dp[2][j - 1]) % mod;
                        break;
                    case 8:
                        dp[8][j] = (dp[1][j - 1] + dp[3][j - 1]) % mod;
                        break;
                    case 9:
                        dp[9][j] = (dp[2][j - 1] + dp[4][j - 1]) % mod;
                        break;
                }
            }
        }

        long sum = 0;
        for (int i = 1; i < 10; i++) if (i != 8) sum = (sum + dp[i][n]) % mod;
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.print(HOOOOOOOOOOORSE(n));
    }
}
