class Solution {
    public boolean detectCapitalUse(String word) {
        return isAllCapital(word) || isAllSmall(word) || isFirstLetterCapital(word);
    }
    
    private boolean isAllCapital(String word) {
        for(int i = 0; i < word.length(); ++ i)
            if(word.charAt(i) > 96)
                return false;
        return true;
    }
    
    private boolean isAllSmall(String word) {
        for(int i = 0; i < word.length(); ++ i)
            if(word.charAt(i) < 97)
                return false;
        return true;
    }
    
    private boolean isFirstLetterCapital(String word) {
        if(word.charAt(0) > 96)
            return false;
        for(int i = 1; i < word.length(); ++ i) {
            if(word.charAt(i) < 97)
                return false;
        }
        return true;
    }
}
