function solution(character, monsters) {
    var answer = '';
    let player = character.split(' ');
    let pHP = player[0];
    let pAttack = player[1];
    let pDefence = player[2];
    let info = monsters.map(monster => monster.split(' '));
    let point = 0;
    let time = 1;
    let target = "";
    info.forEach(m => {
        let name = m[0];
        let mPoint = m[1];
        let HP = m[2];
        let attack = m[3];
        let defence = m[4];
        let damage = pAttack - defence;
        let pDamage = attack - pDefence;
        if(damage > 0){
            let nowTime = 0;
            while(1){
                nowTime++;
                HP -= damage;
                if(HP<=0){
                    if(mPoint*time>point*nowTime){
                        point = mPoint;
                        time = nowTime;
                        target = name;
                    }
                    if(mPoint*time===point*nowTime){
                        if(mPoint>point){
                            point = mPoint;
                            time = nowTime;
                            target = name;
                        }
                    }
                    break;
                }
                if(pHP-pDamage<=0)   break;
            }
        }
    })
    answer = target;
    return answer;
}