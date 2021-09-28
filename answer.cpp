class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        return backtracking(s, m, p, n);
    }
    
    bool backtracking(string& s, int i, string& p, int j) {
        if (i == 0 && j == 0) return true;
        if (i != 0 && j == 0) return false;
        if (i == 0 && j != 0) {
            if (p[j-1] == '*') {
                return backtracking(s, i, p, j-2);
            }
            return false;
        }

        if (s[i-1] == p[j-1] || p[j-1] == '.') {
            return backtracking(s, i - 1, p, j - 1);
        } else if (p[j-1] == '*') {
            if (backtracking(s, i, p, j - 2)) return true;
            if (p[j-2] == s[i-1] || p[j-2] == '.') {
                return backtracking(s, i - 1, p, j);
            }
            return false;
        }
        return false;
    }
};
