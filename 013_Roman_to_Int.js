/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var Roman = {
        M : 1000,  
        CM : 900,  
        D : 500,  
        CD : 400,  
        C : 100,  
        XC : 90,  
        L : 50,  
        XL : 40,  
        X : 10,  
        IX : 9,  
        V : 5,  
        IV : 4,  
        I : 1  
    }
    var result = 0;
    var i = 0;
    while (i < s.length) {
        var sub = s.slice(i);
        for (var j in Roman) {
            if (sub.indexOf(j) == 0) {
                result += Roman[j];
                i += j.length;
                break;
            }
        }
    }
    return result;
    
};