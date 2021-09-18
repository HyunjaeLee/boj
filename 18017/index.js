const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8');
const [A, B] = input.split(' ').map(v => +v)
const c = 299792458
console.log((A + B) / (1 + (A * B) / (c * c)))