const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8');
const sum = input.split(' ').map(v => +v).reduce((pre, cur) => pre + cur, 0);
console.log(sum);
