/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

var isIsomorphic = function(s, t) {
  var helper = function(s) {
      let myMap = new Map();
      let count = 1;
      let resStr = "";
      for (let index in s) {
        let str = s[index];
          if (!myMap.get(str)) {
              count++;
              myMap.set(str, count);
              resStr += count.toString();
          } else {
              resStr += myMap.get(str);
          }
      }
      return resStr;
  }
  return helper(s) == helper(t);
};