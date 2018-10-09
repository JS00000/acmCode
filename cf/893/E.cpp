#include <cstdio>

int factor[109];
int time[109];
int Prime_Factors(int x)
{
     int fatCnt=0;
     int temp=x;
     for( int i = 2; i <= temp / i; i++ )
     {
        if ( temp % i == 0 )
         {
            fatCnt++;
            factor[fatCnt] = i;
            while( temp % i == 0 )
            {
                time[fatCnt]++;
                temp /= i;
            }
         }  
     }
     if(temp!=1)
     {
         factor[++fatCnt] = temp;
         time[fatCnt] = 1;
     }
     return fatCnt;
}

int main()
{

    return 0;
}
