class Solution {
    public String capitalizeTitle(String title) {
        String[] words = title.split(" ");
        StringBuilder res = new StringBuilder();
        boolean isFirst = true;
        for(var x: words) {
            if(!isFirst)
                res.append(" ");
            if(x.length() < 3)
                res.append(x.toLowerCase());
            else {
                res.append((x.charAt(0) + "").toUpperCase()).append(x.substring(1, x.length()).toLowerCase());
            }
            isFirst = false;
        }
        return res.toString();
    }
}
