/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
  let map = new Map();
  
  for (let num of nums) {
      if (map.get(num)) {
          let cnt = map.get(num) + 1;
          map.set(num, cnt)
      } else {
          map.set(num, 1)
      }
  }
  const mapSort = new Map([...map.entries()].sort((a, b) => b[1] - a[1]));

  let cnt = 0;
  let res = [];
  
  for (let key of mapSort.keys()) {
      if (cnt < k) {
          res.push(key)
          cnt++
      } else {
          return res
      }
  }
  return res
};