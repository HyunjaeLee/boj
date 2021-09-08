const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString();
const price = input.split('\n').map(v => +v);
const lowest = Math.min(price[0], price[1], price[2]) + Math.min(price[3], price[4]) - 50;
console.log(lowest);
