class Solution {
public:
    vector<string> res;

    int minv(string &s) {
        int bal = 0, ans = 0;

        for (char c : s) {
            if (c == '(')
                bal++;
            else if (c == ')') {
                bal--;

                if (bal < 0) {
                    bal = 0;
                    ans++;
                }
            }
        }

        return ans + bal;
    }

    void solve(string &s, int i, int bal, int removed, int minr, string &cur) {
        if (bal < 0 || removed > minr)
            return;

        if (i == s.size()) {
            if (bal == 0 && removed == minr)
                res.push_back(cur);
            return;
        }

        if (s[i] == '(' || s[i] == ')') {
            solve(s, i + 1, bal, removed + 1, minr, cur);
        }

        cur.push_back(s[i]);

        if (s[i] == '(')
            solve(s, i + 1, bal + 1, removed, minr, cur);
        else if (s[i] == ')')
            solve(s, i + 1, bal - 1, removed, minr, cur);
        else
            solve(s, i + 1, bal, removed, minr, cur);

        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        res.clear();

        int minr = minv(s);

        string cur;
        solve(s, 0, 0, 0, minr, cur);

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};