class Solution {    
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            build(image, sr, sc, image[sr][sc], color);   
        return image;
    }
    
    private void build(int[][] image, int x, int y, int from_c, int to_c) {
        image[x][y] = to_c;
        if(x > 0 && image[x - 1][y] == from_c)
            build(image, x - 1, y, from_c, to_c);
        if(y > 0 && image[x][y - 1] == from_c)
            build(image, x, y - 1, from_c, to_c);
        if(x + 1 < image.length && image[x + 1][y] == from_c)
            build(image, x + 1, y, from_c, to_c);
        if(y + 1 < image[0].length && image[x][y + 1] == from_c)
            build(image, x, y + 1, from_c, to_c);
    }
}
