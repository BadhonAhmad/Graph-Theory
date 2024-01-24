#include <iostream>
#include <vector>

using namespace std;

void dfs(int i, int j, int initialcolor, int newcolor, vector<vector<int>> &image)
{

    if (i < 0 || j < 0)
        return;

    if (i >= image.size() || j >= image[0].size())
        return;

    if (image[i][j] != initialcolor)
        return;

    image[i][j] = newcolor;

    dfs(i, j - 1, initialcolor, newcolor, image);
    dfs(i - 1, j, initialcolor, newcolor, image);
    dfs(i + 1, j, initialcolor, newcolor, image);
    dfs(i, j + 1, initialcolor, newcolor, image);
}
vector<vector<int>> Floodfill(vector<vector<int>> &image, int sr, int sc, int newcolor)
{
    int initialcolor = image[sr][sc];
    if (initialcolor != newcolor)
        dfs(sr, sc, initialcolor, newcolor, image);
    return image;
}
int main()
{
    
}