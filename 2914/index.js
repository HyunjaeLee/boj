const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString();
const [A, I] = input.split(' ').map(v => +v);
console.log(A * (I - 1) + 1);
