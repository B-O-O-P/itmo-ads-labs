import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class D {

    static int minimin(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }

    static int meme(char i, char j) {
        if (i == j) return 0;
        else return 1;
    }

    static int HereFishyFishy(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int dp[][] = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j > 0) {
                    dp[i][j] = j;
                    continue;
                }
                if (i > 0 && j == 0) {
                    dp[i][j] = i;
                    continue;
                }
                if (j > 0 && i > 0) {
                    dp[i][j] = minimin(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + meme(s1.charAt(i - 1), s2.charAt(j - 1)));
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("input.txt"));
        FileWriter fileWriter = new FileWriter(new File("output.txt"));

        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();

        fileWriter.write(HereFishyFishy(s1, s2) + "");
        fileWriter.flush();
    }
}
