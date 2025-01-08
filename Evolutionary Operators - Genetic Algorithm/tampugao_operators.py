import math
import random

# Ackley function
def ackley(solution):
    a = 20
    b = 0.2
    c = 2 * math.pi
    d = len(solution)
    
    summate_1 = sum([x**2 for x in solution])
    summate_2  = sum([math.cos(c * x) for x in solution])
    term_1 = -a * math.exp(-b * math.sqrt(summate_1  / d))
    term_2 = -math.exp(summate_2 / d)
    
    return term_1 + term_2 + a + math.e

# Generates random decision variable values**
def generate_solution(lb, ub):
    return lb + (ub - lb) * random.random()

# Generates strength of each solution based on fitness values**
def percentages(solution, optimal):
    strength = []
    summation = 0.0
    dimension = len(solution)
    # calculation in the denominator
    for i in range(dimension):
        summation = summation + (1 / abs(solution[i] - optimal))
    # calculates the proportional strength of each solution base on the total strength of all sol'n in the pop.
    for i in range(dimension):
        inverse1 = 1 / abs(solution[i] - optimal)
        inverse2 = summation
        strength.append(inverse1 / inverse2)
    return strength

# Generates percentage range based on percentage strength of each solution**
def generate_wheel(percentages):
    wheel = []
    pair = []
    dimension = len(percentages)
    start = 0.0
    end = percentages[0]
    pair.append(start)
    pair.append(end)
    wheel.append(pair)
    for i in range(dimension):
        pair = []
        if i != 0:
            start = end
            end = start + percentages[i]
            pair.append(start)
            pair.append(end)
            wheel.append(pair)
    return wheel

# Choose index of parent based on random number generated and the range in the wheel**
def select_parent(random_number, wheel):
    dimension = len(wheel)
    for i in range(dimension):
        if random_number > wheel[i][0]:
            if random_number < wheel[i][1]:
                return i + 1
            else:
                continue

# Uniform crossover**
def uniform_crossover(solution1, solution2):
    dimension = len(solution1)
    baby1 = []
    baby2 = []
    for i in range(dimension):
        random1 = random.random()
        random2 = random.random()
        if random1 < 0.5:
            baby1.append(solution1[i])
        else:
            baby1.append(solution2[i])
        if random2 < 0.5:
            baby2.append(solution1[i])
        else:
            baby2.append(solution2[i])
    return baby1, baby2

# Inversion mutation**
def inversion_mutation(solution):
    dimension = len(solution)
    index1 = random.randint(0, dimension - 1)
    index2 = random.randint(0, dimension - 1)
    while index1 == index2:
        index2 = random.randint(0, dimension - 1)
    if index2 < index1:
        temp = index1
        index1 = index2
        index2 = temp
    section = solution[index1:index2 + 1]
    reversed_sec = section[::-1]
    solution[index1:index2 + 1] = reversed_sec
    return solution

# Main - the values are indicated by the lab manual
lb, ub = -32.768, 32.768
dimension = 5
pop_size = 10

# Generate population***
population = []
for j in range(pop_size):
    solution = []
    for i in range(dimension):
        solution.append(generate_solution(lb, ub))
    population.append(solution)
    print(f"solution {j + 1} : {solution}")
    print(f"fitness of solution {j + 1} : {ackley(solution)}\n")

# Calculate fitness values of each solution in the population*** 
sol_fit = []
for i in range(pop_size):
    sol_fit.append(ackley(population[i]))
    # print(f"fitness values {i + 1} : {sol_fit[i]}") 

# Generate strength of each solution based on fitness values**
for_roulette = percentages(sol_fit, 0.0)
# print("strength :", for_roulette)

# Generate percentage range based on percentage strength of each solution and the parent as well**  
percent = generate_wheel(for_roulette)

parent1 = select_parent(random.random(), percent)
print("\nSelected Parents:")
print(f"Selected_parent 1 : {population[parent1 - 1]}")
print(f"fitness of Selected_parent 1 : {ackley(population[parent1 - 1])}")

parent2 = select_parent(random.random(), percent)
print(f"Selected_parent 2 : {population[parent2 - 1]}")
print(f"fitness of Selected_parent 2 : {ackley(population[parent2 - 1])}")

# Crossover
baby1, baby2 = uniform_crossover(population[parent1 - 1], population[parent2 - 1])

print("\nAfter Recombination:")
print(f"baby 1 : {baby1}")
print(f"fitness of baby 1 : {ackley(baby1)}")

print(f"baby 2 : {baby2}")
print(f"fitness of baby 2 : {ackley(baby2)}")

# Mutation
mutated_baby1 = inversion_mutation(baby1)
mutated_baby2 = inversion_mutation(baby2)

print("\nAfter Mutation:")
print(f"Mutated_baby 1 : {mutated_baby1}")
print(f"fitness of Mutated_baby 1 : {ackley(mutated_baby1)}")

print(f"Mutated_baby 2 : {mutated_baby2}")
print(f"fitness of Mutated_baby 2 : {ackley(mutated_baby2)}")