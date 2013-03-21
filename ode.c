#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float f_prima(x, y, h);
void euler(x&, y&, y_prima&, h, n_pasos);

int main(){

  float h = 0.1;
  int n_pasos = ((1 + h)/h);
  float* x;
  x = malloc(n_pasos*sizeof(float));
  float* y;
  y = malloc(n_pasos*sizeof(float));
  float* y_prima;
  y_prima = malloc(n_pasos*sizeof(float));

  if(!x){
    printf("Problema con memoria");
    exit(1);
  }
  if(!y){
    printf("Problema con memoria");
    exit(1);
  }



}

float f_prima(x, y, h){
     float temp;
     temp = 1 + y*y;
     return temp;
}

void euler(int *x, int *y, int* y_prima, float h, int n_pasos){
  y[0] = 0.0;

  int i;
  for(i = 1; i < n_pasos; i ++){
  y_prima[i] = f_prima(x[i-1], y[i-1]);
  
  x[i] = x[i-1] + h;
  y[i] = y[i-1] + h*(y_prima[1]);

}
   
    
  
}
