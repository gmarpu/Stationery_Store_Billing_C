#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void custob()
{

char iname[20],date[40],ch1='y',ch2='y',pro[100];
float rate,cost=0.0,total=0.0,c[100];
int bill,sno=0,quantity,q[100],item,i;
FILE *fp; 
fp=fopen("store.c","r"); 
while(ch1=='y')
{
printf("ENTER CUSTOMER'S NAME:");
scanf("%s",&iname);
printf("\nENTER BILL NUMBER: ");
scanf("%d",&bill);
printf("\nENTER DATE: ");
scanf("%s",&date);
printf("\nENTER  THE item: ");
printf("\nPLEASE\nPRESS 1 FOR PEN \nPRESS 2 FOR pencil \nPRESS 3 FOR eraser \nPRESS 4 FOR scale \nPRESS 5 FOR notebook\n ");
ch2='y';

while(ch2=='y')
{
printf("\nENTER YOUR CHOICE :");
scanf("%d",&item);

switch(item)
{
//case to calculate cost quantity and total
case 1:
printf("\nENTER QUANTITY: ");
scanf("%d",&quantity);
rate=20;
cost=quantity*20;
sno++;
c[sno]=cost;
total=total+cost;
pro[sno]=item;
q[sno]=quantity;
break;
//case to calculate cost quantity and total
case 2:
printf("\nENTER QUANTITY:");
scanf("%d",&quantity);
rate=5;
sno++;
cost=quantity*5;
c[sno]=cost;
total=total+cost;
pro[sno]=item;
q[sno]=quantity;
break;
//case to calculate cost quantity and total
case 3:
printf("\nENTER QUANTITY:");
scanf("%d",&quantity);
rate=30;
sno++;
cost=quantity*30;
c[sno]=cost;
total=total+cost;
pro[sno]=item;
q[sno]=quantity;
c[sno]=cost;
break;
//case to calculate cost quantity and total
case 4:
printf("\nENTER QUANTITY:");
scanf("%d",&quantity);
rate=10;
sno++;
cost=quantity*10;
c[sno]=cost;
total=total+cost;
pro[sno]=item;
q[sno]=quantity;
break;
//case to calculate cost quantity and total
case 5:
printf("\nENTER QUANTITY:");
scanf("%d",&quantity);
rate=15;
sno++;
cost=quantity*15;
c[sno]=cost;
total=total+cost;
pro[sno]=item;
q[sno]=quantity;
break;
default:
printf("\nINVALID RESPONSE!");
} //end of switch
printf(" \nANY MORE item PRESS 'y' AND 'n' FOR NO");
fflush(stdin);
scanf("%c",&ch2);
}
//end of while loop
fclose(fp);


fp=fopen("store.c","app");

printf("\nCUSTOMER'S NAME:%s",iname);
printf("\tBILL NO.%d",bill);
printf("\nDATE%s",date);

printf("\nS NO.\tITEM\tRATE\tQUANTITY\tCOST");
for(i=1;i<=sno;i++) 
{
printf("\n%d",i);
if(pro[i]==1)
{
printf("\tPEN\t");
printf("20");
}
else if(pro[i]==2)
{
printf("\tPENCIL\t");
printf("5");
}
else if(pro[i]==3)
{
printf("\tERASER\t");
printf("30");
}
else if(pro[i]==4)
{
printf("\tSCALE\t");
printf("10");
}
else
{
printf("\tNOTEBOOK");
printf("15");
}
printf("\t%d",q[i]);
printf("\t\t%f",c[i]);
printf("\n");
}

printf("\nTOTAL%f",total); 
printf("\n");

printf("\nNEXT CUSTOMER");
printf("\nPRESS 'y' TO CONTINUE ");
fflush(stdin);
scanf("%c",&ch1);
//for loop to intailise all the variables to zero
for(i=1;i<=sno;i++)
{
pro[i]=0;
q[i]=0;
c[i]=0;
}

}

cost=0,total=0,quantity=0;
fclose(fp);

getch();
}
 
 
  typedef struct items
{
	int code;
	char name[30];
	int quantity;
	struct items *link;
}node;

node *header=NULL;
node *get_node()
{
	return((node *)malloc(sizeof(node)));
}

void insert()
{
	int code,quantity;
	char name[30];
	node *p;
	printf("\nEnter code\n : ");
	scanf("%d",&code);
		printf("Enter Name\n : ");
	scanf("%s",name);
		printf("Enter Quantity\n : ");
	scanf("%d",&quantity);
	p=get_node();
	p->code=code;
	p->quantity=quantity;
	strcpy(p->name,name);
	p->link=NULL;
	if(header==NULL)
		header=p;
	else
	{
		p->link=header;
		header=p;
	}
}

void del()
{
	node *temp;
	int key;
	int code;
	printf("enter the code of the item  to be deleted");
	scanf("%d",&code);
	if(header==NULL)
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		for(temp=header;temp!=NULL;temp=temp->link)
	{
	
		 if(code==temp->code)
		 {
		 
		temp=header;
		header=header->link;
		printf("The following record is deleted : %d %s %d\n",temp->code,temp->name,temp->quantity);
		free(temp);
	}
	}
}
}


void display()
{
	node *temp;
	printf("code   Name      quantity\n");
	for(temp=header;temp!=NULL;temp=temp->link)
	printf("%-4d %-10s %d\n",temp->code,temp->name,temp->quantity);
}
	
void search()
{
	int code;
	node *temp;
	printf("Enter the code of items to be searched : ");
	scanf("%d",&code);
	for(temp=header;temp!=NULL;temp=temp->link)
	{
		if(code==temp->code)
		{
			printf("code   Name      quantity\n");
			printf("%-4d %-10s %d\n",temp->code,temp->name,temp->quantity);
			return;
		}
	}
	printf("items Record Not Found !!!\n");
}


void menu()
{
	int choice;
		printf("\nChoose :\n1 - Insert items Record\n2 - Delete items Record\n3 - Search items Record\n4 - Display items Records\nPress any other key to EXIT !\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 : insert();break;
		case 2 : del();break;
		case 3 : search();break;
		case 4 : display();break;
		default : exit(0);break;
		}
}

int admin()
{
	for(;;) 
	{
		menu();
	}
	return 0;
}

void main()
{
  
  char username[20];
  char userpwd[8]; 
  int i;
  
  printf("Enter your username : ");
  scanf("%s",username);
  if(!strcmp(username,"admin"))
  {
    printf("Enter your password : "); 
  for(i=0;i<9;i++)
  {
   userpwd[i]=getch();
   printf("*");   	
  }
  userpwd[i]='\0';
 if(!strcmp(username,"admin") && !strcmp(userpwd,"admin@123"))
 {
  printf("\n\nLogged In Successful"); 
  
  admin();
 }
 
 
  else
 {
  printf("\n\nIncorrect username or password");
 }
}
 else if(!strcmp(username,"bstaff"))
  {
    printf("Enter your password :\n "); 
  for(i=0;i<10;i++)
  {
   userpwd[i]=getch();
   printf("*");   	
  }
  userpwd[i]='\0';
 if(!strcmp(username,"bstaff") && !strcmp(userpwd,"bstaff@123"))
 {
  printf("\n\nLogged In Successful\n"); 
 
  custob();
 }
 
 
  else
 {
  printf("\n\nIncorrect username or password");
 }
}

  getch();
  	
  }

