const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString();
const regex = /^(-?[0-9]*)x/;
const res = input.match(regex);
if (res) {
    if (res[1] === '') {
        console.log('1');
    } else if (res[1] === '-') {
        console.log('-1');
    } else {
        console.log(res[1]);
    }
} else {
    console.log('0');
}
