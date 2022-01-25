class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        std::vector<char> Cur;
        int idx = 0;
        int CurMax = 0;
        while (idx < len) {
            int idxV = 0;
            int lenV = Cur.size();
            while (idxV < lenV) {
                if (Cur[idxV] == s[idx]) {
                    if (CurMax < Cur.size()) {
                        CurMax = Cur.size();
                    }
                    Cur.erase(Cur.begin(), Cur.begin() + idxV + 1);
                    break;
                }
                ++idxV;
            }
            Cur.push_back(s[idx]);
            ++idx;
        }
        if (CurMax < Cur.size()) {
            CurMax = Cur.size();
        }
        return CurMax;
    }
};