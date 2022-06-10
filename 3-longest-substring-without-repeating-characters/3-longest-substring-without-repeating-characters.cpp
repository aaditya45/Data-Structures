class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> _map(256,-1);
        int r = 0;
        int l = 0;
        int res = 0;
        while(r<s.size()){
            if(_map[s[r]]!=-1){
                l = std::max(l,_map[s[r]]+1);
            }
            _map[s[r]] = r;
            res = std::max(res,r-l+1);
            r++;
        }
        return res;
    }
};