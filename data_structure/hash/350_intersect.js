/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  var helper = function(nums) {
      let map = new Map();
      nums.map(item => {
          if (map.has(item)) {
              let cnt = map.get(item) + 1;
              map.set(item, cnt);
          } else {
              map.set(item, 1);
          }   
      })
      boolean 
      return map;
  }
  let map1 = helper(nums1);
  let map2 = helper(nums2);
  let res = [];
  for (let [key, value] of map1) {
      if (map2.has(key)) {
          let val2 = map2.get(key);
          let min = value < val2 ? value : val2;
          for (let i = 0; i < min; i++) {
              res.push(key);
          }
      }
  }
  return res;
};