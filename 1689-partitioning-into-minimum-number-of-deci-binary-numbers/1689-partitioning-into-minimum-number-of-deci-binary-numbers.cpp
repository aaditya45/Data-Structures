class Solution {
public:
    int minPartitions(string n) {
        int m=0;
        for(auto x:n){
            m=max(m,x-48);
        }
        return m;
    }
};