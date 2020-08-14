#include<stdio.h>
int check()
{
	char x[10],name[10],x1[10],mob[10];
	int y,pass,t,bal;
	printf("\n------------>  USERNAME             :");
	scanf("%s",&x);
	printf("\n------------>  PASSWORD             :");
	scanf("%d",&y);
	FILE *fpointer = fopen(x,"r");
	fscanf(fpointer,"%s",&name);
	fscanf(fpointer,"%d",&pass);
	if( x[10] == name[10] && y == pass)
	{
		printf("\n |++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
		printf("\n------->  NAME                  : %s",name);
		
		fscanf(fpointer,"%d",&bal);
		printf("\n------->  ACCOUNT BALANCE       : Rs.%d/-\n\n",bal);
		printf("\n |++++++++++++++++++++++++++++++++++++++++++++++++++|\n");
		//fscanf(fpointer,"%s",&mob);
		//printf("\nMobile No.                 :%s",mob);
	}
	else{
		printf("\n-----Account not Exsit-----\n");
	}
	
	return 1;
}

int login()
{
	char x[10],name[10],mob[10];
	int y,pass,t,bal;
	printf("\nEnter User Name :");
	scanf("%s",&x);
	printf("\nPassword        :");
	scanf("%d",&y);
	FILE *fpointer = fopen(x,"r");
	fscanf(fpointer,"%s",&name);
	fscanf(fpointer,"%d",&pass);
	if( y == pass)
	{
		printf("\n       |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|");
		printf("\n       |+|                                                                   |+|");
		printf("\n       |+|    NAME                       : %s                              ",name);
		
		fscanf(fpointer,"%d",&bal);
		printf("\n       |+|    AVAILABLE BALCANCE         :%d Rs.                              ",bal);
		fscanf(fpointer,"%s",&mob);
		printf("\n       |+|    MOBILE NO.                 :%s                               ",mob);
		printf("\n       |+|                                                                 ");
		printf("\n       |+|___________________________________________________________________|+|");
	
	
		int q;
		
		do{
		printf("\n       +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n       |+|                                                                   |+|");
		printf("\n       |+|                          1.   WITHDRAWAL                          |+|");
		printf("\n       |+|                          2.   EDIT PROFILE                        |+|");
		printf("\n       |+|                          3.   DIPOSITE                            |+|");
		printf("\n       |+|                          4.   TRANSFER FUNDS                      |+|");
		printf("\n       |+|                          5.   EXIT                                |+|");	
		printf("\n       |_______________________________________________________________________|");
		printf("\n                                   Enter Choice   :");
			scanf("%d",&q);	
			switch(q)
			{
				case 1:
					printf("\n     |+|               Enter Amount           :");
					scanf("%d",&t);
					printf("\n           ++++++------Transection Success------++++++\n");
				
					fpointer = fopen(name,"w");
					fprintf(fpointer,"%s",name);
					fprintf(fpointer,"\n%d",pass);
					fprintf(fpointer,"\n%d",bal-t);
					fprintf(fpointer,"\n%s",mob);
		
						fclose(fpointer);
					break;
				case 2:
					printf("\nEnter New Name           :");
					scanf("%s",&name);
					printf("\nEnter New Password       :");
						scanf("%d",&pass);
					printf("\nEnter Balance        : ");
					scanf("%d",&bal);
					printf("\nEnter New Mobile Number  :");
					scanf("%s",&mob);
					fpointer = fopen(name,"w");
					fprintf(fpointer,"%s",name);
					fprintf(fpointer,"\n%d",pass);
					fprintf(fpointer,"\n%d",bal);
					fprintf(fpointer,"\n%s",mob);
		
					fclose(fpointer);
				case 3:
					printf("\n     |+|               Enter Amount           :");
					scanf("%d",&t);
					printf("\n           ++++++------Transection Success------++++++\n");
				
					fpointer = fopen(name,"w");
					fprintf(fpointer,"%s",name);
					fprintf(fpointer,"\n%d",pass);
					fprintf(fpointer,"\n%d",bal+t);
					fprintf(fpointer,"\n%s",mob);
					
					fclose(fpointer);
					break;
				case 4:
					int trans,tbal,tpass;
					char x1[10],tname[10],tmob[10];
					printf("\n       +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
					printf("\n       |_______________________________________________________________________|");
					printf("\n       ENTER AMMOUNT     :                          ");
					scanf("%d",&trans);
					if(trans <= bal)
					{
						
							printf("\n Enter NAME in which you want to transfer funds  : ");
							scanf("%s",&x1);
		  					FILE *fpointer = fopen(x1,"r");
							fscanf(fpointer,"%s",&tname);
							
							fscanf(fpointer,"%d",&tpass);

                            if(x1[10] == tname[10] )
							{	
							
								//fscanf(fpointer,"%s",&tname);
								fscanf(fpointer,"%d",&tbal);	
								fscanf(fpointer,"%s",&tmob);
								
								
								fpointer = fopen(x1,"w");
								tbal = tbal+trans;
								fprintf(fpointer,"%s",x1);
								fprintf(fpointer,"\n%d",tpass);
								fprintf(fpointer,"\n%d",tbal);
								fprintf(fpointer,"\n%s",tmob);
								
							
								fclose(fpointer);
								bal=bal-trans;
								
								fpointer = fopen(name,"w");
								fprintf(fpointer,"%s",name);
								fprintf(fpointer,"\n%d",pass);
								fprintf(fpointer,"\n%d",bal);
								fprintf(fpointer,"\n%s",mob);
					
								fclose(fpointer);
								printf("\n           ++++++-------------Transection Success-----------++++++\n");
							}
							else{
								printf("\n ----------------------ACCOUNT NOT EXIST-------------------------");
							}
							
				
						
					}
					else{
						printf("\n -------------------NOT ENOUGH BALANCE---------------- ");
					}
				
					
				default :
					break;
			}
		}while (q != 5);
	}
	else{
		printf("\n-------------------Account not Exsit-----------------\n");
	}
	
	
	return 1;
}
void Sign()
{
	int pass,bal;
	char name[10],mob[10];
	printf("\nEnter name           :");
	scanf("%s",&name);
	printf("\nEnter password       :");
	scanf("%d",&pass);
	printf("\nEnter Balance        : ");
	scanf("%d",&bal);
	printf("\nEnter Mobile Number  :");
	scanf("%s",&mob);
	FILE *fpointer = fopen(name,"w");
	fprintf(fpointer,"%s",name);
	fprintf(fpointer,"\n%d",pass);
	fprintf(fpointer,"\n%d",bal);
	fprintf(fpointer,"\n%s",mob);

	fclose(fpointer);
	
	printf("\n-----Sign Up Done------\n");
	
}
void manu()
{
//	printf("\n____________________________________________________________________________\n");
	printf("\n\n\n\n-----------------------------------ATM--------------------------------------\n");
	printf(" ___________________________________________________________________________\n");
	printf("|___________________________________________________________________________|\n");
	printf("---->  PRESS 1 TO                    LOG IN");
	printf("\n---->  PRESS 2 TO                    SIGN UP");
	printf("\n---->  PRESS 3 TO                    CHECK BALANCE");
	printf("\n---->  PRESS 5 TO                    EXIT\n");
	printf(" ___________________________________________________________________________\n");
	printf("|__________________________________________________________________________|\n");
}
int main()
{
	int a;
	printf("\n                                                           By - MANOZ JINAGAL\n");
	do{
		manu();
	printf("\n---->  Enter Choice    :");
	scanf("%d",&a);

	switch(a)
	{
		case 1:
			login();
			break;
		case 2:
			Sign();
			break;
		case 3:
			check();
			break;
		default:
			break;
	}
}while(a != 5);
}

