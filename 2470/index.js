const fs = require('fs');
const lines = fs.readFileSync('/dev/stdin', 'utf8').split('\n');
const N = +lines[0];
const arr = lines[1].split(' ').map(v => +v).sort((a, b) => a - b);
let left = 0;
let right = N - 1;
let min = 2_000_000_001;
let ans1, ans2;
while (left < right) {
    const sum = arr[left] + arr[right];
    const abs = Math.abs(sum);
    if (abs < min) {
        min = abs;
        ans1 = arr[left];
        ans2 = arr[right];
    }
    if (sum < 0) {
        left++;
    } else if (sum > 0) {
        right--;
    } else {
        break;
    }
}
console.log(`${ans1} ${ans2}`);
