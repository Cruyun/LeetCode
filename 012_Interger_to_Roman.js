/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var Roman = [["","I","II","III","IV","V","VI","VII","VIII","IX"],
             ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"],
             ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"],
             ["","M","MM","MMM","  "," ","  ","   ","    ","  "]];
    if (isNaN(num)) {
        return num;
    }
    var numReverse = num.toString().split("").reverse();
    var result = [];
    for (var i = 0; i < numReverse.length; i++) {
        result.unshift(Roman[i][numReverse[i]]);
    }
    return result.join("");
};