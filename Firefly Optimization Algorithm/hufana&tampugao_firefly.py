#Hufana_Tampugao
#Firefly Operator

import math
import random
import pandas as pd #

#generates random decision variable values
def griewank_generate(lb,ub):
    return lb + (ub - lb) * random.random()

#accepts solutions 
def griewank(solution):
    summation = 0.0
    product = 1.0
    dimension = len(solution)
    for i in range(dimension):
        summation = summation + (solution[i] * solution[i])/4000
        product = product * math.cos(solution[i] / math.sqrt(i + 1))

    return summation - product + 1


population = []
solution = []
dimension = 5 
pop_size = 10
t = 1 #

#generate population
for k in range(pop_size):
    solution = []
    for i in range(dimension):
        solution.append(griewank_generate(-10, 10))
    population.append(solution)
    print("sol", k + 1, "at t =", t, ": ", population[k]) #aa

fitness_values = []
for k in range(pop_size):
    fitness_values.append(griewank(population[k]))
    print("fitness value ", k + 1, ": ", fitness_values[k])

#

#plot the values in a sorted and unsorted data frames
solfit = []
dec_var = []
for i in range(dimension):
    dec_var.append(str(i + 1))

for k in range(pop_size):
    temp = []
    temp = population[k]
 
    temp.append(fitness_values[k])
    solfit.append(temp)

dec_var.append('fitness')
df = pd.DataFrame(solfit)
df.columns = dec_var
print("\nUnsorted Population")
print(df)

# sort the data frames base on fitness values
sorted_firefly = df.sort_values('fitness')
print("\nSorted Population")
print(sorted_firefly)

#choose the first and last firefly as it's the best and worst in the sorted data frame
x_j_better = (list(sorted_firefly.iloc[0]))[0:dimension] 
x_i_notbetter = (list(sorted_firefly.iloc[pop_size - 1]))[0:dimension]

print("\nMore Attractive: ", x_j_better)
print("Less Attractive: ", x_i_notbetter)


 #improve the attractiveness of the less attractive firefly
summation = 0.0
attractiveness= 2.0 #beta
levy_flight = 2.0  #lambda
light_absorp = 1.0 #gamma
alpha = random.random()

# for beta_0 in [2.0, 10.0]: Test for beta
# for gamma in [1.0, 5.0]: Test for gamma
# for lambda_val in [2.0, 10.0]: #Test for lambda

    
#difference between two fireflies
for k in range(dimension):
    summation = summation + ((x_j_better[k] - x_i_notbetter[k]) * (x_j_better[k] - x_i_notbetter[k]))
r2 = summation

second_partial = attractiveness * math.exp(-1 * light_absorp * r2)

second_term = [second_partial * (a - b) for a, b in zip(x_j_better, x_i_notbetter)]

# part of third term
if(random.random() - 0.50) < 0:
    sign = -1.0
else:
    sign = 1.0

third_partial = alpha * sign * (t ** -levy_flight)  #

third_term = [third_partial * i for i in x_i_notbetter]

new_pos = [a + b + c for a, b, c in zip(x_i_notbetter, second_term, third_term)]
print("\nOld position: ", x_i_notbetter)
print("Old Fitness Value: ", griewank(x_i_notbetter))
print("New position: ", new_pos)
print("New Fitness Value: ", griewank(new_pos))


