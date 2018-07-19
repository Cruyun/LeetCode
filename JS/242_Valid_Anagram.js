/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(str1, str2) {
  let a = [], b = [];
  a = str1.split("");
  b = str2.split("");
  a.sort();
  b.sort();
  let c = "", d = "";
  a.forEach(i => {
    c += i;
  })
  b.forEach(i => {
    d += i;
  })
  if (c == d) {
    return true;
  }
  return false;
};