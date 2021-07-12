#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

#define MAX 100
typedef struct tm tm;

void help(){
	printf("Usage :-\n");
	printf("$ ./todo add \"todo item\"  # Add a new todo\n");
	printf("$ ./todo ls               # Show remaining todos\n");
	printf("$ ./todo del NUMBER       # Delete a todo\n");
	printf("$ ./todo done NUMBER      # Complete a todo\n");
	printf("$ ./todo help             # Show usage\n");
	printf("$ ./todo report           # Statistics\n");
}

int main(int argc, char* argv[])
{
	FILE *f1,*f2,*f3,*f4;
	int i,len,tot=0,lsiz=128,rsiz=10,c=1,lno,ctr=0;
	char line[lsiz][rsiz],ch,temp[]="temp.txt",str[MAX];
	char mnth[MAX],dy[MAX],yr[MAX];
	int year,month,day;
	int pending,done;
	
	//todo help
    if(strcmp(argv[1],"help")==0){
    	help();
    }
    //todo add
    else if(strcmp(argv[1],"add")==0){
    	f1=fopen("todo.txt","a");
    	
    	if(f1==NULL){
    		printf("unable to open");
    		//exit(1);	
		}
		else{
			fflush(stdin);
			
			fputs(argv[2],f1);
			fputs("\n",f1);
			fclose(f1);
			
			printf("Added todo:\"%s\"",argv[2]);
		}
	}
	//todo ls
	else if(strcmp(argv[1],"ls")==0){
		i=0;
		tot=0;
		
		f1=fopen("todo.txt","r");
		
		while(fgets(line[i],lsiz,f1)){
			line[i][strlen(line[i])-1]='\0';
			i++;
		}
		tot=i;
		for(i=tot-1;i>=0;i--){
			printf("[%d] %s\n",c,line[i]);
			c++;
		}
		fclose(f1);	
	}
	//todo del
	else if(strcmp(argv[1],"del")==0){
		f1=fopen("todo.txt","r");
		
		while(fgets(line[i],lsiz,f1)){
			c++;
		}
		rewind(f1);
		
		if(atoi(argv[2])>c){
			printf("Error: todo #%s does not exist. Nothing deleted.",argv[2]);
		}
		else{
			if(atoi(argv[2])==1 || atoi(argv[2])==2){
				lno=atoi(argv[2])-1;
			}
			else{
				lno=(c-1)-(atoi(argv[2])-1);
			}
		
			f2=fopen(temp,"w");
			lno++;
		
			while(!feof(f1)){
				strcpy(str,"\0");
				fgets(str,MAX,f1);
			
				if(!feof(f1)){
					ctr++;
					if(ctr!=lno){
						fprintf(f2,"%s",str);
					}
				}
			}
			fclose(f1);
			fclose(f2);
			remove("todo.txt");
			rename(temp,"todo.txt");
		
			printf("Deleted todo #%s",argv[2]);
		}
	}
	//todo done
	else if(strcmp(argv[1],"done")==0){
		i=0;
		tot=0;
		c=0;
		
		f1=fopen("todo.txt","r");
		
		while(fgets(line[i],lsiz,f1)){
			line[i][strlen(line[i])-1]='\0';
			i++;
			c++;
		}
		tot=i;
		rewind(f1);
		
		if(atoi(argv[2])>c){
			printf("Error: todo #%s does not exist.",argv[2]);
		}
		else{
			if(atoi(argv[2])==1 || atoi(argv[2])==2){
				lno=atoi(argv[2])-1;
			}
			else{
				lno=(c-1)-(atoi(argv[2])-1);
			}
			f3=fopen("done.txt","a");
			
			if(f3==NULL){
    			printf("unable to open");
    			//exit(1);	
			}
			else{
				fflush(stdin);

				time_t currentTime;
				time(&currentTime);
	
				tm *myTime= localtime(&currentTime);
				year=1900+myTime->tm_year;
				month=myTime->tm_mon+1;
				day=myTime->tm_mday;
	
				sprintf(yr,"%d",year);
				sprintf(mnth,"%d",month);
				sprintf(dy,"%d",day);
	
				strcat(yr,"-");
				strcat(yr,mnth);
				strcat(yr,"-");
				strcat(yr,dy);
				
				fputs("x ",f3);
				fputs(yr,f3);
				fputs(" ",f3);
				fputs(line[lno],f3);
				fputs("\n",f3);
				
				fclose(f3);
				
				f4=fopen(temp,"w");
				lno++;
		
				while(!feof(f1)){
					strcpy(str,"\0");
					fgets(str,MAX,f1);
			
					if(!feof(f1)){
						ctr++;
						if(ctr!=lno){
							fprintf(f4,"%s",str);
						}
					}
				}
				fclose(f1);
				fclose(f4);
				remove("todo.txt");
				rename(temp,"todo.txt");
			
				printf("Marked todo #%s as done.",argv[2]);
			}
		}
	}
	//todo report
	else if(strcmp(argv[1],"report")==0){
		pending=0;
		done=0;
		i=0;
		tot=0;
		c=0;
		
		fflush(stdin);

		time_t currentTime;
		time(&currentTime);
	
		tm *myTime= localtime(&currentTime);
		year=1900+myTime->tm_year;
		month=myTime->tm_mon+1;
		day=myTime->tm_mday;
	
		sprintf(yr,"%d",year);
		sprintf(mnth,"%d",month);
		sprintf(dy,"%d",day);
	
		strcat(yr,"-");
		strcat(yr,mnth);
		strcat(yr,"-");
		strcat(yr,dy);
		
		f1=fopen("todo.txt","r");
		f3=fopen("done.txt","r");
		
		if(f1==NULL){
			printf("cant open file\n");
		}
		else{
			for(ch=getc(f1);ch!=EOF;ch=getc(f1)){
				if(ch=='\n'){
					pending++;
				}
			}
		}
		fclose(f1);
		
		if(f3==NULL){
			printf("cant open file\n");
		}
		else{
			for(ch=getc(f3);ch!=EOF;ch=getc(f3)){
				if(ch=='\n'){
					done++;
				}
			}
		}
		printf("%s Pending : %d Completed : %d\n",yr,pending,done);
	}
	/*fllush(stdin);
	return 0;*/
}
