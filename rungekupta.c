#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float f_prima_1(float y1, float y2);
float f_prima_2(float y1, float y2);
void rungeKuttaCuartoOrden(float* x, float *y, float h, int n_pasos);

int main(){

  float h = 0.1;
  int n_pasos = ((1 + h)/h);
  float* x;
  float* y_1;
  float* y_2;
  float* y_prima_1;
  float* y_prima_2;
 
  x = malloc(n_pasos*sizeof(float));  
  y_1 = malloc(n_pasos*sizeof(float));
  y_2 = malloc(n_pasos*sizeof(float));
  y_prima_1 = malloc(n_pasos*sizeof(float));

  y_prima_2 = malloc(n_pasos*sizeof(float));

  if(!x || !y_1 || !y_2 || !y_prima_1 || !y_prima_2){
    printf("Problema con memoria");
    exit(1);
  }
 
}


float f_prima_1(float y1, float y2){
     return y2;
}

float f_prima_2(float y1, float y2){
     return -4.0*y1;
}

void rungeKuttaCuartoOrden(int *x, int *y, float h, int n_pasos){
  //Condiciones iniciales
  y[0] = 0.0;

  int i;
  float k1;
  float k2;
  float k3;
  float k4;
  float promedio_k;
  float x1;
  float x2;
  float x3;
  float y1;
  float y2;
  float y3;

  for(i = 1; i < n_pasos; i ++){

  k1 = f_prima_1(y[i-1]);

  //Primer paso
  
  x1 = x[i-1] + (h/2.0);
  y1 = y[i-1] + (h/2.0)*k1;

  k2 = f_prima_1(y1);

  //Segundo paso

  x2 = x[i-1] + (h/2.0);
  y2 = y[i-1] + (h/2.0)*k2;

  k3 = f_prima_1(y2);

  //Tercer paso

  x3 = x[i-1] + (h/2.0);
  y3 = y[i-1] + (h/2.0)*k3;

  k4 = f_prima_1(y3);
  
  //Cuarto paso

  promedio_k = (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);

  x[i] = x[i-1] + h;
  y[i] = y[i-1] + h*promedio_k;
 

}
   
    
  
}
