/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
'use strict'
var filter = function(arr, fn) {
    filteredArr=[];
    n=arr.length;
    for(let i=0;i<n;i++) if(fn(arr[i],i)) filteredArr.push(arr[i]);
    return filteredArr;
};