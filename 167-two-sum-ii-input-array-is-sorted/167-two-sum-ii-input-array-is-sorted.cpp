class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a=0,b=numbers.size()-1;
        
        while(a<b){
            int sum=numbers[a]+numbers[b];
            if(sum==target){
                return {a+1,b+1};
            }else if(sum<target){
                a++;;
            }else{
                b--;
            }
        }
        return {0,0};
    }
};