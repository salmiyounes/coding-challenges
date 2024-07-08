class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length() + 1, n2 = word2.length() + 1 ;
        int[][] d = new int[n1][n2];
        for (int i = 1; i < n1; i++) {
            d[i][0] = i;
        }

        for (int j = 1; j < n2; j++) {
            d[0][j] = j;
        }

        for (int j = 1; j < n2; j++) {
            for (int i = 1; i < n1; i++) {
                int substitutionCost = word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1;
                d[i][j] = Math.min(d[i - 1][j] + 1, Math.min(d[i][j - 1] + 1, d[i - 1][j - 1] + substitutionCost));
            }
        }

        return d[n1 - 1][n2 - 1];
    }
}

