
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * @author Shahidul Islam
 * @date 2/4/2022
 **/
public class _22_GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        List<String> parenthesesList = new ArrayList<>();
        char[] parentheses = new char[n*2];
        generateParenthesesList(parentheses, 0, n*2, parenthesesList);
        return parenthesesList;

    }

    private void generateParenthesesList(char[] parentheses, int cn, int n, List<String> parenthesesList) {
        if (cn == n) {
            if (isValidParenThesis(parentheses)) {
                parenthesesList.add(new String(parentheses));
            }
        } else {
            for (char ch : new char[]{'(', ')'}) {
                parentheses[cn] = ch;
                generateParenthesesList(parentheses, cn + 1, n, parenthesesList);
            }
        }
    }


    private boolean isValidParenThesis(char[] parentheses) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < parentheses.length; i++) {
            char ch = parentheses[i];
            if (ch == '(') stack.push(ch);
            else if (ch == ')') {
                if (stack.isEmpty()) return false;
                if (stack.pop() != '(') return false;
            }

        }
        return stack.isEmpty();
    }
}
