/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
  var check = function(arr) {
      let set = new Set();
      for (let value of arr) {
          if (value != '.') {
              let num = parseInt(value);
              if (set.has(num)) {
                  return false
              } else {
                  set.add(num);
              }
          } 
      }
      return true
  }
  
  // 检查每一行
  for (let row of board) {
      if (!check(row)) {
          return false
      }
  }
  // 检查每一列
  for (let i = 0; i < 9; i++) {
      let col = [];
      for (let j = 0; j < 9; j++ ) {
          col.push(board[j][i]);
      }
      if (!check(col)) {
          return false
      }
  }
  // 检查3*3格子
  for (let k = 0; k < 9; k += 3) {
      for (let w = 0; w < 9; w += 3) {
          let arr = []
          for (let i = k; i < k + 3; i++) {
              for (let j = w; j < w + 3; j++) {
                  arr.push(board[i][j]);
              }
          }
          if (!check(arr)) {
              return false
          }
      }
  }
  return true;
};