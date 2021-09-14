const fs = require('fs');
const lines = fs.readFileSync('/dev/stdin', 'utf8').split('\n');
const [N, M] = lines[0].split(' ').map(v => + v);
const list = [];
for (let i = 1; i <= N; i++) {
    list[i] = [];
}
for (let i = 1; i <= M; i++) {
    const [u, v] = lines[i].split(' ').map(v => +v);
    list[u].push(v);
    list[v].push(u);
}
const visited = [];
const bfs = function (v) {
    const queue = [];
    queue.push(v);
    visited[v] = true;
    while (queue.length > 0) {
        cur = queue.shift();
        for (const next of list[cur]) {
            if (visited[next]) continue;
            queue.push(next);
            visited[next] = true;
        }
    }
}
let count = 0;
for (let i = 1; i <= N; i++) {
    if (visited[i]) continue;
    count++;
    bfs(i);
}
console.log(count);
