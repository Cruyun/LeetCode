/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  if (s.length <= 1) {
      return s.length;
  }
  let str = "";
  let maxLen = 0;
  
  for (let index in s) {
      let char = s[index];
      let last = str.indexOf(char);
      
      if (str.indexOf(char) === -1) {
          str += char;
          maxLen = maxLen < str.length ? str.length : maxLen
      } else {
          str = str.substr(last + 1) + char;
      }
  }
  return maxLen
};