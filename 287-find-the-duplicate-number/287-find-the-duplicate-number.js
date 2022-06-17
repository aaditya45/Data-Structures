/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    //using fast and slow pointers O(n) and O(1)
    
    var fast=nums[0]
    var slow=nums[0]
    do{
        slow=nums[slow]
        fast=nums[nums[fast]]
    }while(fast!=slow);
    
    fast=nums[0];
    while(fast!=slow){
        slow=nums[slow]
        fast=nums[fast]
    }
    return slow
};