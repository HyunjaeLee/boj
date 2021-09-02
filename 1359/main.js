const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8');
const [N, M, K] = input.split(' ').map(v => +v);
const combination = function(n, r) {
    if (n < r) return 0;
    if (n - r < r) return combination(n, n-r);
    if (r == 0) return 1;
    let numerator = 1;
    let denominator = 1;
    for (let i = 0; i < r; i++) {
        numerator *= n - i;
        denominator *= r - i;
    }
    return numerator / denominator;
};
let numerator = 0;
let denominator = combination(N, M);
for (let i = 0; i <= M - K; i++) {
    numerator += combination(M, K+i) * combination(N-M, M-K-i);
}
console.log(numerator/denominator);
