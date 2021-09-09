const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString();
const lines = input.split('\n');
const K = +lines[0];
const coef = lines[1].split(' ').map(v => +v);
const [a, b, N] = lines[2].split(' ').map(v => +v);
const dx = (b - a) / N;
const f = x => {
    let val = 0;
    for (const c of coef) {
        val = val * x + c;
    }
    return val;
};
const sigma = epsilon => {
    let sum = 0;
    for (let i = 0; i < N; i++) {
        sum += f(a + i * dx + epsilon)
    }
    return sum * dx;
};
const integral = (() => {
    let val = 0;
    for (let i = 0; i <= K; i++) {
        val += coef[K - i] * (b ** (i + 1) - a ** (i + 1)) / (i + 1);
    }
    return val;
})();
let left = 0;
let right = dx;
let eps = -1;
for (let i = 0; i < 64; i++) {
    const mid = (left + right) / 2;
    const diff = integral - sigma(mid);
    if (diff > 0.0001) {
        left = mid;
    } else if (diff < -0.0001) {
        right = mid;
    } else {
        eps = mid;
        break;
    }
}
console.log(eps);
