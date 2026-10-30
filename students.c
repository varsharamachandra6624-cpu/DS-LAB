#include<stdio.h>
#include<stdlib.h>
struct Student{
  int roll;
  char name[30];
  float marks;
};
void displayAll(struct Student *ptr, int n){
  int i;
  printf("\nRoll\tName\t\tMarks\n");
  printf("---------------------------------------\n");
  for(i=0;i<n;i++){
    printf("%d\t%s\t\t%.2f\n",(ptr+i)->roll,(ptr+i)->name,(ptr+i)->marks);
  }
}
int main(){
  int n,i;
  printf("enter number of students:");
  scanf("%d",&n);
  struct Student *students=(struct Student *)malloc(n*sizeof(struct Student));
  if(students==NULL){
    printf("Memory allocation failed\n");
    return 1;
  }
  for(i=0;i<n;i++){
    printf("\nenter roll number:");
    scanf("%d",&(students+i)->roll);
    printf("\nenter name:");
    scanf("%29s",(students+i)->name);
    printf("\nenter marks:");
    scanf("%f",&(students+i)->marks);
  }
  displayAll(students,n);
  
  free(students);
  return 0;
}
