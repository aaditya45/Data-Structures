class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int last_peak=-1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]<s[i]){
                last_peak=i;
            }
        }
        if(last_peak==-1) return -1;
        int index=last_peak;
        for(int i=last_peak;i<s.size();i++){
            if(s[i]>s[last_peak-1]){
                index=i;
            }
        }
        swap(s[last_peak-1],s[index]);
        sort(s.begin()+last_peak,s.end());
        int res=stoll(s);
        if(res>INT_MAX || res<=n) return -1;
        return res;
    }
};