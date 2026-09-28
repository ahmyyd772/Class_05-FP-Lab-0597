#include<stdio.h>

int main(){
    int product,customer,orderNo,discount,priority,group;
    float amount,distance,discountAmount,finalAmount,deliveryCharge,priorityCharge,total;
    char *productName,*customerName;

    printf("1.Electronics\n2.Clothing\n3.Books\n4.Household\n");
    printf("Select product category: ");
    scanf("%d",&product);

    printf("1.Regular\n2.Premium\n3.Corporate\n");
    printf("Select customer category: ");
    scanf("%d",&customer);

    printf("Enter order amount: ");
    scanf("%f",&amount);
    printf("Enter delivery distance (km): ");
    scanf("%f",&distance);
    printf("Enter order number: ");
    scanf("%d",&orderNo);

    if(amount<0 || distance<0 || orderNo<0){
        printf("Invalid order details\n");
        return 0;
    }

    switch(product){
    case 1:
        productName="Electronics";
        switch(customer){
        case 1: discount=5; break;
        case 2: discount=10; break;
        case 3: discount=15; break;
        default: printf("Invalid customer category\n"); return 0;
        }
        break;
    case 2:
        productName="Clothing";
        switch(customer){
        case 1: discount=10; break;
        case 2: discount=15; break;
        case 3: discount=20; break;
        default: printf("Invalid customer category\n"); return 0;
        }
        break;
 case 3:
   productName="Books";
     switch(customer){
  case 1: discount=8; break;
  case 2: discount=12; break;
     case 3: discount=18; break;
     default: printf("Invalid customer category\n"); return 0;
        }
      break;
     case 4:
      productName="Household";
     switch(customer){
     case 1: discount=7; break;
     case 2: discount=14; break;
     case 3: discount=20; break;
     default: printf("Invalid customer category\n"); return 0;
     }
     break;
    default:
     printf("Invalid product category\n");
        return 0;
    }

    customerName=customer==1?"Regular":customer==2?"Premium":"Corporate";
    discountAmount=amount*discount/100;
    finalAmount=amount-discountAmount;

    deliveryCharge=(finalAmount>=5000 || customer==2 || customer==3)
                   ? 0 : distance*20;
    priority=(customer==2 || customer==3) && amount>=10000;
    priorityCharge=priority?500:0;
    group=orderNo%4;
    total=finalAmount+deliveryCharge+priorityCharge;

    printf("\n--- Order Report ---\n");
    printf("Product category: %s\n",productName);
    printf("Customer category: %s\n",customerName);
    printf("Original amount: Rs. %.2f\n",amount);
    printf("Discount: %d%%\n",discount);
    printf("Discount amount: Rs. %.2f\n",discountAmount);
    printf("Final payable amount: Rs. %.2f\n",finalAmount);
    printf("Delivery distance: %.2f km\n",distance);
    printf("Shipping: %s\n",deliveryCharge==0?"Free":"Paid");
    printf("Delivery charges: Rs. %.2f\n",deliveryCharge);
    printf("Priority delivery: %s\n",priority?"Yes":"No");
    printf("Priority charges: Rs. %.2f\n",priorityCharge);
    printf("Processing Group: %c\n",'A'+group);
    printf("Total amount payable: Rs. %.2f\n",total);

    return 0;
}