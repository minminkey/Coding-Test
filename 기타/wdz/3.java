import java.util.Stack;

class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        for(int i=0; i<arr.length; i++){
            int top = stack.peek();
            if(top<arr[i]){
                answer++;
                stack.push(arr[i]);
            }
            else if(top>arr[i]){
                while(top>arr[i]){
                    stack.pop();
                    top = stack.peek();
                }
                if(top<arr[i]){
                    answer++;
                    stack.push(arr[i]);
                }
            }
        }
        return answer;
    }
}