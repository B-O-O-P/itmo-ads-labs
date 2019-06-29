import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class E {
    static int p[] = new int[1000000];
    static int max[] = new int[1000000];
    static int min[] = new int[1000000];
    static int size[] = new int[1000000];


    static void fun(int x) {
        p[x] = x;
        size[x] = 1;
        max[x] = x;
        min[x] = x;
    }

    static int search(int x) {
        if (p[x] == x) {
            return x;
        }
        return p[x] = search(p[x]);
    }

    static void fun2(int x, int y) {
        x = search(x);
        y = search(y);
        if (x != y) {
            if (size[x] < size[y]) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            p[y] = x;
            size[x] = size[x] + size[y];
            if (max[x] < max[y]) {
                max[x] = max[y];
            } else {
                max[y] = max[x];
            }
            if (min[x] > min[y]) {
                min[x] = min[y];
            } else {
                min[y] = min[x];
            }
        }
    }

    static String show(int x) {
        x = search(x);
        return (min[x] + " " + max[x] + " " + size[x]);
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("dsu.in"));
        FileWriter fileWriter = new FileWriter(new File("dsu.out"));
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= n; i++) {
            fun(i);
        }
        while (scanner.hasNextLine()) {
            String s[] = scanner.nextLine().split(" ");
            switch (s[0]) {
                case "union":
                    fun2(Integer.parseInt(s[1]), Integer.parseInt(s[2]));
                    break;
                case "get":
                    fileWriter.write(show(Integer.parseInt(s[1])) + "\n");
                    break;
            }
        }
        fileWriter.flush();
    }
}
