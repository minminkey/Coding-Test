import java.util.ArrayList;
import java.util.List;

class Node {
    public int live;
    public String[] str;

    public Node() {
        this.live = 0;
        this.str = new String[30];
        for(int i=0; i<27; i++){
            str[i] = "";
        }
    }
}

class Solution {
    public String[] solution(String[] code) {
        List<String> ans = new ArrayList<String>();
        int ansIdx = 0;
        Node[] node = new Node[30];
        int prev = -1;
        for(int i=0; i<code.length; i++){
            int now = 0;
            for(int j=0; j<code[i].length(); j++){
                if(code[i].charAt(j)!='.'){
                    if(prev < now){
                        node[now] = new Node();
                    }
                    else if(prev > now){
                        for(int idx=prev; idx>now; idx--){
                            node[idx] = null;
                        }
                    }
                    prev = now;
                    if(code[i].charAt(j) == 'p'){
                        char key = code[i].charAt(j+6);
                        int flag = 0;
                        for(int idx = now; idx>=0; idx--){
                            if(node[idx] == null)   continue;
                            if(node[idx].str[key - 'a'] == "")  continue;
                            else{
                                ans.add(node[idx].str[key - 'a']);
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 0){
                            ans.add("error");
                        }
                    }
                    else{
                        char key = code[i].charAt(j);
                        String value = code[i].substring(j);
                        node[now].str[key-'a'] = value;
                    }
                    break;
                }
                else    now++;
            }
        }
        String[] answer = new String[ans.size()];
        int size=0;
        for(String temp : ans){
            answer[size++] = temp;
        }
        return answer;
    }
}