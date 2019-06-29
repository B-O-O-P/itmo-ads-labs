import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class F {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("style.in"));

        int n = scanner.nextInt();
        int a[] = new int[n];
        for (int k = 0; k < n; k++) {
            a[k] = scanner.nextInt();
        }

        int m = scanner.nextInt();
        int b[] = new int[m];
        for (int k = 0; k < m; k++) {
            b[k] = scanner.nextInt();
        }

        int i = 0;
        int j = 0;
        int mini = -1;
        int minj = -1;
        int min = a[n - 1] + b[m - 1];

        while (i < n && j < m) {
            if (Math.abs(a[i] - b[j]) < min) {
                min = Math.abs(a[i] - b[j]);
                mini = a[i];
                minj = b[j];
            }

            if (a[i] > b[j]) {
                j++;
            } else {
                i++;
            }
        }

        FileWriter fileWriter = new FileWriter(new File("style.out"));
        fileWriter.write(mini + " " + minj);
        fileWriter.flush();
    }
}
