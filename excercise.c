#include<stdio.h>
#include<string.h>
#define N strlen(g)
#include<stdlib.h>
#include<conio.h>
#include <math.h>

#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[30];
char tnew[28];
char arr1[1024];
int arr1c[1024];
int a,e,c;
int flag;
void exor()
{
for(c = 1;c < N; c++)
cs[c] = (( cs[c] == g[c])?'0':'1');
}
void crc()
{
for(e=0;e<N;e++) cs[e]=t[e];
do{
if(cs[0]=='1') exor();
for(c=0;c<N-1;c++)
cs[c]=cs[c+1];
cs[c]=t[e++];
}while(e<=a+N-1);
}
int main()
    { char choice;
    printf("\n.....YOUR OPTIONS....\n");
    printf("\na.CRC\n b.Hamming\n");
    printf("\nEnter your choice:");
    scanf("%c",&choice);
    switch(choice)
    {
    case'a':
        {
            printf("\nEnter data : ");
            scanf("%s",t);
            printf("\n----------------------------------------");
            printf("\nEnterGenerating polynomial in binary : ");
            scanf("%s",g);
            a=strlen(t);
            for(e=a;e<a+N-1;e++) t[e]='0';
            printf("\n----------------------------------------");
            printf("\nAugmenteddataword : %s",t);
            printf("\n----------------------------------------");
            crc();
            printf("\nChecksum is : %s",cs);
            for(e=a;e<a+N-1;e++) t[e]=cs[e-a];
            printf("\n----------------------------------------");
            printf("\nFinalcodeword is : %s",t);
            printf("\n----------------------------------------\n\n");

            printf("\n Retreiving the data from---> %s \n", t);

            crc();
            int me = strlen(cs);
            for (int h=0; h<me; h++)
            {
                if (cs[h]='0')
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            printf("\n flag is  %d \n", flag);
            int st= strlen(t);
            if (flag==1)
            {
               for(int hh=0; hh<st-me;hh++)
               {
                   tnew[hh]=t[hh];
               }
            }
             printf("\n data is  %s \n", tnew);

        }
    case 'b':
        {   int con1;
            printf("\n Enter the data received \n");
            scanf("%s",arr1);
            int m1=strlen(arr1);
            for (int i=0; i<m1; i++)
            {
                if (arr1[i]=='1') arr1c[i]=1;
                else arr1c[i]=0;
            }
            int c1 = arr1c[10]^arr1c[8]^arr1c[6]^arr1c[4]^arr1c[2]^arr1c[0];
            int c2 = arr1c[9]^arr1c[8]^arr1c[5]^arr1c[4]^arr1c[0]^arr1c[1];
            int c3 = arr1c[7]^arr1c[4]^arr1c[5]^arr1c[6];
            int c4 = arr1c[3]^arr1c[0]^arr1c[1]^arr1c[2];
            int c = c4*8+c3*4+c1*2+c1;

            if (c==0)
            {
                printf("\n Received data successfully \n");
                printf("\n data is %d %d %d %d %d %d %d " ,arr1c[0],arr1c[1],arr1c[2],arr1c[4],arr1c[5],arr1c[6],arr1c[8]);
            }
            else
            {
                printf("there is error in the data at index from lsb: %d",c);
                if(arr1c[m1-c] == 0)
                {
                    arr1c[m1-c] = 1;
                    printf("\n correct data is %d %d %d %d %d %d %d " ,arr1c[0],arr1c[1],arr1c[2],arr1c[4],arr1c[5],arr1c[6],arr1c[8]);
                }
                else
                {
                    arr1c[m1-c] = 0;
                    printf("\n correct data is %d %d %d %d %d %d %d " ,arr1c[0],arr1c[1],arr1c[2],arr1c[4],arr1c[5],arr1c[6],arr1c[8]);
                }
            }
        }

    }

return 0;
}
