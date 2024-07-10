/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return {
        init:init,
        increment: function() {
            this.init++;
            return this.init;
        },
        decrement: function() {
            this.init--;
            return this.init;
        },
        reset: function() {
            return this.init=init;
        }
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */