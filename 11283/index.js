const fs = require('fs');
const s = fs.readFileSync('/dev/stdin', 'utf8');
console.log(s.charCodeAt(0) - '가'.charCodeAt(0) + 1);
