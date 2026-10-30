#include<stdio.h>
#define N 9
int isRowValid(int board[N][N]){
int i,j,seen[0];
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      int val=board[i][j];
      if(val!=0){
        if(seen[val])
          return 0;
          seen[val]=1;
      }
   }
}
return 1;
}
int isColValid(int board[N][N]){
  int i,j,seen[N+1];
  for(j=0;j<N;j++){
    for(i=0;i<=N;i++)
      seen[i]=0;
      for(i=0;i<N;i++){
        int val=board[i][j];
        if(val!=0){
          if(seen[val])
            return 0;
            seen[val]=1;
        }
     }
  }
return 1;
}
int isBoxValid(int board[N][N]){
  int r,c,i,j,seen[N+1];
  for(r=0;r<N;r+=3){
    for(c=0;c<N;c+=3){
      for(i=0;i<=N;i++)
        seen[i]=0;
        for(i=r;i<r+3;i++){
          for(j=c;j<r+3;j++){
            int val=board[i][j];
            if(val!=0){
              if(seen[val])
                return 0;
                seen[val]=1;
            }
         }
       }
    }
  }
return 1;
}
int main(){
  int board[N][N];
  int i,j;
  printf("enter the 9*9 sudoku board row by row(use 0 for empty cells):\n");
  for(i=0;i<N;i++)
  for(j=0;j<N;j++)
  scanf("%d",&board[i][j]);
  if(isRowValid(board)&&isColValid(board)&&isBoxValid(board))
  printf("Valid Sudoku Board\n");
  else
  printf("Invalid Sudoku Board\n");
  return 0;
}
