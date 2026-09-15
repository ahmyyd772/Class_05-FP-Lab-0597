#include <stdio.h>

int main() {
int department, age, heartRate, consciousness, severity;
int departmentPriority = 0, criticalCondition, seniorStatus, temperatureAlert;
int caseRemainder;
float temperature;
const char *departmentName, *consciousnessStatus, *severityName;
const char *caseCategory, *finalDecision;

printf("Select Emergency Department:\n");
printf("1. General Emergency\n");
printf("2. Cardiology\n");
printf("3. Neurology\n");
printf("4. Trauma\n");
printf("Enter choice: ");
scanf("%d", &department);

printf("Enter patient age: ");
scanf("%d", &age);

  printf("Enter heart rate: ");
   scanf("%d", &heartRate);

 printf("Enter body temperature: ");
  scanf("%f", &temperature);

printf("Level of Consciousness:\n");
printf("1. Conscious\n");
printf("2. Unconscious\n");
 printf("Enter choice: ");
  scanf("%d", &consciousness);

printf("Severity Level:\n"); 
 printf("1. Low\n");
  printf("2. Medium\n");
  printf("3. High\n");
  printf("Enter choice: ");  
   scanf("%d", &severity);

switch(department) {
case 1:
departmentName = "General Emergency";
switch(severity) {
case 1:
case 2:
departmentPriority = 0;
break;
case 3:
departmentPriority = 1;
break;
default:
printf("Invalid severity level.\n");
return 0;
}
break;

case 2:
departmentName = "Cardiology";
switch(severity) {
case 1:
case 2:
case 3:
if(heartRate < 50 || heartRate > 120)
departmentPriority = 1;
break;
default:
printf("Invalid severity level.\n");
return 0;
}
break;

case 3:
departmentName = "Neurology";
switch(severity) {
case 1:
case 2:
case 3:
if(consciousness == 2)
departmentPriority = 1;
break;
default:
printf("Invalid severity level.\n");
return 0;
}
break;

case 4:
departmentName = "Trauma";
switch(severity) {
case 1:
case 2:
departmentPriority = 0;
break;
case 3:
departmentPriority = 1;
break;
default:
printf("Invalid severity level.\n");
return 0;
}
break;

default:
printf("Invalid department choice.\n");
return 0;
}

criticalCondition = ((heartRate < 50 || heartRate > 120) && consciousness == 2);
seniorStatus = (age >= 65) ? 1 : 0;
temperatureAlert = (temperature < 36 || temperature > 38) ? 1 : 0;

caseRemainder = (age + heartRate) % 4;

switch(caseRemainder) {
case 0:
caseCategory = "Case Category A";
break;
case 1:
caseCategory = "Case Category B";
break;
case 2:
caseCategory = "Case Category C";
break;
case 3:
caseCategory = "Case Category D";
break;
}

if(criticalCondition)
finalDecision = "Immediate Medical Attention";
else if(departmentPriority || seniorStatus || temperatureAlert)
finalDecision = "Priority Further Assessment";
else
finalDecision = "Routine Medical Assessment";

consciousnessStatus = (consciousness == 1) ? "Conscious" : "Unconscious";

switch(severity) {
case 1:
severityName = "Low";
break;
case 2:
severityName = "Medium";
break;
case 3:
severityName = "High";
break;
default:
severityName = "Invalid";
}

printf("\n========== Patient Triage Report ==========\n");
printf("Emergency Department        : %s\n", departmentName);
printf("Patient Age                 : %d years\n", age);
printf("Heart Rate                  : %d bpm\n", heartRate);
printf("Body Temperature            : %.2f C\n", temperature);
printf("Level of Consciousness      : %s\n", consciousnessStatus);
printf("Severity Level              : %s\n", severityName);
printf("Department Priority         : %s\n", departmentPriority ? "Yes" : "No");
printf("Critical Condition          : %s\n", criticalCondition ? "Yes" : "No");
printf("Senior Priority             : %s\n", seniorStatus ? "Yes" : "No");
printf("Temperature Alert           : %s\n", temperatureAlert ? "Yes" : "No");
printf("Case Category               : %s\n", caseCategory);
printf("Final Triage Decision       : %s\n", finalDecision);
printf("============================================\n");

return 0;
}