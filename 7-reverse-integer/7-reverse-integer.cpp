class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0) {neg=true;}
        string s=to_string(x);
        if(neg) s.erase(s.begin());
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-1-i]);
        }
        int num;
        try{
            num=stoi(s);
        }catch(exception e){
            return 0;
        }
        if(neg) return -num;
        return num;
    }
};