import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class G {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("style.in"));

        int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
        int n1 = scanner.nextInt();
        int[] a1 = new int[100001];

        for (int i = 0; i < n1; i++) {
            a1[i] = scanner.nextInt();
        }

        int n2 = scanner.nextInt();
        int[] a2 = new int[100001];

        for (int i = 0; i < n2; i++) {
            a2[i] = scanner.nextInt();
        }

        int n3 = scanner.nextInt();
        int[] a3 = new int[100001];

        for (int i = 0; i < n3; i++) {
            a3[i] = scanner.nextInt();
        }

        int n4 = scanner.nextInt();
        int[] a4 = new int[100001];
        for (int i = 0; i < n4; i++) {
            a4[i] = scanner.nextInt();
        }

        Arrays.sort(a1, 0, n1);
        Arrays.sort(a2, 0, n2);
        Arrays.sort(a3, 0, n3);
        Arrays.sort(a4, 0, n4);


        int min = Math.min(Math.min(a1[0], a2[0]), Math.min(a3[0], a4[0]));
        int max = Math.max(Math.max(a1[0], a2[0]), Math.max(a3[0], a4[0]));
        int diff = Math.abs(max - min);

        int min1 = i1, min2 = i2, min3 = i3, min4 = i4;
        while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4) {
            min = Math.min(Math.min(a1[i1], a2[i2]), Math.min(a3[i3], a4[i4]));
            max = Math.max(Math.max(a1[i1], a2[i2]), Math.max(a3[i3], a4[i4]));
            int diffR = Math.abs(max - min);

            if (diffR < diff) {
                diff = diffR;
                min1 = i1;
                min2 = i2;
                min3 = i3;
                min4 = i4;
            }

            if (diffR < 1) {
                break;
            }

            while (min == a1[i1]) {
                i1++;
            }

            while (min == a2[i2]) {
                i2++;
            }

            while (min == a3[i3]) {
                i3++;
            }

            while (min == a4[i4]) {
                i4++;
            }
        }

        FileWriter fileWriter = new FileWriter("style.out");
        fileWriter.write(a1[min1] + " " + a2[min2] + " " + a3[min3] + " " + a4[min4]);
        fileWriter.flush();
    }
}
