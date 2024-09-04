#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	clrscr();
	srand(time(NULL));
	int i,r,w,n,a,b,ans,sol;
	r = 0; w = 0;a=0;b=0;ans=0;sol=0;
	printf("How many questions do you want?? ");
	scanf("%d",&n);
	for(i=0;i<n;i+=1){
	a=rand()%50;
	b=rand()%50;
	sol = a+b;
	printf("what is %d + %d ? ",a,b);
	scanf("%d",&ans);
	if(ans == sol)
	r += 1;
	else
	w += 1;
	}
	printf("\nNumber of\nRight answers :%d\tWorng answers:%d",r,w);
	getch();
	return 0;
}