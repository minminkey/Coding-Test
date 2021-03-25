function solution(cacheSize, cities) {
    var answer = 0;
    let cache = [];
    cities = cities.map(city=>city.toLowerCase());
    if(cacheSize===0)   return cities.length*5;
    for(let i = 0; i<cities.length; i++){
        let now = cities[i];
        let idx = cache.indexOf(now);
        if(idx>-1){
            cache.splice(idx, 1);
            answer += 1;
        }
        else{
            if(cache.length === cacheSize)  cache.shift();
            answer += 5;
        }
        cache.push(now);
    }
    return answer;
}