function solution(line) {
    const N = line.length;
    const INF = Number.MAX_SAFE_INTEGER;
    const crossPoints = [];
    let minX = INF;
    let minY = INF;
    let maxX = -INF;
    let maxY = -INF;

    for (let i = 0; i < N - 1; i++) {
        for (let j = i + 1; j < N; j++) {
            const [a, b, e] = line[i];
            const [c, d, f] = line[j];

            const mod = a * d - b * c;
            if (!mod) continue; 
            const xNumerator = b * f - e * d;
            const yNumerator = e * c - a * f;
            if (xNumerator % mod || yNumerator % mod) continue;

            const x = xNumerator / mod;
            const y = yNumerator / mod;

            crossPoints.push([x, y]); 
            minX = Math.min(minX, x); 
            minY = Math.min(minY, y);
            maxX = Math.max(maxX, x);
            maxY = Math.max(maxY, y);
        }
    }

    const paper = [...Array(maxY - minY + 1)].map(() => [...Array(maxX - minX + 1)].map(() => '.'));

    crossPoints.forEach(([x, y]) => {
        paper[maxY - y][x - minX] = '*';
    });

    return paper.map(v => v.join(''));
}