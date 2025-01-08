import random
import numpy as np
import matplotlib.pyplot as plt
import time

def f(w, x, y, z):
    return w**3 + x**2 - y**2 - z**2 + 2 + y * z - 3 * 2 * x + w * z - x * y + 2

    # convert the number into list of bits
def bin_to_dec(list_bin):
    decimal = 0
    for i in range(len(list_bin)):
        digit = list_bin.pop()
        if digit == '1':
            decimal += pow(2, i)
    return decimal

def evaluation(solution):
    # evaluate the solution

    w = bin_to_dec(solution[0:4].copy())
    x = bin_to_dec(solution[4:8].copy())
    y = bin_to_dec(solution[8:12].copy())
    z = bin_to_dec(solution[12:16].copy())
    return f(w, x, y, z)
def generate_popn(n):

    population = []
    for i in range(n):
        solution = []
        w = []
        x = []
        y = []
        z = []
        # gegnerate for w
        for i in range(4):
            if random.random() < 0.5:
                w.append('1')
            else:
                w.append('0')
        # gegnerate for x
        for i in range(4):
            if random.random() < 0.5:
                x.append('1')
            else:
                x.append('0') 
        # gegnerate for y
        for i in range(4):
            if random.random() < 0.5:
                y.append('1')
            else:
                y.append('0')
        # gegnerate for z
        for i in range(4):
            if random.random() < 0.5:
                z.append('1')
            else:
                z.append('0')
                
        solution=(w+x+y+z)
        population.append(solution)
    return (population)

def averaging(added, fitness):
    increased = [x + added for x in fitness]
    average = sum(increased) / len(increased)
    return [x / average for x in increased]

# single point crossover
def substring_swap(solution1, solution2):
    dimension = len(solution1)
    index1 = random.randint(1, dimension - 1)
    baby1 = solution1[:index1] + solution2[index1:]
    baby2 = solution2[:index1] + solution1[index1:]
    return baby1, baby2

def mutation(solution):
    dimension = len(solution)
    index1 = random.randint(0,dimension-1)
    new_sol = solution
    if new_sol[index1] == '1':
        new_sol[index1] = '0'
    else:
        new_sol[index1] = '1'
    return new_sol

# generate the percentage range based on percentage strenght of each solution
def generate_wheel(percentages):
    wheel = []
    start = 0.0
    for percentage in percentages:
        end = start + percentage
        wheel.append([start, end])
        start = end
    return wheel

# choose index of parent based on random number generated and the range in the r wheel
def select_parent(random_number, wheel):
    for i, (start, end) in enumerate(wheel):
        if start <= random_number < end:
            return i + 1
    return len(wheel)

def genetic_algorithm(generations, n, mutation_rate, added=2000):
    popn = generate_popn(n)
    fitness_value = [evaluation(sol) for sol in popn]
    index_best = np.argmax(fitness_value)
    super_best_solution = popn[index_best]
    super_best_fitness = max(fitness_value)
    super_best_time = 0
    all_fitness = [super_best_fitness]
    start_time = time.time()
    
    # generation/loop
    for j in range(generations):
        ave = averaging(added, fitness_value)
        percentage = [x / sum(ave) for x in ave]
        wheel = generate_wheel(percentage)

        new_popn = []
         # select parents
        for _ in range(int(n / 2)):  #we do the recombination for half  the number of solutions
          # every recombination will produce 2 babies
            parent1 = select_parent(random.random(), wheel)
            parent2 = select_parent(random.random(), wheel)

            babe1, babe2 = substring_swap(popn[parent1 - 1], popn[parent2 - 1])
            new_popn.append(babe1)
            new_popn.append(babe2)

        fitness_value = [evaluation(sol) for sol in new_popn]

        for i in range(n):
            if random.random() < mutation_rate:
                new_popn[i] = mutation(new_popn[i])

        popn = new_popn
        fitness_value = [evaluation(sol) for sol in popn]

            # determine the best in this generation
        index_best = np.argmax(fitness_value)
        best_solution_this_gen = popn[index_best]
        best_fitness_this_gen = max(fitness_value)

        
    # compare with overall best
        current_time = time.time() - start_time
        if best_fitness_this_gen > super_best_fitness:
            super_best_fitness = best_fitness_this_gen
            super_best_solution = best_solution_this_gen
            super_best_time = current_time
            # Print only when a new best is found
            print(f"Time and generation at which best was found: {float(super_best_time):.5f}s at Gen {j}")

        all_fitness.append(super_best_fitness)

    # Plot the progression of fitness over generations
    plt.plot(all_fitness)
    plt.xlabel('Generation No.')
    plt.ylabel('Best Fitness Value')
    plt.title('Genetic Algorithm Performance')
    plt.show()

    return super_best_solution, super_best_fitness, super_best_time, all_fitness

# Run experiments
experiments = [(100, 50), (100, 100), (500, 50), (500, 100)]
for gen, n in experiments:
    print(f"\nRunning experiment: Generations={gen}, Population Size={n}")
    best_solution, best_fitness, best_time, all_fitness = genetic_algorithm(gen, n, mutation_rate=0.8)
    print(f"Best solution: {best_solution}")
    print(f"Best fitness: {best_fitness}")
    print(f"All fitness values: {all_fitness}")
