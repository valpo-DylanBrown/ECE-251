#include <stdio.h>
#include <string.h>
#define LINESIZE 120

int main(){
  FILE *afp, *bfp = NULL;
  afp = fopen("courseList.txt","r");
  bfp = fopen("output.txt", "w");
  int loop;
  int course;
  char department[4];
  char section;
  int startTime, startTimeHour, startTimeMin;
  int endTime, endTimeHour, endTimeMin;
  char day1[2];
  char ch;
  char room[10];
  char lastName[25];
  char firstName[25];
  int roomNumber;
  char term[10];
  int year;
  int k=0;
  int isL = 0;
  char* tok1;
  char* tok2;
  char* tok3;
  char* tok4;
  char* tok5;
  char* tok6;
  char line[LINESIZE];
  fscanf(afp, "%d", &loop);
  //printf("LOOP: %d", loop);
  while((ch = fgetc(afp))!= EOF){
      fprintf(bfp,"==============================\n");
      fgets(line, LINESIZE, afp);
      //printf("%s", line);
      tok1 = strtok(line, " /");
      //printf("%s\n", tok1);
      tok2 = strtok(NULL, "/");
      //printf("%s\n", tok2);
      tok3 = strtok(NULL, "/");
      //printf("%s\n", tok3);
      tok4 = strtok(NULL, "/");
      //printf("%s\n", tok4);
      tok5 = strtok(NULL, "/");
      //printf("%s\n", tok5);
      tok6 = strtok(NULL, "\n");
      //printf("%s\n", tok6);

      sscanf(tok1,"%[A-Z] %d %c\n", department, &course, &section);
      if(section == 'L'){
        for(int i = 0; i<=strlen(tok1);i++){
          //printf("isL: %d", isL);
          //printf(" tok1: %s", tok1);
          if(isL == 1){
            section = tok1[i];
            break;
          }
          if (tok1[i] == 'L'){
            isL = 1;
          }
        }
        fprintf(bfp, "Course: %s %d Lab Section %c\n", department, course, section);
      }
      else{
        fprintf(bfp, "Course: %s %d Section %c\n", department, course, section);
      }
      sscanf(tok2,"%d - %d",&startTime, &endTime);
      startTimeHour = startTime/100;
      startTimeMin = startTime%100;
      endTimeHour = endTime/100;
      endTimeMin = endTime%100;
      fprintf(bfp,"Time: ");
      if(startTimeHour >= 12){
        if(startTimeHour == 12){
          fprintf(bfp,"%d:%02d PM - ", startTimeHour, startTimeMin);
        }
        else{
          fprintf(bfp,"%d:%02d PM - ", startTimeHour-12, startTimeMin);
        }

      }
      else{
        fprintf(bfp,"%d:%02d AM - ", startTimeHour, startTimeMin);
      }
      if(endTimeHour >= 12){
        if(endTimeHour == 12){
          fprintf(bfp,"%d:%02d PM\n", endTimeHour, endTimeMin);
        }
        else{
          fprintf(bfp,"%d:%02d PM\n", endTimeHour-12, endTimeMin);
        }
      }
      else{
        fprintf(bfp, "%d:%02d AM\n", endTimeHour, endTimeMin);
      }
      sscanf(tok3, "%[MTWRFS]", day1);
      //printf("day 1:%s\n", day1);
      fprintf(bfp,"Days: ");
      for (int i = 0; i<=strlen(day1); i++){
          if (day1[i] == 'M'){
            fprintf(bfp,"Monday ");
          }
          if (day1[i] == 'T'){
            fprintf(bfp, "Tuesday ");
          }
          if (day1[i] == 'W'){
            fprintf(bfp,"Wednesday ");
          }
          if (day1[i] == 'R'){
            fprintf(bfp,"Thursday ");
          }
          if (day1[i] == 'F'){
            fprintf(bfp, "Friday ");
          }
          if (day1[i] == 'S'){
            fprintf(bfp,"Saturday ");
          }
      }
      fprintf(bfp, "\n");
      sscanf(tok4,"%[A-Z] %d", room, &roomNumber);
      fprintf(bfp,"Room: %s %d\n", room, roomNumber);
      sscanf(tok5, "%[a-zA-Z], %[a-zA-Z]", lastName, firstName);
      fprintf(bfp,"Professor: %s %s\n", firstName, lastName);
      sscanf(tok6, "%[a-zA-Z], %d", term, &year);
      fprintf(bfp,"Semester: %s %d\n", term, year);
      //fprintf(bfp,"==============================\n");
      k++;
      if(k==loop){
        fprintf(bfp,"==============================\n");
        break;
      }
  }
}
