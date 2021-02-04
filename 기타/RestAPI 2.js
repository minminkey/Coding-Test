const request = require('request');

function myFetch(url) {
  return new Promise((resolve, reject) => {
    request(url, function (error, response, body) {
      if(error) reject(error)

      else resolve(body)
    });
  });
}
async function homeFetch(url, team, year, competition){
    console.log(team, year);
    let totalGoal = 0;
    const rawhome = await myFetch(url);
    const home = JSON.parse(rawhome)
    let t=home.total;
    for(let i=1; i<=home.total_pages; i++){
        const rawpage = await myFetch(`${url}&page=${i}`);
        const page = JSON.parse(rawpage);
        const data = page.data;
        let target = Math.min(t, Math.min(page.per_page,page.total));
        for(let j=0; j<target; j++){
            t--;
            if(data[j].competition!=competition) continue;
            if(data[j].team1===team){
                totalGoal += parseInt(data[j].team1goals);
            }
            else{
                totalGoal += parseInt(data[j].team2goals);
            }
        }
    }
    return totalGoal;
}
async function getWinnerTotalGoals(competition, year) {
    const rawcompInfo = await (myFetch(`https://jsonmock.hackerrank.com/api/football_competitions?name=${competition}&year=${year}`));
    const compInfo = JSON.parse(rawcompInfo);
    const winner = compInfo.data[0].winner;
     let totalGoal = 0;
    totalGoal += await homeFetch(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1=${winner}`, winner, year, competition);
    totalGoal += await homeFetch(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team2=${winner}`, winner, year, competition);
    return totalGoal;
}