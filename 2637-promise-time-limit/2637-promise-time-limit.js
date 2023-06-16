/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    const timeOut = new Promise((_, reject) => setTimeout(()=>reject('Time Limit Exceeded'), t));
	return async function(...args) {
        try{
             return await Promise.race([fn(...args), timeOut]);
        }catch(err){
            throw err;
        }
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */