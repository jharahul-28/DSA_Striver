vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> answer;
    int top = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1, left = 0, num = 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            answer.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            answer.push_back(matrix[i][right]);
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                answer.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                answer.push_back(matrix[i][left]);
            left++;
        }
    }
    return answer;
}