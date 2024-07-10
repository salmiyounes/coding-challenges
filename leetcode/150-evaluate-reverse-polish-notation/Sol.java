import java.util.Stack;
import java.util.Set;
import java.util.Arrays;

class Solution {
    public static int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        Set<String> operators = new HashSet<>(Arrays.asList("+", "-", "*", "/"));

        for (String token : tokens) {
            if (!operators.contains(token)) {
                stack.push(Integer.parseInt(token));
            } else {
                int num2 = stack.pop();
                int num1 = stack.pop();
                if (token.equals("+")) {
                    stack.push(num1 + num2);
                } else if (token.equals("-")) {
                    stack.push(num1 - num2);
                } else if (token.equals("*")) {
                    stack.push(num1 * num2);
                } else if (token.equals("/")) {
                    stack.push(num1 / num2);
                }
            }
        }
        return stack.pop();
    }
}
