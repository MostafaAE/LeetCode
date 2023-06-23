/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
  if (n === 0) return arr;

  const res = [];

  arr.forEach(el => res.push(...(Array.isArray(el) ? flat(el, n - 1) : [el])));
  return res;
};