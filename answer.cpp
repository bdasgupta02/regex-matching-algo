class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<vector<int>> mem(slen+1, vector<int>(plen+1, -1));
        helper(s, slen, p, plen, mem);
        return mem[slen][plen] == 1 ? true : false;
    }
    int helper(string& s, int i, string& p, int j, vector<vector<int>>& mem) {
        int isMatch = -1;
        if(mem[i][j] != -1)
            return mem[i][j];
        if(i == 0 && j == 0) {
            mem[i][j] = 1; 
            return 1;
        }
        if(j == 0 && i > 0) {
            mem[i][j] = 0;
            return 0;
        }
        if(i == 0 && j > 0) {
            if(p[j-1] == '*') {
                isMatch = helper(s, i, p, j-2, mem);
                mem[i][j] = isMatch;
                return isMatch;
            }
            return 0;
        }
        if(s[i-1] == p[j-1] || p[j-1] == '.') {
            isMatch = helper(s, i-1, p, j-1, mem);
            mem[i][j] = isMatch; 
            return isMatch;
        }else if(p[j-1] == '*') {
            if(helper(s, i, p, j-2, mem) == 1) {
                mem[i][j] = 1;
                return 1;
            }
            if(p[j-2] == s[i-1] || p[j-2] == '.') {
                isMatch = helper(s, i-1, p, j, mem);
                mem[i][j] = isMatch;
                return isMatch;
            }
        }
        return isMatch;
    }
};
