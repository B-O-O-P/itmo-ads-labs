import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class B {

    static Boolean psp(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            Character cur = s.charAt(i);
            if (stack.empty()) {
                stack.push(cur);
            } else {
                if (stack.peek() == '(' && cur == ')' || stack.peek() == '{' && cur == '}' || stack.peek() == '[' && cur == ']') {
                    stack.pop();
                } else {
                    stack.push(cur);
                }
            }
        }
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("brackets.in"));
        FileWriter fileWriter = new FileWriter(new File("brackets.out"));
        String s = scanner.nextLine();

        if (psp(s)) {
            fileWriter.write("YES");
        } else {
            fileWriter.write("NO");
        }

        fileWriter.flush();
    }
}
