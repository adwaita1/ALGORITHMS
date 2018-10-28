
/*

Assignment Name: Implementation of Unification algorithm

*/


 #include<stdio.h>
//#include<conio.h>

int no_of_pred;
int no_of_arg[10];
int i,j;
char nouse;
char predicate[10];
char argument[10][10];


void unify();
void display();
void chk_arg_pred();


   void main()
   {
   int ch;
   do{
//   clrscr();

 
            printf("\t=========PROGRAM FOR UNIFICATION=========\n");
            printf("\nEnter Number of Predicates:- [ ]\b\b");
            scanf("%d",&no_of_pred);

            for(i=0;i<no_of_pred;i++)
            {
            scanf("%c",&nouse);    //to accept "Enter" as a character
            printf("\nEnter Predicate %d:-[ ]\b\b",i+1);
            scanf("%c",&predicate[i]);
            printf("\n\tEnter No.of Arguments for Predicate %c:-[ ]\b\b",predicate[i]);
            scanf("%d",&no_of_arg[i]);
                        for(j=0;j<no_of_arg[i];j++)
                        {
                         scanf("%c",&nouse);
                         printf("\n\tEnter argument %d:( )\b\b",j+1);
                         scanf("%c",&argument[i][j]);
                        }
            }

            display();
            chk_arg_pred();
//            getch();
//            flushall();
            printf("Do you want to continue(y=1/n=0): ");
            scanf("%d",&ch);
       }while(ch=='1');
   }



   void display()
   {
       printf("\n\t=======PREDICATES ARE======");
            for(i=0;i<no_of_pred;i++)
            {
             printf("\n\t%c(",predicate[i]);
                        for(j=0;j<no_of_arg[i];j++)
                        {
                        printf("%c",argument[i][j]);
                        if(j!=no_of_arg[i]-1)
                                    printf(",");
                        }
             printf(")");
            }
   }

   void chk_arg_pred()
   {
   int pred_flag=0;
   int arg_flag=0;

   /*======Checking Prediactes========*/
            for(i=0;i<no_of_pred-1;i++)
            {
                        if(predicate[i]!=predicate[i+1])
                        {
                        printf("\nPredicates not same..");
                        printf("\nUnification cannot progress!");
                        pred_flag=1;
                        break;
                        }
            }
   /*=====Chking No of Arguments====*/
     if(pred_flag!=1)
     {
            for(i=0;i<no_of_arg[i]-1;i++)
            {
                        if(no_of_arg[i]!=no_of_arg[i+1])
                        {
                        printf("\nArguments Not Same..!");
                        arg_flag=1;
                        break;
                        }
            }
     }
            if(arg_flag==0&&pred_flag!=1)
                        unify();

   }
/*==========UNIFY FUNCTION=========*/
   void unify()
   {
            int flag=0;
            for(i=0;i<no_of_pred-1;i++)
            {
                 for(j=0;j<no_of_arg[i];j++)
                 {
                        if(argument[i][j]!=argument[i+1][j])
                        {
                          if(flag==0)
                          printf("\n\t======SUBSTITUTION IS======");
                        printf("\n\t%c/%c",argument[i+1][j],argument[i][j]);
                         flag++;
                        }
                }
            }
            if(flag==0)
            {          printf("\nArguments are Identical...");
                        printf("\nNo need of Substitution\n");
            }
   }



/*	OUTPUT:

sitrc@sitrc-OptiPlex-3020:~$ gcc unify.c
sitrc@sitrc-OptiPlex-3020:~$ ./a.out
	=========PROGRAM FOR UNIFICATION=========

Enter Number of Predicates:- [5]

Enter Predicate 1:-[4]

	Enter No.of Arguments for Predicate 4:-[2]

	Enter argument 1:(1)

	Enter argument 2:(3)

Enter Predicate 2:-[4]

	Enter No.of Arguments for Predicate 4:-[2]

	Enter argument 1:(4)

	Enter argument 2:(6)

Enter Predicate 3:-[4]

	Enter No.of Arguments for Predicate 4:-[2]

	Enter argument 1:(7)

	Enter argument 2:(9)

Enter Predicate 4:-[4]

	Enter No.of Arguments for Predicate 4:-[2]

	Enter argument 1:(2)

	Enter argument 2:(8)

Enter Predicate 5:-[4]

	Enter No.of Arguments for Predicate 4:-[2]

	Enter argument 1:(3)

	Enter argument 2:(7)

	=======PREDICATES ARE======
	4(1,3)
	4(4,6)
	4(7,9)
	4(2,8)
	4(3,7)
	======SUBSTITUTION IS======
	4/1
	6/3
	7/4
	9/6
	2/7
	8/9
	3/2
	7/8Do you want to continue(y=1/n=0): 
*/
