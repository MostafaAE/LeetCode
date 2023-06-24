/**
 * @param {Object} obj
 * @return {Object}
 */
var compactObject = function (obj) {
  let res;

  if (Array.isArray(obj)) {
    res = [];
    obj.forEach(item => {
      if (item)
        typeof item === 'object'
          ? res.push(compactObject(item))
          : res.push(item);
    });
  } else {
    res = {};
    Object.entries(obj).forEach(entry => {
      if (entry[1])
        typeof entry[1] === 'object'
          ? (res[entry[0]] = compactObject(entry[1]))
          : (res[entry[0]] = entry[1]);
    });
  }
  return res;
};