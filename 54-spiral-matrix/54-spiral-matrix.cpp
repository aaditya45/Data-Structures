class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> res;
        int i=0;
        int j=0;
        res.push_back(m[0][0]);
        m[0][0]=-101;
        while(true){
            if(res.size()==m[0].size()*m.size()){
                break;
            }
            while(i+1!=m[0].size()&&m[j][i+1]!=-101){
                i++;
                res.push_back(m[j][i]);
                m[j][i]=-101;
            }
            while(j+1!=m.size()&&m[j+1][i]!=-101){
                j++;
                res.push_back(m[j][i]);
                m[j][i]=-101;
            }
            while(i-1!=-1&&m[j][i-1]!=-101){
                i--;
                res.push_back(m[j][i]);
                m[j][i]=-101;
            }
            while(j-1!=-1&&m[j-1][i]!=-101){
                j--;
                res.push_back(m[j][i]);
                m[j][i]=-101;
            }
        }
        
        return res;
        
    }
};