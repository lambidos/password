#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct user {
		int id;
		char login[100];
		char first_name[50];
		char last_name[50];
		
	//	char* password;
	}u;

char * passwordV() {
	int i,a=0,b=0,c=0;
    static char password[20];
    
    start:
    	
    printf( "Enter a password that contains a capital, symbol and a number \n" );
    scanf( "%s", password );
    
    /****** test if password is between 8 and 20 caracters *******/
    
		while(strlen(password)>20 || strlen(password)<8){
			if(strlen(password)>20)
			{printf( "password too long please do not exceed 20 character \n" );scanf( "%s", password );}
			else {printf( "password too short minimum is 8 characters \n" );scanf( "%s", password );}
		goto start;
		}


	/******check if password coantains a numbre, a capital and a symbol*******/
    for(i=0; i<strlen(password);i++)
	    {
			if (isdigit(password[i]))
		    a++;
		    else {
		
			if (isalpha(password[i]))
			    {
			    	if(isupper(password[i]))
			    		b++;
				}
				else if ((password[i])!=0)
								c++;  		}
		}
		
	/*****password fulfills criteria ******/
	
if (a>0 && b>0 && c>0){
	    printf( "your password is strong\n");
	
}
	/*****password doesn't fulfill criteria ******/

	else 
	{  
		if (a==0) printf( "password need atleast one digit \n" );	
		if (b==0) printf( "password need atleast one capital letter \n" ); 
		if (c==0) printf( "password need atleast one symbol \n" );	
	sleep(5);
	system("CLS");
	goto start;
	}
    return password;
    
}

int find_current_id(){
	
//	return id;
}

void singup(int id){
	struct user u;
id+=2;
	//int length=0,j=0;

	
	printf("\n\n\n\n\nentrez fotre prenom\n");
	scanf("%s",u.first_name);

	
	printf("\n\n\n\n\nentrez fotre nom\n");
	scanf("%s",u.last_name);
    
	
	strcpy(u.login, u.first_name);
    strcat(u.login,".");
    strcat(u.login,u.last_name);
    
    
	u.id=id;
	 FILE *fptr;
   fptr = fopen("users.txt","a");

	fprintf(fptr, "id:%d %s %s %s\n",u.id, u.first_name,u.last_name, u.login);
   fclose(fptr);
   
	
/*
	//writing first name into login
 	for (length=0; u.first_name[length] != '\0';++length) {
    u.login[length] = u.first_name[length];}
    
    //adding a '.' between first name and last name into login
    u.login[length]= '.';
    length++;
    
	//writing last name into login
	for (j=0; u.last_name[j] != '\0';++j,length++) {
    u.login[length] = u.last_name[j];}
    u.login[length]= '\0';
    
	*/

	
}

int main(){
			int a=0;
		
		printf("\n\n\n\n\n1: to sign up\n2: to log-in\n");
		scanf(" %d",&a);
		fflush(stdin);
			while(a!=1 &&a!=2){
			system("CLS");
			printf("\n\n\nvieuller entrez 1 ou 2\n\n");
			printf("1: to sign up\n2: to log-in\n");
			scanf("%d",&a);fflush(stdin);
		}
				if(a==1){
					system("CLS");
					singup(1);
				}else{
					passwordV();
				}

				return 0;
}












