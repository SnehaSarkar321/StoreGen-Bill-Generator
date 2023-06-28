#include<stdio.h>
#include<conio.h>
#include<string.h>
int search(char[100],char[100][100]);
float price[10],amount[10],tam;
int qty[10],n,i,ch,flag,num,c;
char name[100][100],item[100];
int main(){
    do{
        printf("\n\n1.Add item ");
        printf("\n2.Remove item ");
        printf("\n3.Add/Remove Quantity ");
        printf("\n4.Calculate bill");
        printf("\n5.Print bill");
        printf("\n6.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: {
                printf("Enter the no. of items you want to purchase: \n");
                scanf("%d",&n);
                for(i=1;i<=n;i++){
                    printf("\nEnter the name of the item: ");
                    fflush(stdin);
                    gets(name[i]);
                    printf("\nEnter the quantity: ");
                    scanf("%d",&qty[i]);
                    printf("\nEnter the price of the item: ");
                    scanf("%f",&price[i]);
                }
                break;
            }    
            case 2 :{
                printf("\nEnter the name of the item you want to remove : ");
                fflush(stdin);
                gets(item);
                flag=search(item,name);
                if(flag!=0){
                    for(i=flag;i<n;i++){
                        strcpy(name[i],name[i+1]);
                        qty[i]=qty[i+1];
                        price[i]=price[i+1];
                    }n--;
                printf("Item removed..!!");
                }
                else
                    printf("Item not found to be removed ");
                break;
            }
            case 3 :{
                printf("\nEnter the name of the item you add/remove in quantity: ");
                fflush(stdin);
                gets(item);
                flag=search(item,name);
                if(flag!=0){
                    printf("\nQuantity : %d",qty[flag]);
                    printf("\nEnter the new quantity:");
                    scanf("%d",&num);
                    qty[flag]=num;
                    printf("Quantity updated..!!");
                }
                else
                    printf("Item not found...!!!");
                break;
            }
            case 4 :{
                for(i=1; i<=n;i++){
                    amount[i]=qty[i]*price[i];
                    tam=tam+amount[i];
                }
                break;
            }
            case 5 :{
                printf("\n\n****** B I L L ******");
                printf("\nItem\tQuantity\tPrice\tAmount ");
                for(i=1;i<=n;i++){
                    printf("\n\n%s\t%d\t\t%.2f\t%.2f",name[i],qty[i],price[i],amount[i]);
                }
                printf("\n_______________");
                printf("\nTotal amount to be paid\t\t%.2f",tam);
                printf("\n_______________");
                break;
            }
            default:
                printf("\nWrong Input");
        }
    }while(ch!=6);
}  
int search(char item[],char name[100][100]){
    for(i=1;i<=n;i++){
        if(strcmp(item,name[i])==0){
            c=1;
            break;
        }
    }
    if(c==1)
        return(i);
    else
      return 0;    
}