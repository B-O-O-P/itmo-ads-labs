import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B2 {

    static class SegmentTree {
        int st[];

        SegmentTree(int a[], int n) {
            st = new int[4 * n];
            buildST(a, 0, n - 1, 0);
        }

        int getMiddle(int l, int r) {
            return l + (r - l) / 2;
        }

        int getSum(int ss, int se, int qs, int qe, int si) {

            if (qs <= ss && qe >= se)
                return st[si];

            if (se < qs || ss > qe)
                return 0;

            int mid = getMiddle(ss, se);
            return getSum(ss, mid, qs, qe, 2 * si + 1) +
                    getSum(mid + 1, se, qs, qe, 2 * si + 2);
        }

        void updateValue(int ss, int se, int i, int diff, int si) {
            if (i < ss || i > se)
                return;
            st[si] = st[si] + diff;
            if (se != ss) {
                int mid = getMiddle(ss, se);
                updateValue(ss, mid, i, diff, 2 * si + 1);
                updateValue(mid + 1, se, i, diff, 2 * si + 2);
            }
        }

        void update(int arr[], int n, int i, int new_val) {
            if (i < 0 || i > n - 1) {
                return;
            }
            int diff = new_val - arr[i];
            arr[i] = new_val;
            updateValue(0, n - 1, i, diff, 0);
        }

        int get(int n, int qs, int qe) {
            if (qs < 0 || qe > n - 1 || qs > qe) {
                return -1;
            }
            return getSum(0, n - 1, qs, qe, 0);
        }

        int buildST(int arr[], int ss, int se, int si) {
            if (ss == se) {
                st[si] = arr[ss];
                return arr[ss];
            }
            int mid = getMiddle(ss, se);
            st[si] = buildST(arr, ss, mid, si * 2 + 1) +
                    buildST(arr, mid + 1, se, si * 2 + 2);
            return st[si];
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("rsq.in"));
        FileWriter fileWriter = new FileWriter(new File("rsq.out"));

        int n = scanner.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) a[i] = scanner.nextInt();

        SegmentTree segmentTree = new SegmentTree(a, n);
        String s = "";
        while (scanner.hasNext()) {
            s = scanner.next();
            switch (s) {
                case "sum":
                    int l = scanner.nextInt() - 1;
                    int r = scanner.nextInt() - 1;
                    fileWriter.write(segmentTree.get(n, l, r) + "\n");
                    break;
                case "set":
                    int i = scanner.nextInt() - 1;
                    int x = scanner.nextInt();
                    segmentTree.update(a, n, i, x);
                    break;
            }
        }

        fileWriter.flush();
    }
}
