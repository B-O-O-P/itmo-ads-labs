import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class E {
    public static void antiQsort(int a[]) {
        for (int i = 0; i < a.length; i++) {
            int t = a[i];
            a[i] = a[i / 2];
            a[i / 2] = t;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("antiqs.in"));

        int n = scanner.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        antiQsort(a);

        FileWriter fileWriter = new FileWriter(new File("antiqs.out"));

        for (int i = 0; i < n; i++) {
            fileWriter.write(a[i] + " ");
            fileWriter.flush();
        }
    }
}
