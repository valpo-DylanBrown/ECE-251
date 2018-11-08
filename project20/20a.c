#include <stdio.h>
#include <string.h>
#define LINESIZE 120
int main(){
  FILE *afp, *bfp = NULL;
  afp = fopen("courseList.txt","r");
  bfp = fopen("output.txt", "w");
  int loop, course, roomNumber, isL, year, k;
  char department[4];
  char section, ch;
  int startTime, startTimeHour, startTimeMin;
  int endTime, endTimeHour, endTimeMin;
  char day[2], room[10],lastName[25],firstName[25],term[10];
  char *tok1, *tok2, *tok3, *tok4, *tok5, *tok6;
  char line[LINESIZE];
  fscanf(afp, "%d", &loop);
  while((ch = fgetc(afp))!= EOF){
      fprintf(bfp,"==============================\n");
      fgets(line, LINESIZE, afp);
      tok1 = strtok(line, " /");
      tok2 = strtok(NULL, "/");
      tok3 = strtok(NULL, "/");
      tok4 = strtok(NULL, "/");
      tok5 = strtok(NULL, "/");
      tok6 = strtok(NULL, "\n");
      sscanf(tok1,"%[A-Z] %d %c\n", department, &course, &section);
      if(section == 'L'){
        for(int i = 0; i<=strlen(tok1);i++){
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
      sscanf(tok3, "%[MTWRFS]", day);
      //printf("day 1:%s\n", day);
      fprintf(bfp,"Days: ");
      for (int i = 0; i<=strlen(day); i++){
          if (day[i] == 'M'){
            fprintf(bfp,"Monday ");
          }
          if (day[i] == 'T'){
            fprintf(bfp, "Tuesday ");
          }
          if (day[i] == 'W'){
            fprintf(bfp,"Wednesday ");
          }
          if (day[i] == 'R'){
            fprintf(bfp,"Thursday ");
          }
          if (day[i] == 'F'){
            fprintf(bfp, "Friday ");
          }
          if (day[i] == 'S'){
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
  return 0;
}
