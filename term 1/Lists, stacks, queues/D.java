import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.Scanner;


public class D {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("stack-min.in"));
        FileWriter fileWriter = new FileWriter(new File("stack-min.out"));

        int n = scanner.nextInt();
        ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

        for (int i = 0; i < n; i++) {
            int cur = scanner.nextInt();
            switch (cur) {
                case 1:
                    int val = scanner.nextInt();
                    if (stack.isEmpty()) {
                        stack.push(val);
                    } else {
                        val = Integer.min(val, stack.peek());
                        stack.push(val);
                    }
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    fileWriter.write(stack.peek() + "\n");
                    break;
            }
        }

        fileWriter.flush();
    }
}
