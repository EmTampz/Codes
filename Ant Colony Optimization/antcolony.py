import random

data = [
    [0,13,45,50,95,15,32,140],
    [15,0,40,44,85,22,43,122],
    [42,35,0,7,42,55,40,145],
    [48,39,10,0,47,58,45,155],
    [105,90,35,42,0,98,100,202],
    [12, 24,52, 55,102,0,35,148],
    [35,42,32,42,102,33,0,112],
    [135,125,142,150,212,150,110,0]  
]

def init_tau(dimension):
    tau = []
    for _ in range(dimension):
        tau.append([1]*(dimension))
    return tau

size =  3
iterations = 10
beta = 2.0
alpha =0.602
dimension = len(data[0])
best_prob = -1.0
t = 1
global_best_tour = 1000
global_best_ant = []

# initialize the pheromone levels to 1 at the start
tau = init_tau(dimension)

# choose starting city of ant
while t < iterations: 
    
    print("iteration: ", t)
    population = []
    
    # state transition rule
    # run through each ant
    # create pop for ant
    for k in range(size):
        J = [i for i in range(dimension)]
        ant = []
        
        # randomly select starting city
        start_city = random.choice(J)
        
        # remove this city from J and add to ant tour
        ant.append(start_city)
        J.remove(start_city)
        
        last_city = start_city
        
        # we loop until we complete the tour, less one because we already have a starting city
        for step in range(dimension-1):
            
            best_prob = -1.0
            sum = 0
            
            # calculate all the probabilities
            for m in range(len(J)):
                sum += tau[last_city][J[m]] * ((1/data[last_city][J[m]])**beta)
            for n in range(len(J)):
                numerator = tau[last_city][J[n]] * ((1/data[last_city][J[n]])**beta)
                probability = numerator / sum
                
                # determine the highest probability and record the city associated with it
                if probability > best_prob:
                    best_prob = probability
                    next_city = J[n]
            
            last_city = next_city
            
            # remove the city from J and add to ant tour
            ant.append(last_city)
            J.remove(last_city)
        
        # append the completed ant to the population
        population.append(ant)
    print("Population: ", population)
    
    # calculate tour length of each ant
    L = []
    for k in range(size):
        ant = population[k]
        tour_length = 0
        for l in range(dimension-1):
            r = ant[l]
            s = ant[l+1]
            
            tour_length += data[r][s]  
        tour_length += data[ant[dimension-1]][ant[0]] 
        L.append(tour_length) 
    
    # fitness values of each ant
    inverted_L = [1/L[i] for i in range(size)]
    
    # determine the best ant in this iteration
    best_tour_now = min(L)
    best_ant_now = population[L.index(max(L))]
    print("Best tour length now: ", best_tour_now)
    print("Best ant now: ", best_ant_now)
    
    # compare iteration best ant with global best ant
    if best_tour_now < global_best_tour:
        global_best_tour = best_tour_now
        global_best_ant = best_ant_now
        print("replaced")
    
    # global pheromone updating rule
    for m in range(dimension):
        for n in range(dimension):
            first_term = (1 - alpha) * tau[m][n]
            second_term = 0
            # run through each ant 
            for o in range(size):
                ant = population[o]
                for p in range(dimension-1):
                    r = ant[p]
                    s = ant[p+1]
                    
                    # this segment of the tour is present in this ant
                    if (m == r and n == s):
                        second_term += inverted_L[o]
                        # don't continue this ant if found because it only appears once
                        break
            tau[m][n] = first_term + second_term
    t += 1

print("Best ant: ", global_best_ant)
print("Best ant tour length: ", global_best_tour)
