class Solution {
public:
    string longestPalindrome(string s) {
        int res = 1;
        int i =0;
        int st = 0;
        int end = 0;
        
        while(i<s.size()-1){
            int a = i;
            int b = i;
            while(b<s.size() && a>=0 && s[a] == s[b]){
                a--;
                b++;
            }
            if((b-a-1)>res){
                res = b-a-1;
                st = a+1;
                end = b;
            }
            i++;
        }
        i = 0;
        while(i<s.size()-1){
            int a = i;
            int b = i+1;
            while(b<s.size() && a>=0 && s[a] == s[b]){
                a--;
                b++;
            }
            if((b-a-1)>res){
                res = b-a-1;
                st = a+1;
                end = b;
            }
            i++;
        }
        //cout<<st<<endl;
        //cout<<res<<endl;
        string ans = "";
        for(int i = st ; i< st + res ; i++){
            ans += s[i];
        }
        return ans;
    }
};