function solution(gift_cards, wants) {
    var answer = 0;
    let cardNum = new Array(100010).fill(0);
    gift_cards.forEach(card=>{
        cardNum[card]++;
    });
    wants.forEach(want=>{
        if(cardNum[want]>0){
            cardNum[want]--;
        }
        else{
            answer++;
        }
    })
    return answer;
}