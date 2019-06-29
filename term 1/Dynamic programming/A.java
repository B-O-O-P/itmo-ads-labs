import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;

public class A {

    static String VTraveSidelOgurechik(int n, int k, int a[]) {
        String ans = "";

        int dp[] = new int[n + 1];
        int monetki[] = new int[n + 1];

        dp[1] = 0;
        int nmax = 0;

        for (int i = 2; i <= n; i++) {
            nmax = i - 1;
            int max;
            if ((i - k) > 1) max = i - k;
            else max = 1;
            for (int j = max; j < i; j++) {
                if (dp[nmax] < dp[j]) nmax = j;
            }
            monetki[i] = nmax;
            dp[i] = dp[nmax] + a[i];
        }

        int cnt = 0;
        int num = n;

        ArrayDeque<Integer> jumps = new ArrayDeque<>();

        jumps.addLast(num);
        while (num > 1) {
            num = monetki[num];
            jumps.add(num);
            cnt++;
        }

        ans = dp[n] + "\n" + cnt + "\n";

        while (!jumps.isEmpty()) ans += jumps.removeLast() + " ";

        return ans;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("input.txt"));
        FileWriter fileWriter = new FileWriter(new File("output.txt"));

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int a[] = new int[n + 1];

        a[1] = 0;
        a[n] = 0;

        for (int i = 2; i < n; i++) a[i] = scanner.nextInt();

        fileWriter.write(VTraveSidelOgurechik(n, k, a) + "");
        fileWriter.flush();
    }
}
