/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
  const map = new Map();

  arr1.forEach(el => map.set(el.id, el));

  arr2.forEach(el => {
    if (map.has(el.id)) {
      const obj = map.get(el.id);
      Object.entries(el).forEach(entry => {
        const [key, value] = entry;
        obj[key] = value;
      });
    } else map.set(el.id, el);
  });

  return [...map.values()].sort((a, b) => a.id-b.id);
};