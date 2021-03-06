class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int n = words.length;
        boolean flag = word1.equals(word2);
        int l = -1, f = 0;
        int min = n - 1;
        for(int i = 0; i < n; i++){
            if(words[i].equals(word1)){
                if(flag){
                    if(l != -1) min = Math.min(min, i - l);
                    l = i;
                    continue;
                }
                if(l == -1) l = i;
                else{
                    if(f == 2) min = Math.min(min, i - l);
                    l = i;
                }
                f = 1;
            } else if(words[i].equals(word2)){
                if(l == -1) l = i;
                else{
                    if(f == 1) min = Math.min(min, i - l);
                    l = i;
                }
                f = 2;
            }
        }
        
        return min;
    }
}
