/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */


var isValid=function(nums,threshold,mid){
    var sum=0
    
    for(var i=0;i<nums.length;i++){
        sum+=Math.ceil(nums[i]/mid);
    }
    if(sum>threshold) return false
    else return true
}
var smallestDivisor = function(nums, threshold) {
    var high=Math.max.apply(null,nums)
    var low=1
    var res=1
    
    while(low<=high){
        var mid=(high+low)>>1
        if(isValid(nums,threshold,mid)){
            res=mid
            high=mid-1
        }else low=mid+1
    }
    return res
};