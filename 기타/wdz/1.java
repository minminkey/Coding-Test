import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(int[][] passwords, String s) {
        int answer = 0;
        Map<Integer, Integer> passwordMap = new HashMap<>();
        for(int i=0; i<passwords.length; i++){
            passwordMap.put(passwords[i][0], passwords[i][1]);
        }
        String word = "";
        int flag = 0;
        int next = -1;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '#'){
                if(flag == 0){
                    int now = Integer.parseInt(word);
                    if(passwordMap.get(now) == null){
                        flag = 0;
                    }
                    else{
                        next = passwordMap.get(now);
                        flag = 1;
                    }
                    word = "";
                }
                else if(flag == 1){
                    int now = Integer.parseInt(word);
                    if(now == next){
                        answer++;
                    }
                    flag = 0;
                    word = "";
                }
            }
            else{
                word += s.charAt(i);
            }
        }
        return answer;
    }
}