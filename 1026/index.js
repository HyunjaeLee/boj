const fs = require('fs');
const lines = fs.readFileSync('/dev/stdin', 'utf8').split('\n');
const N = +lines[0]
const A = lines[1].split(' ').map(v => +v).sort((a, b) => a - b)
const B = lines[2].split(' ').map(v => +v).sort((a, b) => b - a)
let S = 0;
for (let i = 0; i < N; i++) {
    S += A[i] * B[i]
}
console.log(S)