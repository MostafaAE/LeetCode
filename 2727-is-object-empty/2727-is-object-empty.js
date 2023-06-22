/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    
    for(const el in obj)
        return false;
    return true;
    
};