#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define price 2.0

//global definitions and declarations
struct customer {
	char id[10];
	char pass[10];
	char name[20];
	char no[13];
	int rides;
}a,c;
struct time {
	int hr;
	int m;
	int s;
}t;
    //function prototypes
void gettotal(void);
void databackup(void);
void greetings(void);
void process(void);
void print(struct customer * c);
void goxy(int y,int x);
float extratime(void);
float timeunit(void);
//main
int main() {
	//MAIN DECLARATIONS
	float unit1=0,unit2=0,cost=0;
	int opt;
	int fs;
	char location[20];
	char choice;
	char s[20];
	char temp[20];
	int f;
	FILE *fp;
	//GREETING FUNCTION IS CALLED
B:
	greetings();
	printf("---------------------------------------\"YOU WANT TO ENTERED AS A USER OR OWNER(U/O)\"-----------------------------------------\n");
	scanf("%c",&choice);
	fflush(stdin);
	system("cls");
	if(choice=='u'||choice=='U'){
		//process fn call
		process();
		//goxy fn call
		goxy(1,5);
		printf("\tSIGN UP OR SIGN IN?\n");
		gets(s);
		fflush(stdin);
		//SIGN UP CONDITION
		if(!(strcmp(s,"sign up"))) {
			
			
			//customer data inputs
C :
			printf("ENTER YOUR NU ID(##k-####)\n");
			fgets(c.id,10,stdin);
			fflush(stdin);
				c.id[strlen(c.id)-1]='\0';
				char ch[strlen(c.id)];
		FILE *fp=fopen("customer.txt","r+");
			
			if(fp==NULL)
			{
				printf("FILE NOT FOUND");
				exit(0);
			}
			while(!feof(fp))
			{
				 fgets(ch,strlen(c.id)+1,fp );
				 if(!(strcmp(ch,c.id)))
				 {
				 goto C;
				 }
				 else
				 {
				 	continue;
				 }
			}
			printf("enter a string password(max 8 characters)\n");
			fgets(c.pass,10,stdin);
						c.pass[strlen(c.pass)-1]='\0';
			//customer name
			printf("ENTER YOUR NAME( atmost 20 characters)\n");
			fflush(stdin);
			fgets(c.name,20,stdin);
			c.name[strlen(c.name)-1]='\0';
			printf("ENTER YOUR MOBILE NO()\n");
			fgets(c.no,13,stdin);
			c.no[strlen(c.no)-1]='\0';
			//file processing
			fp=fopen("customer.txt","ab");
			fwrite(&c,sizeof(c),1,fp);
			fprintf(fp,"\n");
			fclose(fp);
			//printing customer data
			//print function call
			process();
			print(&c);
			goxy(1,5);
			printf("\nWanna ride?(yes/no)\n");
			gets(s);
			//process fn call
			// process();
			if(!(strcmp(s,"no"))) {
				goxy(1,5);
				printf("HAVE A FUN!\n");
				exit(1);
			} 
			else {
				char **ptr;
				printf("enter point name from menu\n");
				fp=fopen("point.txt","r+");
				int i=0,j=0;
				ptr=(char **)malloc(sizeof(char*));
				while((fscanf(fp,"%s\n",location))!=EOF){
					ptr=(char **)realloc(ptr,(i+1)*sizeof(char *));
				if(j%2!=0){
					fseek(fp,1,1);
					j++;
					continue;
				}
				int l=strlen(location);
				ptr[i]=(char *)malloc((l+1));
				strcpy(ptr[i],location);
				i++;j++;
				}
				for(int j=0; j<i; j++) {
					goxy(0,5);
					printf("%d-%s\n",j+1,ptr[j]);
				}
				memset(location,0,20);
				scanf("%s",location);
				char flocation[20];
				//file open again
				fp=fopen("point.txt","r+");
				int k=1;
				while(!feof(fp)) {
					fscanf(fp,"%s",flocation);
					fscanf(fp,"%d",&t.hr);
					fscanf(fp,"%d",&t.m);
					if(!strcmp(flocation,location)) {
						
						goxy(1,5);
						printf("your point is:%s",flocation);
						goxy(2,5);
						printf("Expected time is --> %d hours and %d minutes",t.hr,t.m);
						break;
						}
						
				}
				fclose(fp);
				}	
				//FILE CLOSE AND TIME IS TAKEN FROM FILE
				goxy(2,5);
A:
				printf("IS THE RIDE START(yes/no)\n");
				scanf("%s",s);
				if(!(strcmp(s,"no"))) {
					printf("wait for 3 minutes the ride will be reached soon\n");
					sleep(10);
					goto A;
				}
				else
				{
					unit1=timeunit();
				}
				printf("is your ride ends\n");
				scanf("%s",s);
				if(!(strcmp(s,"no")))
				{
					unit2= extratime();
				}
				float unit=unit1+unit2;
				cost=price*unit;
				print(&a);
				printf("your total cost is %f",cost);
				fp=fopen("price.txt","a");
				fprintf(fp,"%d",cost);
			}//ride loop ends
			
			
		            //SIGN IN CONDITION...
	else if(!(strcmp(s,"sign in"))) {

             char pass[10];
			D:
			printf("enter NU_ID\n");
			scanf("%s",c.id);
			printf("enter password\n");
			scanf("%s",c.pass);
			char fid[strlen(c.id)+1];
			char fpass[strlen(c.pass)+1];
			fp=fopen("customer.txt","rb");
			if(fp==NULL)
			{
				printf("file doesnt exist\n");
				goto B;
			}
			int size, i=0,flag=0;
			while(!feof(fp)) {
			int offset=i*sizeof(c);	
				fseek(fp,offset,SEEK_SET);
                 if(i>0)
					fseek(fp,i,1); 
		fread(&a,sizeof(c),1,fp);
if(!strcmp(a.id,c.id))
		{
			if(!strcmp(a.pass,c.pass)){
				        flag=1;
						process();
						print(&a);
						break;
						}
						}
				else {
					i++;
					continue;
				}		
				}
					if(flag==0)
					{
						printf("\nID NOT MATCHED...\n");
						
						goto D;
						}	
						
							goxy(1,5);
			printf("\nWanna ride?(yes/no)\n");
			fflush(stdin);
			gets(s);
			//process fn call
			// process();
			if(!(strcmp(s,"no"))) {
				goxy(1,5);
				printf("HAVE A FUN!\n");
				exit(1);
			} 
			else {
				char **ptr;
				printf("enter point name from menu\n");
				fp=fopen("point.txt","r+");
				int i=0,j=0;
				ptr=(char **)malloc(sizeof(char*));
				while((fscanf(fp,"%s\n",location))!=EOF){
					ptr=(char **)realloc(ptr,(i+1)*sizeof(char *));
				if(j%2!=0){
					fseek(fp,1,1);
					j++;
					continue;
				}
				int l=strlen(location);
				ptr[i]=(char *)malloc((l+1));
				strcpy(ptr[i],location);
				i++;j++;
				}
				for(int j=0; j<i; j++) {
					goxy(0,5);
					printf("%d-%s\n",j+1,ptr[j]);
				}
				memset(location,0,20);
				scanf("%s",location);
				char flocation[20];
				//file open again
				fp=fopen("point.txt","a+");
				int k=1;
				while(!feof(fp)) {
					fscanf(fp,"%s",flocation);
					fscanf(fp,"%d",&t.hr);
					fscanf(fp,"%d",&t.m);
					if(!strcmp(flocation,location)) {
						
						goxy(1,5);
						printf("%s",flocation);
						goxy(2,5);
						printf("Expected time is --> %d hours and %d minutes",t.hr,t.m);
						break;
						}

				}
				}
				fclose(fp);
				//FILE CLOSE AND TIME IS TAKEN FROM FILE
				goxy(2,5);
a:
				printf("IS THE RIDE START(yes/no)\n");
				scanf("%s",s);
				if(!(strcmp(s,"no"))) {
					printf("wait for 1 minute the ride will be reached soon\n");
					sleep(1);
					goto a;
				}
				else
				{
					unit1=timeunit();
				}
				printf("is your ride ends\n");
				scanf("%s",s);
				if(!(strcmp(s,"no")))
				{
					 unit2=extratime();
				}
				else{
				float unit=unit1+unit2;
				cost=price*unit;
				print(&a);
				printf("your total cost is %f",cost);
				fp=fopen("price.txt","a");
				fprintf(fp,"%d",cost);
				}
			}//ride loop ends
		 else {
			goxy(0,5);
			puts("WRONG CHOICE");
			goto B;
		}
	}
	//USER CONDITION ENDS...
	else if(choice=='o'||choice=='O') {
		int size;
		char ask;
		char *pass;
		//PROCESSING FUNCTION IS CALLED
		process();
		for(int i=0; i<3; i++) {
			printf("enter password\n");
			scanf("%s",s);
			pass=(char *)malloc(strlen(s));
			fp=fopen("owner.txt","rb");
			if(fp==NULL){
			printf("file not open\n");
			exit(1);
			}
			fscanf(fp,"%s",pass);
			fclose(fp);
			//process function is called
			process();
			if(!(strcmp(s,pass))) {
				goxy(1,5);
				printf("YOU ARE ENTERED SUCESSFULLY\n");
				system("cls");
				break;
				//here is the work
			} else if(i==2) {
				goxy(0,5);
				printf("SORRY! INCORRECT PASSWORD THREE TIMES");
				system("cls");
				exit(1);
			} else {
				goxy(0,5);
				printf("Incorrect password Try again\n");
				continue;
			}
		}
		while(1) {
			greetings();		
			goxy(1,5);
			printf("1-To change the password");
			goxy(1,5);
			printf("2-To add location points in file");
			goxy(1,5);
			printf("3-To view car details");
			goxy(1,5);
			printf("4-To get income of that day\n");
			goxy(1,5);
			printf("5-To delete records in car details");
			goxy(1,5);
			printf("6-To add backup");
			goxy(1,5);
			printf("7-To switch end");
			goxy(1,5);
			printf("8-To exit");
			goxy(1,0);
			printf("what do you want to do\n");
			scanf("%d",&opt);
			switch(opt) {
				case 1:
					printf("enter the curret password\n");
					scanf("%s",&s);
					pass=(char *)malloc(strlen(s));
					fp=fopen("owner.txt","r+");
					fscanf(fp,"%s",pass);
					fclose(fp);
					if(!(strcmp(s,pass))){
						free(pass);
                            printf("enter size of new password");
                            scanf("%d",&size);
                            pass=(char *)malloc(size);
							printf("enter new password\n");
							scanf("%s",s);
							fp=fopen("owner.txt","w");
                            fprintf(fp,"%s",s);
							fclose(fp);  
						}
						else{
							printf("wrong password!\n");
						}
					break;
				case 2:
					char name[20];
					printf("enter no of location points you want to enter\n");
					scanf("%d",&size);
		
					for(int i=0;i<=size-1;i++){
						printf("enter location name\n");
						fflush(stdin);
						gets(name);
						printf("enter time for this location(#hr-#min)");
						fflush(stdin);
						scanf("%d-%d",&t.hr,&t.m);
						fp=fopen("point.txt","a");
						fputs(name,fp);
						fprintf(fp," %d %d\n",t.hr,t.m);
						fclose(fp);
					}
						
					break;
					case 3:
				     		char line[100];
							fp=fopen("car.txt","r+");
							int ln;
							for(int i=0;fgets(line,100,fp);i++){
                                
                                printf("%d-%s",i+1,line);
							}
						getche();
							fclose(fp);
						break;
						case 4:
						     gettotal();
							break;
						case 5:
							datadelete();
							break;
							case 6:
								databackup();
								break;
								case 7:
								goto B;
								break;
								case 8:
								exit(0);
								break;	
			}
			process();
		}
		
		
	}

	//OWNER CONDITION ENDS

	else {
		goxy(1,5);
		printf("INVALID INPUT");
		sleep(1);
		goto B;
	}



}
// FUNCTION DEFINITIONS
void greetings() {
	system("cls");
	printf("\n-----------------------------------------------");
	printf("WELCOME TO FASTIAN CAB SERVICE");
	printf("-----------------------------------------------\n\n");
}
void process(void) {
	system("cls");
	goxy(15,6);
	printf("processing.");
	sleep(1);
	system("cls");
	goxy(15,6);
	printf("processing..");
	sleep(1);
	system("cls");
	goxy(15,6);
	printf("processing...");
	greetings();
}
void print(struct customer *c1) {
	goxy(2,5);
	printf("_________________________________");
	goxy(1,5);
	printf("%s  %s","Your password ->",c1->pass);
	goxy(2,5);
	printf("NU-ID#              %s",c1->id);
	goxy(2,5);
	printf("Customer Name:      %s",c1->name);
	goxy(2,5);
	printf("Customer Mobile no: %s",c1->no);
	goxy(1,5);
	printf("_________________________________\n");
}
void goxy(int y,int x) {
	for(int i=0; i<y; i++)
		printf("\n");
	for(int i=0; i<x; i++)
		printf("\t");
}
float timeunit(void){
	  int h=0,min=0,sec=0;
	  float unit=0;
	 
	  while(!((h==t.hr)&&(min==t.m))){
	      print(&a);
		  	  printf("%d:%d:%d\t\t\t\t\t\t\t\t\tunit=%.2f\n",h,min,sec,unit);
		sleep(1);
		  system("cls");
	  	if(min==59&&sec==59){
	  		h++;
	  		min=0;
	  		sec=0;
	  		continue;
		  }
	    else if(sec==59){
		  	min++;
		  	unit++;
		  	sec=0;
		  	continue;
		  }
		else{
			if(sec%10==0&&sec!=0){
			unit++;
			}sec++;
		}
		  
			  }
			  return unit;
}
float extratime(void)
{
	char ch='n';
	int h=0,min=0,sec=0;
	float unit=0;
	 
	  while(ch=='n'){
	      print(&a);
		  printf("%d:%d:%d\t\t\t\t\t\t\t\t\t\t\t\tunit=%.2f\n",h,min,sec,unit);
		sleep(1);
		  system("cls");
	  	if(min==59&&sec==59){
	  		h++;
	  		min=0;
	  		sec=0;
	  		continue;
		  }
	    else if(sec==59){
	    	min++;
		  	unit++;
		  	sec=0;
	    	printf("is your ride ends now(y/n)\n");
	    	ch=getch();
		  	continue;
		  }
		else{
			sec++;
		}
		  
			  }
			  return unit;
}

void databackup(void)
{
	FILE *fp1=fopen("customer.txt","r+");
	FILE *fp2=fopen("backup.txt","a+");
	while(fread(&a,sizeof(a),1,fp1)!=NULL)
	{
		fwrite(&a,sizeof(a),1,fp2);
	}
	printf("backup completed\n");
	getch();
	fclose(fp1);
	fclose(fp2);
}
void gettotal(void)
{
		        float cost,total;
			    FILE *ptr1=fopen("price.txt","r+");
				while(!feof(ptr1))
					{
						fscanf(ptr1,"%d",&cost);
						total+=cost;
					}
						printf("TODAY TOTAL AMOUNT EARNED IS %.2f",total);
					fclose(ptr1);
					ptr1=fopen("price.txt","w");
					fclose(ptr1);
}




