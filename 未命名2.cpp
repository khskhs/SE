#include<iostream>
#include<algorithm>
#include <ctime>
using namespace std;
 
int Initial_State [ 10 ] [ 10 ] ; 
 
bool get_Initial_State( int i , int j  )  //�����ڣ� i , j ��λ�ô����Դ洢������,�ҵ����򷵻�true�����򷵻�false
{
    if( i > 9 || j > 9 ) 
        return true;
 
    for( int k = 1 ; k <= 9 ; ++k ) 
    {
        bool can = true;                // can �������ڼ�¼����k�ܷ���� ( i , j ) �� 
        for( int m = 1 ; m < i ; ++m ) 
            if( Initial_State[m][j] == k )  // ���ͬһ���Ƿ���ֹ�����k
            {
                can = false ;
                break ;
            }
        if ( can ) 
            for( int n = 1 ; n < j ; ++n ) 
                if( Initial_State[i][n] == k )  // ���ͬһ���Ƿ���ֹ�����k
                {
                    can = false ;
                    break; 
                }
        if( can ) 
        {
            int up1 = ( i/3 ) * 3 + 3 ; // (i,j)�������ڵ�3��3С����i���������
            int up2 = ( j/3 ) *3 + 3;   // (i,j)�������ڵ�3��3С������j���������
 
            if( i % 3 == 0 )    //���������������Ĵ���
                up1 = i ; 
            if( j % 3 == 0 ) 
                up2 = j ;
 
            for( int p = up1-2 ; p <= up1 ; ++p  )  /* �����3��3��С�������Ƿ������ͬһ������ */
            {
                if( can == false )   /* �������ѭ�� */
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
                if( get_Initial_State( i  , j +1 ) )   /* ��ͬһ�е���һλ�ÿ�ʼ���� */
                    return true ;  
            }
            else
            {
                if( i < 9 )  
                {
                    if( get_Initial_State( i + 1 , 1 ) )    /* ����һ�еĵ�һ���ո�ʼ���� */
                        return true ;
                }
                else
                    return true ;  /* i >= 9  && j >= 9  , �������� */
 
            }
            Initial_State[i][j] = 0 ;   /* �ؼ���һ�����Ҳ������Ҫ�ظ�ԭ״��������������������Ӱ�� */
        }
    }
    return false ;  /*  1��9�����Թ������У��򷵻صݹ����һ�� */
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
 
int main()
{
	int N,M;
	cin>>N;
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
