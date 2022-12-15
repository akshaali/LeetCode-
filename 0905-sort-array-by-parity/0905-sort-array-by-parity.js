/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function(nums) {
    let ans = [...nums];
    let pt1 = 0, pt2 = nums.length - 1;
    for(let i = 0; i<nums.length; i++){
        if(nums[i]%2 == 0){
            ans[pt1++] = nums[i];
        }else{
            ans[pt2--] = nums[i];
        }
    }
    return ans;
    
};