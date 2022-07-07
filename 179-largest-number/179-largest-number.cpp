class Solution {
public:
    string largestNumber(vector<int>& n) {
        sort(n.begin(),n.end(),[](int&a,int&b){
            return to_string(a)+to_string(b)>to_string(b)+to_string(a);
        });
        string res="";
        
        for(auto x:n) res+=to_string(x);
        if(res[0]=='0') return "0";
        else return res;
    }
};