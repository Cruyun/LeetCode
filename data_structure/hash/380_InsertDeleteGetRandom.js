/**
 * Initialize your data structure here.
 */
var RandomizedSet = function() {
  this.map = new Map()
  this.arr = []
};

/**
* Inserts a value to the set. Returns true if the set did not already contain the specified element. 
* @param {number} val
* @return {boolean}
*/
RandomizedSet.prototype.insert = function(val) {
  if (!this.map.has(val)) {
      this.arr.push(val);
      this.map.set(val, this.arr.length - 1)
      return true
  }
  return false
};

/**
* Removes a value from the set. Returns true if the set contained the specified element. 
* @param {number} val
* @return {boolean}
*/
RandomizedSet.prototype.remove = function(val) {
  if (!this.map.has(val)) {
      return false
  }
  let last = this.arr[this.arr.length - 1]
  let valIndex = this.map.get(val)
      
  this.arr[valIndex] = last
  this.map.set(last, valIndex)
      
  this.map.delete(val)
  this.arr.pop()
  return true
};

/**
* Get a random element from the set.
* @return {number}
*/
RandomizedSet.prototype.getRandom = function() {
  let ran = Math.floor(Math.random() * Math.floor(this.arr.length));
  return this.arr[ran]
};

/** 
* Your RandomizedSet object will be instantiated and called as such:
* var obj = Object.create(RandomizedSet).createNew()
* var param_1 = obj.insert(val)
* var param_2 = obj.remove(val)
* var param_3 = obj.getRandom()
*/