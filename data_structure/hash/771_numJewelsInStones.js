/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
  if (J.length < 1) {
      return 0;
  }
  let set = new Set();
  for (let index in J) {
      set.add(J[index])
  }
  let res = 0;
  for (let index in S) {
      if (set.has(S[index])) {
          res++;
      }
  }
  return res
};