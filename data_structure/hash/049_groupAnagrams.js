/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let newStrs = [];
    let map = new Map();
    strs.map((str, index) => {
        let s = str.split('').sort(function(a,b){return a.localeCompare(b)}).join('');
        if (map.has(s)) {
            let arr = map.get(s);
            arr.push(str);
            map.set(s, arr);
        } else {
            map.set(s, [str]);
        }
    })
    let res = [];
    for (let value of map.values()) {
        res.push(value);
    }
    return res;
};