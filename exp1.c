#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_STATES 5
int main(){
  char stateCodes[MAX_STATES][3]={"KA","TN","DL","MH","AP"};
  char vehicleNo[5];
  char state[3];
  int i,len,stateFound=0,valid=1,numStart;
  
  printf("Enter vehicle number: ");
  scanf("%s",vehicleNo);
  
  len = strlen(vehicleNo);
  
  if(len<9 || len>10){
    printf("Invalid Vehicle Number-Incorrect length\n");
    return 0;
  }
  state[0] = vehicleNo[0];
  state[1] = vehicleNo[1];
  state[2] = '\0';
  
  for(i=0; i<MAX_STATES; i++){
    if(strcmp(state,stateCodes[i])==0){
      stateFound = 1;
      break;
    }
  }
  if(!stateFound){
    printf("Invalid Vehicle Number-Invalid State Code\n");
    return 0;
  }
  if(!isdigit(vehicleNo[2]) || !isdigit(vehicleNo[3])){
    printf("Invalid Vehicle Number-Invalid RTO Code\n");
    return 0;
  }
  numStart = len-4;
  for(i=4; i<numStart; i++){
    if(!isalpha(vehicleNo[i])){
      valid = 0;
      break;
    }
  }
  if(!valid){
    printf("Invalid Vehicle Number-Invalid Series Code\n");
    return 0;
  }
  
  for(i=numStart; i<len; i++){
    if(!isdigit(vehicleNo[i])){
      valid = 0;
      break;
    }
  }
  if(valid)
    printf("Valid Vehicle Number\n");
  else
    printf("Invalid Vehicle Number-Invalid Number Part\n");
    
  return 0;
}
