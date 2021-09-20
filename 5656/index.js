const fs = require('fs')
const lines = fs.readFileSync('/dev/stdin', 'utf8').split('\n')
for (let i = 0; i < lines.length; i++) {
    if (lines[i].includes('E')) break;
    console.log(`Case ${i + 1}: ${eval(lines[i])}`)
}