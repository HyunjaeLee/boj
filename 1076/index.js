const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8');
const color = input.split('\n');
const table = {
    black: 0,
    brown: 1,
    red: 2,
    orange: 3,
    yellow: 4,
    green: 5,
    blue: 6,
    violet: 7,
    grey: 8,
    white: 9,
};
console.log((table[color[0]] * 10 + table[color[1]]) * 10 ** table[color[2]])