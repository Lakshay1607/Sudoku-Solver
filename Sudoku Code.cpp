bool issaferow(int board[][9],int row,int i)
{
    for(int j=0;j<9;j++)
    {
        if(board[row][j]==i)
        {
            return false;
        }
    }
    return true;
}
bool issafecolumn(int board[][9],int column,int i)
{
    for(int j=0;j<9;j++)
    {
        if(board[j][column]==i)
        {
            return false;
        }
    }
    return true;
}
bool issafebox(int board[][9],int row,int column,int i)
{
    int rowfactor=row-(row%3);
    int colfactor=column-(column%3);
    for(int j=0;j<3;j++)
    {
        for(int k=0;k<3;k++)
        {
            if(board[j+rowfactor][k+colfactor]==i)
            {
                return false;
            }
        }
    }
    return true;
}


bool issafe(int board[][9],int row,int column,int i)
{
    if(issaferow(board,row,i) && issafecolumn(board,column,i) && issafebox(board,row,column,i))
    {
        return true;
    }
    return false;
}
bool findelement(int board[][9],int &row,int &column)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                column=j;
                return true;
            }
        }
    }
    return false;
}
bool sudokuhelper(int board[][9])
{
    int row,column;
    if(!findelement(board,row,column))
    {
        return true;
    }
    
    for(int i=1;i<=9;i++)
    {
        if(issafe(board,row,column,i))
        {
            board[row][column]=i;
            if(sudokuhelper(board))
            {
                return true;
            }
            board[row][column]=0;
        }
    }
    return false;
}
bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    return sudokuhelper(board);
}
