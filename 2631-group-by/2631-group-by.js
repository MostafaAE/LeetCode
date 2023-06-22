/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const map = new Map();
    
    for(const item of this)
    {
        const key = fn(item);
        map.has(key) ? map.get(key).push(item) : map.set(key, [item]);
    }
    return Object.fromEntries(map);
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */