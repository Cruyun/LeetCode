var firstUniqChar = function(s) {
  if (s.length < 1) {
      return -1;
  }
  var myMap = new Map();
  for (let index in s) {
    let str = s[index];
    if (!myMap.get(str)) {
        myMap.set(str, 1);
    } else {
      let cnt = myMap.get(str);
        cnt++;
      myMap.set(str, cnt);
    }
  }
  for (let [key, value] of myMap) {
    if (value === 1) {
        return s.indexOf(key);
  }
}
  return -1;
};
