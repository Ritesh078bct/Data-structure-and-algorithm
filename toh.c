#include<stdio.h>
void toh(int n, char s,char d, char a)
{
    if(n==1){

        printf("Move disk %d from %c to %c\n",n,s,d);
    }else{

    toh(n-1,s,a,d);
    printf("Move disk %d from %c to %c\n",n,s,d);
    toh(n-1,a,d,s);    
    }
}
int main()
    {
        int n=3;
        char source='A',destination='C',auxiliary='B';
        toh(n,source,destination,auxiliary);
        return 0;
    }