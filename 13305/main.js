const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString();
const lines = input.split('\n');
const N = Number(lines[0]);
const dist = lines[1].split(' ').map(v => BigInt(v));
const price = lines[2].split(' ').map(v => BigInt(v));
let min_price = 1000000001n;
let sum = 0n;
for (let i = 0; i < N - 1; i++) {
    min_price = price[i] < min_price ? price[i] : min_price;
    sum += min_price * dist[i];
}
console.log(sum.toString());
