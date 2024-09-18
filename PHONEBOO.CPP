#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int cno;
	char cmobile[11];
	char cname[41];
	int fav;
	struct node *link;
};
int custCount = 0;
struct node *head = NULL;
void addCust(char Cname[41],char Cmobile[11]){
	struct node *NewCust = (struct node *) malloc(sizeof(struct node));
	struct node *tmp;
	tmp = head;
	if(tmp==NULL){
		NewCust->cno = ++custCount;
		strcpy(NewCust->cname,Cname);
		NewCust->fav = 0;
		strcpy(NewCust->cmobile,Cmobile);
		NewCust->link = NULL;
		head = NewCust;
	}
	else{
		while(tmp->link != NULL)
			tmp = tmp->link;
		NewCust->cno = ++custCount;
		strcpy(NewCust->cname,Cname);
		NewCust->fav = 0;
		strcpy(NewCust->cmobile,Cmobile);
		tmp->link = NewCust;
		NewCust->link = NULL;
	}
}
void showBook(){
	struct node *tmp;
	tmp = head;
	while(tmp != NULL){
		printf("--------------------\n");
		printf("Customer number :        %d\n",tmp->cno);
		printf("Customer name :          %s\n",tmp->cname);
		printf("Customer mobile number : %s\n",tmp->cmobile);
		printf("--------------------\n");
		tmp = tmp->link;
	}
}
void cSearch(int Cno){
	struct node *tmp;
	tmp = head;
	while(!(tmp==NULL || tmp->cno == Cno))
		tmp = tmp->link;
	if(tmp != NULL){
		tmp->fav +=1;
		printf("--------------------\n");
		printf("Coustomer Found!!\n");
		printf("Customer number :        %d\n",tmp->cno);
		printf("Customer name :          %s\n",tmp->cname);
		printf("Customer mobile number : %s\n",tmp->cmobile);
		printf("Times searched : %d\n",tmp->fav);
		printf("--------------------\n");

	}
	else{
		printf("Customer Not Found!!");
	}
}
void favCust(){
	struct node *tmp;
	struct node *favorate;
	favorate = head;
	tmp = head;
	int max;
	max = 1;
	while(tmp->link != NULL){
		if(favorate->fav >= tmp->fav){
			max = favorate->cno;
			favorate = tmp;
		}
		tmp = tmp->link;
	}
	printf("---------------------\n");
	printf("Favorate customer found!!\n");
	printf("Customer number : %d\n",max);
	printf("Customer name : %s\n",favorate->cname);
	printf("Customer mobile number : %s\n",favorate->cmobile);



}
int main(){
	clrscr();
	addCust("Amrit","9832925259");
	addCust("Mummy","8653307044");
	addCust("Hello","0123456789");
	showBook();
	cSearch(2);
	favCust();
	getch();
	return 0;
}