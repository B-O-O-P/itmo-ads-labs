import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class J {

    static boolean GOGO(long x, long y, int n) {
        long b[] = new long[5];

        for (int i = 0; i < n - 1; i++) {
            if ((x & (1 << i)) == 0) b[1] = 0;
            else b[1] = 1;
            if ((x & (1 << i + 1)) == 0) b[2] = 0;
            else b[2] = 1;
            if ((y & (1 << i)) == 0) b[3] = 0;
            else b[3] = 1;
            if ((y & (1 << i + 1)) == 0) b[4] = 0;
            else b[4] = 1;
            if ((b[1] == b[2]) && (b[2] == b[3]) && (b[3] == b[4])) {
                return false;
            }
        }

        return true;
    }

    static int YouOnlyLiveNice(int n, int m) {
        int res = 0;
        int len = 1 << n;
        long a[][] = new long[m][len];
        long dp[][] = new long[len][len];

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (GOGO(i, j, n)) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < len; i++) {
            a[0][i] = 1;
        }

        for (int x = 1; x < m; x++) {
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    a[x][i] = a[x][i] + a[x - 1][j] * dp[j][i];
                }
            }
        }
        for (int i = 0; i < len; i++) {
            res += a[m - 1][i];
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("nice.in"));
        FileWriter fileWriter = new FileWriter(new File("nice.out"));
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        if (n > m) {
            int tmp = n;
            n = m;
            m = tmp;
        }

        fileWriter.write(YouOnlyLiveNice(n, m) + "");
        fileWriter.flush();
    }
}
