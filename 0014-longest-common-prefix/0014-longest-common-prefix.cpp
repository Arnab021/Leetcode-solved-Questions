class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first =strs.front();
        string last=strs.back();
        int minlength=min(first.size(),last.size());
        int i=0;
        string s="";
        while (i < minlength && first[i] == last[i]) {
            s=s+first[i];
            i++;
            
        }
        return s;
    }
};