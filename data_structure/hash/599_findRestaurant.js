/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function(list1, list2) {
  let myMap1 = new Map();
  list1.map((item, index) => {
      myMap1.set(item, index);
  })
  let myMap2 = new Map();
  list2.map((item, index) => {
      if (myMap1.has(item)) {
          myMap2.set(item, myMap1.get(item) + index);
      }
  })
  let min = 2001;
  let minLove = [];
  for (let value of myMap2.values()) {
      if (value < min) {
          min = value;
      }
  }
  
  for (let [key, value] of myMap2.entries()) {
      if(value === min) {
          minLove.push(key);
      }
  }
  return minLove;
};