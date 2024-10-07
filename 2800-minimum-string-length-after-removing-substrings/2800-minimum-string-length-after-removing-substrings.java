class Solution {
    public int minLength(String s) {
        Stack<Character> stk=new Stack<>();
        for(Character c:s.toCharArray()) {
            if(!stk.isEmpty() && (stk.peek()=='A' && c=='B' || stk.peek()=='C' && c=='D')) stk.pop();
            else stk.push(c);
        }
        return stk.size();
    }
}