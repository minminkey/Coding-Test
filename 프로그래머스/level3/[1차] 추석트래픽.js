function solution(lines) {
    var answer = 0;
    let times = lines.map(line=>{
        let t = line.split(' ');
        let m = t[1].split(':');
        let end = Number(m[0])*3600+Number(m[1])*60+Number(m[2]);
        let start = +(end - Number(t[2].slice(0, -1)) + 0.001).toFixed(3);
        return [start, end];
    });
    let idx = 0;
    times = times.sort((a,b)=>a[1]-b[1]);
    times.forEach(time=>{
        let s = time[1];
        let e = +(s+1-0.001).toFixed(3);
        let cnt = 0;
        idx++;
        for(let i=0; i<times.length; i++){
            if((times[i][0]>=s&&times[i][0]<=e)||(times[i][1]>=s&&times[i][1]<=e)||(times[i][0]<=s&&times[i][1]>=e)){
                cnt++;
            }
        }
        answer = Math.max(answer, cnt);
    })
    return answer;
}