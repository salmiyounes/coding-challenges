class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> memo = new ArrayList<String>();
        fct(memo, 0, 0, "", n);
        return memo;
    }
    public void fct(List<String> memo, int close, int open, String string, int n) {
        if (string.length() == n * 2) {
            memo.add(string);
            return ;
        }

        if (close < n) {
            fct(memo, close + 1, open, string + "(", n);
        }

        if (open < close) {
            fct(memo, close, open + 1, string + ')', n);
        }
    }
}
