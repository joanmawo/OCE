import numpy as np


h = 0.1
n_points = ((1.0 + h)/h)
x = []
y = []

def func_prime(x, y):
    return 1 + y**2

y[0] = 0.0

#Metodo de Euler
for i in range(1, n_points):
    y_prime = func_prime(x[i-1], y[i-1])

    x[i] = x[i-1] + h
    y[i] = y[i-1] + h*y_prime


#Metodo de Runge-Kutta orden 2
for i in range(1, n_points):
    y_prime = func_prime(x[i - 1], y[i - 1])

    x_middle = x[i - 1] + (h/2.0)
    y_middle = y[i - 1] + (h/2.0)*y_prime

    y_middle_prime = func_prime(x_middle, y_middle)
    
    x[i] = x[i - 1] + h
    y[i] = y[i - 1] + h*y_middle_prime

#Metodo de Runge-Kutta orden 4
for i in range(1, n_points):
    k1 = func_prime(x[i-1],y[i-1])
    
    #first step
    x1 = x[i-1] + (h/2.0)
    y1 = y[i-1] + (h/2.0) * k1
    k2 = func_prime(x1, y1)
    
    #second step
    x2 = x[i-1] + (h/2.0)
    y2 = y[i-1] + (h/2.0) * k2
    k3 = func_prime(x2, y2)
        
    #third step
    x3 = x[i-1] + h
    y3 = y[i-1] + h * k3
    k4 = func_prime(x3, y3)
    
    #fourth step
    average_k = (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4)
    
    x[i] = x[i-1] + h
    y[i] = y[i-1] + h * average_k




    
   
