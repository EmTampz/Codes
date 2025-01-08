import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import random
import math
import numpy as np

population_size = 500 # initialization; and 2000 pop tested as well

#provided lower boundaries and personally set the upper boundaries
lb_x = -10.0
ub_x = 100
lb_y = -100
ub_y = 10.0


# third function with optimal objective value of 0.0
def f(x,y) :
    term_1 = np.sin(3 * np.pi * x) ** 2
    term_2 = (x - 1) ** 2 * (1 + np.sin(3 * np.pi * y) ** 2)
    term_3 = (y - 1) ** 2 * (1 + np.sin(2 * np.pi * y) ** 2)
    return term_1 + term_2 + term_3
    
#sinusoidal chaotic map
def sinusoidal (x):
    return math.sin(math.pi*x)

def generate_value (lb, ub, chaotic) :
    return lb + (ub-lb) * chaotic


sinusoidal_series_x=[]
sinusoidal_series_y=[]
x = 0.30
y = 0.80

sinusoidal_series_x.append(x)
sinusoidal_series_y.append(y)

#generate chaotic map based on sinusoidal function
for i in range(population_size):
    next_in_series = sinusoidal(sinusoidal_series_x[i])
    sinusoidal_series_x.append(next_in_series)

for i in range(population_size):
    next_in_series = sinusoidal(sinusoidal_series_y[i])
    sinusoidal_series_y.append(next_in_series)

xline=[]
yline=[]
zline=[]

for i in range(population_size):
    value = generate_value(lb_x, ub_x, sinusoidal_series_x[i])
    xline.append(value)

for i in range(population_size):
    value = generate_value(lb_y, ub_y, sinusoidal_series_y[i])
    yline.append(value)

#get the equivalent function value for each pair (x,y)
for i in range(population_size):
    zline.append(f(xline[i], yline[i]))

#graph the function
axl = plt.axes(projection='3d')
axl.scatter3D(xline, yline, zline, c=zline, cmap='hot', s=7)
axl.set_xlabel('x')
axl.set_ylabel('y')
axl.set_zlabel('f')
plt.show()