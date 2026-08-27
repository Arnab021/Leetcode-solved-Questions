class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        string prefix = "";

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                cnt[x]--;
                prefix += target[i];
            } 
            else {
                break;
            }
        }

        for (int i = prefix.size(); i >= 0; i--) {

            if (i < (int)prefix.size()) {
                cnt[target[i] - 'a']++;
                prefix.pop_back();
            }

            if (i >= n) continue;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string ans = prefix;

                    ans += char('a' + c);
                    cnt[c]--;

                    for (int k = 0; k < 26; k++) {
                        ans += string(cnt[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};