#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265f
float calcAreaTriangle(float s1, float s2, float s3){
  float s;
  float triArea;
  s = (s1+s2+s3)/2;
  triArea = sqrt(fabsf(s*(s-s1)*(s-s2)*(s-s3)));
  return triArea;
}
float calcAreaRectangle(float length, float height){
  float recArea;
  recArea = length * height;
  return recArea;
}
float calcAreaCircle(float radius){
  float circArea;
  circArea = PI*radius*radius;
  return circArea;
}
float calcPerimeterTriangle(float s1, float s2, float s3){
  float triPeri;
  triPeri = s1+s2+s3;
  return triPeri;
}
float calcPerimeterRectangle(float length, float height){
  float recPeri;
  recPeri = length+length+height+height;
  return recPeri;
}
float calcPerimeterCircle(float radius){
  float circPeri;
  circPeri = 2*PI*radius;
  return circPeri;
}
