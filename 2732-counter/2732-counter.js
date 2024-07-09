/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let f=n,call=0;
    return function() {
        return f+call++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */