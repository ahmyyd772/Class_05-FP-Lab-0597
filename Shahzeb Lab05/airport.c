#include <stdio.h>

int main() {
    int category, destination;
    int age;
    float baggageWeight;
    int permittedBaggage = 0;
    int documentsValid;
    int remainder;
    int priority;
    char categoryName[30];
    char destinationName[30];
    char verificationCategory[20];
    char boardingDecision[50];

    printf("Select Passenger Category:\n");
    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");
    printf("Enter your choice: ");
    scanf("%d", &category);

    printf("\nSelect Destination Type:\n");
    printf("1. Domestic\n");
    printf("2. International\n");
    printf("Enter your choice: ");
    scanf("%d", &destination);

    switch (category) {
     case 1:
    sprintf(categoryName, "Adult");

    switch (destination) {
    case 1:
 sprintf(destinationName, "Domestic");
   permittedBaggage = 20;
  break;

    case 2:
     sprintf(destinationName, "International");
 permittedBaggage = 30;
 break;

   default:
    printf("Invalid destination choice.\n");
    return 0;
  }
    break;

 case 2:
   printf(categoryName, "Student");

  switch (destination) {
  case 1:
    sprintf(destinationName, "Domestic");
    permittedBaggage = 25;
     break;

    case 2:
    printf(destinationName, "International");
 permittedBaggage = 35;
     break;

    default:
    printf("Invalid destination choice.\n");
 }
    break;

      case 3:
      printf(categoryName, "Senior Citizen");

     switch (destination) {
     case 1:
      sprintf(destinationName, "Domestic");    
        permittedBaggage = 30;
      break;

        case 2:
     sprintf(destinationName, "International");
     permittedBaggage = 40;
     break;
         default:
 printf("Invalid destination choice.\n");
                    return 0;
            }
     break;

        default:
    printf("Invalid passenger category.\n");
            return 0;
    }

    printf("\nEnter passenger age: ");
    scanf("%d", &age);

    printf("Enter actual baggage weight in kg: ");
  scanf("%f", &baggageWeight);

    printf("Are travel documents valid?\n");
    printf("1. Yes\n");
   printf("2. No\n");
    printf("Enter your choice: ");
 scanf("%d", &documentsValid);

    remainder = age % 5;

    switch (remainder) {
        case 0:
   sprintf(verificationCategory, "Category A");
       break;
  case 1:
       sprintf(verificationCategory, "Category B");
      break;
        case 2:
     sprintf(verificationCategory, "Category C");
      break;
        case 3:
     sprintf(verificationCategory, "Category D");
            break;
   case 4:
            sprintf(verificationCategory, "Category E");
        break;
    }

    priority = (category == 3 || (category == 2 && destination == 2)) ? 1 : 0;

    if (documentsValid != 1) {
        sprintf(boardingDecision, "Denied Boarding");
    }
    else if (baggageWeight <= permittedBaggage && documentsValid == 1) {
        sprintf(boardingDecision, "Normal Boarding Allowed");
    }
    else if (baggageWeight > permittedBaggage && documentsValid == 1) {
        sprintf(boardingDecision, "Refer for Enhanced Baggage Screening");
    }

    printf("\n========== Passenger Report ==========\n");
    printf("Passenger Category       : %s\n", categoryName);
    printf("Destination Type         : %s\n", destinationName);
    printf("Permitted Baggage       : %d kg\n", permittedBaggage);
    printf("Actual Baggage Weight    : %.2f kg\n", baggageWeight);
    printf("Document Status          : %s\n",
           documentsValid == 1 ? "Valid" : "Invalid");
    printf("Verification Category    : %s\n", verificationCategory);
    printf("Priority Assistance      : %s\n",
           priority == 1 ? "Available" : "Not Available");
    printf("Final Boarding Decision  : %s\n", boardingDecision);
    printf("======================================\n");

    return 0;
}