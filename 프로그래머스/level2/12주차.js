function solution(k, dungeons) {
    if (dungeons.length <= 0) return 0;

    let maxDungeons = 0;
    for (let i = 0; i < dungeons.length; i++) {
        if (k >= dungeons[i][0]) {
            let n = solution(
                k - dungeons[i][1], 
                dungeons.slice(0, i).concat(dungeons.slice(i + 1))
            );
            if (n + 1 > maxDungeons) {
                maxDungeons = n + 1;
            }

            if (maxDungeons >= dungeons.length) return maxDungeons;
        }
    }

    return maxDungeons;
}