/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  let map = new Map();
  let flag = false;
  nums.map((item, index) => {
      if (map.has(item)) {
          let arr = map.get(item);
          arr.map(num => {
              if (Math.abs(num - index) <= k) {
                  flag = true;
              }
          })
          arr.push(index);
          map.set(item, arr);
      } else {
          let arr = [];
          arr.push(index);
          map.set(item, arr);
      }
  })
  return flag;
};