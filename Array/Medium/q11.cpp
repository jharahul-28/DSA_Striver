//brute
vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> answer [n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            answer[i][j]= matrix[j][n-1-i];
        }
    }
    return answer;
}

// optimal
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}