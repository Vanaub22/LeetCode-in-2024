/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let val,arg1=init;
    for(let i of nums) {
        val=fn(arg1,i);
        arg1=val;
    }
    return nums.length?val:init;
};