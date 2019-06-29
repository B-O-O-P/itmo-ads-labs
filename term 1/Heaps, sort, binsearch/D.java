import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class D {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("radixsort.in"));
        FileWriter fileWriter = new FileWriter(new File("radixsort.out"));

        String s = scanner.nextLine();
        String[] split = s.split(" ");

        int n = Integer.parseInt(split[0]);
        int m = Integer.parseInt(split[1]);
        int k = Integer.parseInt(split[2]);

        String[] list = new String[n];
        for (int i = 0; i < n; i++) {
            list[i] = scanner.nextLine();
        }

        int count = 0;
        int alpha = 26;
        for (int i = m - 1; i >= 0; i--) {
            String b[] = new String[n];
            int[] c = new int[26];
            for (int j = 0; j <= alpha - 1; j++) {
                c[j] = 0;
            }

            for (int j = 0; j <= n - 1; j++) {
                int d = list[j].charAt(i) - 97;
                c[d]++;
            }
            int count = 0;

            for (int j = 0; j <= alpha - 1; j++) {
                int tmp = c[j];
                c[j] = count;
                count += tmp;
            }

            for (int j = 0; j <= n - 1; j++) {
                int d = list[j].charAt(i) - 97;
                b[c[d]] = list[j];
                c[d]++;
            }

            list = b;

            count++;
            if (count == k) {
                break;
            }
        }

        for (int j = 0; j < list.length; j++) {
            fileWriter.write(list[j] + "\r\n");
            fileWriter.flush();
        }
    }
}
