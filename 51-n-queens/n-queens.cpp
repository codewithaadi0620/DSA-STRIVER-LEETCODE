class Solution {
public:
    vector<vector<string>> result;
    int N;
    bool isValid(vector<string>&boards,int row,int col){
        //LOOK UPWARD
        for(int i=row-1;i>=0;i--){
            if(boards[i][col]=='Q'){
                return false;
            }
        }
        //CHECK LEFT DIAGONAL UPWARD
        for(int i=row-1, j=col-1 ; i>=0 && j>=0; i--,j--){
            if(boards[i][j]=='Q'){
                return false;
            }
        }
        //CHECK right DIAGONAL UPWARD
        for(int i=row-1, j=col+1 ; i>=0 && j<N; i--,j++){
            if(boards[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>&boards,int row){
       
        if(row>=N){
            result.push_back(boards);
            return ;
        }

        for(int col=0; col<N;col++){
            if(isValid(boards,row,col)){
                boards[row][col]='Q';
                solve(boards,row+1);//Check all 4 Q able to place or not?
                boards[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
    vector<string>boards(n,string(n,'.'));//n->3 ("...","...","...")
       
    solve(boards,0);//row=0;
    return result;
    }
};