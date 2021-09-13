const fs = require('fs');
const crypto = require('crypto');
const S = fs.readFileSync('/dev/stdin').toString().trim();
console.log(crypto.createHash('ripemd160').update(S).digest('hex'));
