#include<bits/stdc++.h>
using namespace std;
int32_t main(){

        int t,i,j,n;
        t=10;j=1;i=0;
        while(t--){
        FILE *f,*o;
        f=fopen("input.txt","w+");
        int x=rand()%1000000001;
        fprintf(f,"%d",x);
        fclose(f);
        system("g++ -o code.exe code.cpp");
        system("code.exe < input.txt > tmout.txt");
        o=fopen("tmout.txt","r+");
        //printf("%d\n",x);

        int y=x*x;
        int d;
        fscanf(o,"%d",&d);
        fclose(o);
        if(d==y)
        {
                printf("Test Case Passed %d\n",j++);i++;
        }
        else printf("Wrong Answer %d\n",j++);}
        if(i==10)printf("Accepted");

return 0;
}