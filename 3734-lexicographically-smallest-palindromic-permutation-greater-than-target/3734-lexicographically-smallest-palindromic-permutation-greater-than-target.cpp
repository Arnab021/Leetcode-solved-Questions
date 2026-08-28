class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        char middle = '\0';
        vector<int> count(26, 0);
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
                middle = char('a' + i);
            }
            count[i] = freq[i] / 2; // Frequencies available for one half
        }
        
        if (oddCount > 1) {
            return "";
        }
        
        int m = n / 2;
        string H = "";
        int i = 0;
        
        // Step 1: Greedily match the target's first half exactly
        for (; i < m; ++i) {
            int c = target[i] - 'a';
            if (count[c] > 0) {
                count[c]--;
                H.push_back(target[i]);
            } else {
                break;
            }
        }
        
        // Step 2: If we matched the entire half, verify if the resulting palindrome is strictly greater
        if (i == m) {
            string P = H;
            if (n % 2 != 0) P += middle;
            string revH = H;
            reverse(revH.begin(), revH.end());
            P += revH;
            
            if (P > target) return P;
            
            // FIX: If the string has only 1 character (or m == 0) and isn't greater, no larger permutation is possible
            if (m == 0) return "";
            
            // If the exact match is not strictly greater, pop the last char to prepare for incrementing
            i = m - 1;
            count[H.back() - 'a']++;
            H.pop_back();
        }
        
        // Step 3: Backtrack to find the first index where we can place a strictly larger character
        bool found = false;
        while (i >= 0) {
            char req = target[i];
            char nxt = '\0';
            
            // Look for the smallest available character strictly greater than target[i]
            for (int c = req - 'a' + 1; c < 26; ++c) {
                if (count[c] > 0) {
                    nxt = c + 'a';
                    break;
                }
            }
            
            if (nxt != '\0') {
                count[nxt - 'a']--;
                H.push_back(nxt);
                found = true;
                break;
            }
            
            // Backtrack if no larger character is available at this index
            if (i > 0) {
                count[H.back() - 'a']++;
                H.pop_back();
            }
            i--;
        }
        
        // If we backed all the way out without finding a valid increment, no permutation is possible
        if (!found) {
            return "";
        }
        
        // Step 4: Fill the remaining slots with the smallest available characters
        for (int c = 0; c < 26; ++c) {
            while (count[c] > 0) {
                H.push_back(c + 'a');
                count[c]--;
            }
        }
        
        string ans = H;
        if (n % 2 != 0) ans += middle;
        string revH = H;
        reverse(revH.begin(), revH.end());
        ans += revH;
        
        return ans;
    }
};