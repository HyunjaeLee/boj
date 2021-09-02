const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8');
const sum = input.split('\n').map(v => +v).reduce((pre, cur) => pre + cur, 0);
console.log(Math.floor(sum / 60));
console.log(sum % 60);
