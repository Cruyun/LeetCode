/**
 * @param {string} digits
 * @return {string[]}
 */

const numsMap = {
  1: "",
  2: "abc",
  3: "def",
  4: "ghi",
  5: "jkl",
  6: "mno",
  7: "pqrs",
  8: "tuv",
  9: "wxyz"
}

var letterCombinations = function(digits) {
  if (digits === null || digits === "") {
    return [];
  }

  let result = [];
  let digitIndex = 0;
  let currentDigit = "";
  backtracking(result, digits, digitIndex, currentDigit);
  return result;
};

var backtracking = function(result, digits, digitIndex, currentDigit) {
  if (digitIndex === digits.length) {
    return result.push(currentDigit)
  }

  const currChar = digits[digitIndex];
  const str = numsMap[currChar];
  for (const s of str) {
    currentDigit += s;
    backtracking(result, digits, digitIndex + 1, currentDigit);
    currentDigit = currentDigit.slice(0, -1);
  }
}
