const fs = require('fs');
const lines = fs.readFileSync('/dev/stdin', 'utf8').split('\n');
const n = +lines[0];
const seq = lines[1].split(' ').map(v => +v);
const x = +lines[2];
seq.sort((a, b) => a - b);
let left = 0;
let right = n - 1;
let count = 0;
while (left < right) {
    const sum = seq[left] + seq[right];
    if (sum < x) {
        left++;
    } else if (sum > x) {
        right--;
    } else {
        count++;
        left++;
        right--;
    }
}
console.log(count);
