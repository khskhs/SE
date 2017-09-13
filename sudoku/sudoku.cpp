#include<iostream>
#include<algorithm>
#include <ctime>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
 
int Initial_State [ 10 ] [ 10 ] ; 
 
bool get_Initial_State( int i , int j  )  //搜索第（ i , j ）位置处可以存储的数字,找到解则返回true，否则返回false
{
    if( i > 9 || j > 9 ) 
        return true;
 
    for( int k = 1 ; k <= 9 ; ++k ) 
    {
        bool can = true;                // can 变量用于记录数字k能否放在 ( i , j ) 处 
        for( int m = 1 ; m < i ; ++m ) 
            if( Initial_State[m][j] == k )  // 检查同一列是否出现过数字k
            {
                can = false ;
                break ;
            }
        if ( can ) 
            for( int n = 1 ; n < j ; ++n ) 
                if( Initial_State[i][n] == k )  // 检查同一行是否出现过数字k
                {
                    can = false ;
                    break; 
                }
        if( can ) 
        {
            int up1 = ( i/3 ) * 3 + 3 ; // (i,j)方格所在的3×3小方格i坐标的上限
            int up2 = ( j/3 ) *3 + 3;   // (i,j)方格所在的3×3小方格在j坐标的上限
 
            if( i % 3 == 0 )    //这是针对特殊情况的处理
                up1 = i ; 
            if( j % 3 == 0 ) 
                up2 = j ;
 
            for( int p = up1-2 ; p <= up1 ; ++p  )  /* 检查在3×3的小方格中是否出现了同一个数字 */
            {
                if( can == false )   /* 跳出外层循环 */
                    break ;
                for( int q = up2-2 ; q <= up2 ; ++q ) 
                    if( Initial_State[p][q] == k ) 
                    {
                        can = false ;
                        break ;
                    }
            }
        }
        if( can ) 
        {
            Initial_State[i][j] = k ; 
            if( j<9 ) 
            {
                if( get_Initial_State( i  , j +1 ) )   /* 到同一行的下一位置开始搜索 */
                    return true ;  
            }
            else
            {
                if( i < 9 )  
                {
                    if( get_Initial_State( i + 1 , 1 ) )    /* 到下一行的第一个空格开始搜索 */
                        return true ;
                }
                else
                    return true ;  /* i >= 9  && j >= 9  , 搜索结束 */
 
            }
            Initial_State[i][j] = 0 ;   /* 关键这一步：找不到解就要回复原状，否则会对下面的搜索造成影响 */
        }
    }
    return false ;  /*  1到9都尝试过都不行，则返回递归的上一步 */
}
 
void start() 
{
    
    for( int i = 1  ; i <= 9 ; ++i )
        for( int j = 1 ; j <= 9 ; ++j )
            Initial_State[i][j] = 0 ;
 
    
    
    int a[10];
    int c;
	for(c=0;c<=9;c++)
		a[c]=c; 
 	a[6]=0;
 	Initial_State[1][1] = 6 ;
 	int b;
 	for(c=2;c<=9;c++)
 	{
 		b=rand() % 9 + 1;
 		if(a[b]!=0)
 		{
 			Initial_State[1][c] =a[b];
 			a[b]=0;
		 }
		 else c--;
	 }
 	
    get_Initial_State( 2 , 1 ) ;  
}
 
int main(int argc,char* args[])
{
	
	int M;
	//cin>>N;
	freopen("sudoku.txt", "w", stdout);
	if (argc!= 3 || strcmp(args[1],"-c") != 0)
	{
		cout << "请输入正确参数!!" << endl;
		return 0;
	}
	for (int i = 0; i < strlen(args[2]); i++)
	{
		if (args[2][i] <= '9' && args[2][i] >= '0')
			continue;
		else
		{
			cout << "请输入正确参数!!" << endl;
			return 0;
		}
	}
	string str(args[2]);
	int N = std::atoi(str.c_str());
	//printf("参数正确，开始生成%d个数独\n", N);

	for(M=0;M<N;M++)
	{
		
		start( );
	    for( int i = 1 ; i <= 9 ; ++ i ) 
	    {
	        for( int j = 1 ; j <= 9 ; ++j ) 
	            cout<< Initial_State [i][j] <<" " ;
	        cout<<endl;
	        
	    }
	    cout<<endl;
	}
    
    
}
