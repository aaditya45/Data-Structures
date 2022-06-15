class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        for(auto c:chalk) sum+=c;
        int extra=k-(k/sum)*sum;
        int index=0;
        while(extra>=0){
            //cout<<index<<endl;
            if(extra>=chalk[index]){
                extra-=chalk[index];
                index++;
            }else{
                
                break;
            }
        }
        
        return index;
    }
};