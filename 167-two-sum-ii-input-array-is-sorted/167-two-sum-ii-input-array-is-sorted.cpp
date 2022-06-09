class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2,0);
        for(int i=0;i<numbers.size()-1;i++){
            int a=i+1;
            int b=numbers.size()-1;
            int mid=0;
            int curr_target=target-numbers[i];
            
            res[0]=i+1;
            while(a<=b){
                mid=(a+b)>>1;
                if(curr_target==numbers[mid]){
                    res[1]=mid+1;
                    return res;
                }else if(numbers[mid]>curr_target){
                    b=mid-1;
                }else{
                    a=mid+1;
                }
            }
        }
        cout<<"binary fault"<<endl;
        return res;
    }
};