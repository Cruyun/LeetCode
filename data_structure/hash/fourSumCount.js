/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
  let map = new Map();
  let res = 0;
  
  for (let i in A) {
      for (let j in B) {
          let arr = [];
          if (map.get(A[i] + B[j])) {
              arr = map.get(A[i] + B[j]);
          }
          let tmp = [];
          tmp.push(i)
          tmp.push(j);
          arr.push(tmp);
          map.set(A[i] + B[j], arr);
      }
  }
  
  for (let w in C) {
      for (let u in D) {
          let num = -1 * (C[w] + D[u])
          if (map.get(num)) {
              let arrs = map.get(num);
              res += arrs.length
          }
      }
  }
  return res
};