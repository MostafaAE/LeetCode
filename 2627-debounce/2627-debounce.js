/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let start = 0;
    let timer;
    return function(...args) {
        const now = Date.now();
        if(now - start <= t)
            clearTimeout(timer);
        
        start = now;
        timer = setTimeout(()=>fn(...args), t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */