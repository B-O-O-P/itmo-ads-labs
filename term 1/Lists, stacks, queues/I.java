import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class I {


    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("hemoglobin.in"));
        FileWriter fileWriter = new FileWriter(new File("hemoglobin.out"));

        int n = scanner.nextInt();
        int a[] = new int[n];
        int kol = 0;

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            switch (s.charAt(0)) {
                case '+':
                    kol++;
                    a[kol] = a[kol - 1] + Integer.parseInt(s.substring(1));
                    break;
                case '-':
                    fileWriter.write((a[kol] - a[kol - 1]) + "\n");
                    a[kol] = 0;
                    kol--;
                    break;
                case '?':
                    int k = Integer.parseInt(s.substring(1));
                    int sum = a[kol] - a[kol - k];
                    fileWriter.write(sum + "\n");
                    break;
            }
        }

        fileWriter.flush();
    }
}
