/*
 * Complete the 'getTotalGoals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING team
 *  2. INTEGER year
 */
const request = require('request');

function myFetch(url) {
  return new Promise((resolve, reject) => {
    request(url, function (error, response, body) {
      if(error) reject(error)

      else resolve(body)
    });
  });
}
async function homeFetch(url, team, year){
    console.log(team, year);
    let totalGoal = 0;
    const rawhome = await myFetch(url);
    const home = JSON.parse(rawhome)
    let t=home.total;
    // console.log(home);
    for(let i=1; i<=home.total_pages; i++){
        // if(t<=0) break;
        const rawpage = await myFetch(`${url}&page=${i}`);
        const page = JSON.parse(rawpage);
        // console.log(page);
        // console.log(i);
        const data = page.data;
        let target = Math.min(t, Math.min(page.per_page,page.total));
        for(let j=0; j<target; j++){
            console.log(data[j]);
            t--;
            console.log(data[j].team1, team);
            if(data[j].team1===team){
                totalGoal += parseInt(data[j].team1goals);
            }
            else{
                totalGoal += parseInt(data[j].team2goals);
            }
            console.log(totalGoal);
        }
    }
    return totalGoal;
}
async function getTotalGoals(team, year) {
    let totalGoal = 0;
    totalGoal += await homeFetch(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1=${team}`, team, year);
    totalGoal += await homeFetch(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team2=${team}`, team, year);
    console.log(totalGoal);
    return totalGoal;
}