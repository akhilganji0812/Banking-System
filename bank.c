#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Define a structure for a Node representing a bank account
struct Node{
  char name[200];
  int acc;
  int pin;
  int money;
  struct Node *next;
};
// Function to add a new account to the linked list
struct Node *add(struct Node *head,char name[300],int acc,int pin,int money){
  if(head==NULL){
    // If the list is empty, create a new node and set it as the head
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    strcpy(ptr->name,name);
    ptr->acc=acc;
    ptr->money=money;
    ptr->pin=pin;
    ptr->next=NULL;
    printf("account created succesfully\n");
    return(ptr);
  }
  else{
     // If the list is not empty, create a new node and make it the new head
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    strcpy(ptr->name,name);
    ptr->acc=acc;
    ptr->money=money;
    ptr->pin=pin;
    ptr->next=head;
    printf("account created succesfully\n");
    return(ptr); 
  }
}
// Function to display account details
void display(struct Node *head,int acc){
  if(head==NULL){
    printf("their is no bank account register yet\n");
  }
  else{
    int flag=0,pin;
    while(head!=NULL){
      if(head->acc==acc){
        printf("enter your pin : \n");
        scanf("%d",&pin);
        if(head->pin==pin){
          printf("Name : %s\n",head->name);
          printf("Account No. : %d\n",head->acc);
          printf("Amount : %d\n",head->money);
        }
        else{
          printf("incorrect pin \n");
        }
        flag=1;
      }
      head=head->next;
    }
    if(flag==0){
      printf("incorrect account number\n");
    }
    }
}
// Function to delete an account from the linked list
struct Node * del(struct Node *head,int acc){
    struct Node *p=head;
    if(p->acc==acc){
      // If the account to be deleted is the head, update the head
        head=p->next;
        free(p);
        return(head);
    }
    else{
      // If the account to be deleted is not the head, find it and update pointers
    struct Node *p=head->next;
    struct Node *q=head;
    while(p->acc!=acc){
        q=q->next;
        p=p->next;
    }
    q->next=p->next;
    free(p);
    return(head);
    }
}
// Function to perform a transaction between two accounts
void trans(struct Node *head,int num1,int num2,int pay,int pin){
    struct Node *p;
    struct Node *q;
    while(head!=NULL){
        if(head->acc==num1){
            p=head;
        }
        if(head->acc==num2){
            q=head;
        }
        head=head->next;
    }
      int a,b,c,d;
      if(p->pin==pin){
           a=p->money;
        if(a>=pay){   
        b=a-pay;
        p->money=b;
        c=q->money;
        d=c+pay;
        q->money=d;
        printf("transaction successfull\n");
    }
    else{
        printf("their is no sufficients money in your account\n");
    }
      }
      else{
        printf("incorrect pin\n");
      }
}
// Function to remove money from an account
void remove_money(struct Node *head,int acc,int mon,int pin){
  if(head==NULL){
    printf("their is no bank account register yet\n");
  }
  else{
    int flag=0;
    while(head!=NULL){
        if(head->acc==acc){
            flag+=1;
            if(head->pin==pin){
                flag=2;
            int a,b;
            a=head->money;
            if(a>=mon){
                b=a-mon;
                head->money=b;
                printf("moeny debited succesfully\n");
                break;
            }
            else{
                printf("their is no sufficients money in your account to remove\n");
            }
        }
    }
    head=head->next;
    }
    if(flag==0){
        printf("incorrect card number\n");
    }
    if(flag!=2){
            printf("pin is incorrect\n");
    }
    }
}
// Function to add money to an account
void add_money(struct Node *head,int acc,int mon,int pin){
  if(head==NULL){
    printf("their is no bank account register yet\n");
  }
  else{
    int flag=0;
    while(head!=NULL){
        if(head->acc==acc){
          flag+=1;
          if(head->pin==pin){
            flag=2;
            int a,b;
            a=head->money;
            b=a+mon;
            head->money=b;
        }}
        head=head->next;
    }
    if(flag==0){
      printf("incorrect account number\n");
    }
    if(flag==1){
      printf("incorrect pin number\n");
    }
  }
}
// Function to save account details to a file
void save(struct Node *head){
  FILE *fptr;
  fptr=fopen("bank.txt","a");
  while(head!=NULL){
    fprintf(fptr,"\nName : %s",head->name);
    fprintf(fptr,"\nAccount No. : %d",head->acc);
    fprintf(fptr,"\nAmount : %d",head->money);
    head=head->next;
  }
  fclose(fptr);
}
int main(){
  struct Node *head=NULL;
  int ch,acc,pin,money,acc1;
  char name[300];
  while(1){
    printf("\n***** BANKING SYSTEM ******\n\n");
    printf("1.create account\n");
    printf("2.delete account\n");
    printf("3.transfer amount\n");
    printf("4.remove money from the account\n");
    printf("5.add money into the account\n");
    printf("6.display the account details\n");
    printf("7.exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("enter your name : \n");
              scanf("%s",name);
              printf("enter your account number \n");
              scanf("%d",&acc);
              printf("enter your 4 digit pin\n");
              scanf("%d",&pin);
              printf("enter money to deposite\n");
              scanf("%d",&money);
              head=add(head,name,acc,pin,money);
              break;
      case 2:printf("enter your account number \n");
              scanf("%d",&acc);
              head=del(head,acc);
              break;
      case 3:printf("enter your account number\n");
              scanf("%d",&acc);
              printf("enter the account number to which you want to transfer amount\n");
              scanf("%d",&acc1);
              printf("enter amount to be transformed\n");
              scanf("%d",&money);
              printf("enter your 4 digit pin\n");
              scanf("%d",&pin);
              trans(head,acc,acc1,money,pin);
              break;
      case 4:printf("enter your account number\n");
              scanf("%d",&acc);
              printf("enter your pin\n");
              scanf("%d",&pin);
              printf("enter amount to be drawn\n");
              scanf("%d",&money);
              remove_money(head,acc,money,pin);
              break;
      case 5:printf("enter your account number\n");
              scanf("%d",&acc);
              printf("enter your pin\n");
              scanf("%d",&pin);
              printf("enter amount to deposite in bank\n");
              scanf("%d",&money);
              add_money(head,acc,money,pin);
              break;
      case 6:printf("enter your account number \n");
              scanf("%d",&acc);
              display(head,acc);
              break;
      case 7:save(head);
              exit(0);
              break;
      default:printf("invaild input\n");
    }
  }
}