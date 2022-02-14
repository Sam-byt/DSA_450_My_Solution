class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int sr = 0, sc =0, er =rows -1, ec=cols -1;
        
        vector<int> ans;
        
        int cnt=rows * cols;
        
        while(cnt>0)
        {
            for(int i = sc; i<=ec && cnt>0 ;i++){
                ans.push_back(matrix[sr][i]);
                cnt--;
            }
            sr++;
            
            for(int i = sr; i<=er && cnt>0 ;i++){
                ans.push_back(matrix[i][ec]); 
                cnt--;
            }
            ec--;
            
            for(int i = ec; i>=sc && cnt>0 ;i--){
                ans.push_back(matrix[er][i]);
                cnt--;
            }
            er--;
            
            for(int i = er; i>=sr && cnt>0 ;i--){
                ans.push_back(matrix[i][sc]); 
                cnt--;
            }
            sc++;
            
            
            
            
        }
        
        return ans;
        
    }
};
