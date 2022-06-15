class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(auto c:chalk) sum+=c;
        long long int extra=k-(k/sum)*sum;
        long long int index=0;
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