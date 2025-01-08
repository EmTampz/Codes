import random

# Simplified data for 5 cities (indexed 1-5, but we'll use 0-based indexing internally)
# Adding a row/column of zeros at index 0 to make the indexing match the city numbers
data = [
    [0, 0, 0, 0, 0, 0],  # dummy row/column for 0 index
    [0, 0, 5, 7, 2, 1],
    [0, 5, 0, 8, 5, 3],
    [0, 7, 8, 0, 10, 3],
    [0, 2, 5, 10, 0, 4],
    [0, 1, 3, 3, 4, 0]
]      

def init_tau(dimension):
    """Initialize pheromone levels to 1.0"""
    tau = []
    for _ in range(dimension):
        tau.append([1.0] * dimension)
    return tau

def calculate_probability(tau, data, current_city, next_city, J, beta):
    """Calculate probability for moving from current_city to next_city"""
    numerator = tau[current_city][next_city] * ((1/data[current_city][next_city])**beta)
    denominator = 0
    for j in J:
        denominator += tau[current_city][j] * ((1/data[current_city][j])**beta)
    return numerator/denominator if denominator != 0 else 0

def print_probability_details(ant_num, current_city, J, probs):
    """Print detailed probability calculations for an ant"""
    # Convert J to 1-based indexing for display
    J_display = [j for j in J]
    print(f"\nGenerating path for Ant {ant_num}")
    print(f"Ant {ant_num} = {{{current_city}}} J{ant_num}({current_city}) = {{{','.join(map(str, J_display))}}}")
    
    print("\nProbabilities:")
    for city, prob in probs:
        print(f"p{ant_num}({current_city},{city}) = {prob:.4f}")
    
    print("\nTable of Probabilities:")
    for city, prob in probs:
        print(f"City {current_city} to City {city}: {prob:.4f}")

def main():
    size = 3  # number of ants
    beta = 2.0
    letter_position = 20  
    alpha = 0.60 + (letter_position * 0.01)
    
    dimension = 6  # including the dummy index 0
    tau = init_tau(dimension)
    
    # Assign different starting cities to each ant (using cities 1-5)
    start_cities = random.sample(range(1, 6), size)
    population = []
    tour_lengths = []
    
    for k in range(size):
        ant = []
        current_city = start_cities[k]
        ant.append(current_city)
        J = list(range(1, 6))  # Cities 1-5
        J.remove(current_city)
        
        while J:
            probs = []
            for next_city in J:
                prob = calculate_probability(tau, data, current_city, next_city, J, beta)
                probs.append((next_city, prob))
            
            print_probability_details(k+1, current_city, J, probs)
            
            # Choose next city based on highest probability
            next_city = max(probs, key=lambda x: x[1])[0]
            ant.append(next_city)
            J.remove(next_city)
            current_city = next_city
            
            print(f"Decision: Ant {k+1} chooses to go from City {current_city} to city {next_city}")
            print(f"Updated Ant {k+1} tour is {ant}")
            print(f"Updated J{k+1}({current_city}) = {{{','.join(map(str, J))}}}\n")
        
        # Calculate tour length
        tour_length = 0
        for i in range(len(ant)-1):
            tour_length += data[ant[i]][ant[i+1]]
        tour_length += data[ant[-1]][ant[0]]  # Return to start
        tour_lengths.append(tour_length)
        population.append(ant)
        
        print(f"The length of tour of Ant {k+1} is: {tour_length}\n")
    
    # Update pheromones
    print("\nUpdating Taus:")
    for i in range(1, dimension):  # Start from 1 to skip dummy index
        for j in range(1, dimension):
            if i != j:
                first_term = (1 - alpha) * tau[i][j]
                second_term = sum(1/tour_lengths[k] for k in range(size) 
                                if (i in population[k] and j in population[k]))
                new_tau = first_term + second_term
                print(f"tau({i},{j}) = (1 - {alpha:.3f}) * {tau[i][j]:.3f} + {second_term:.3f} = {new_tau:.3f}")
                tau[i][j] = new_tau
    
    # Determine best ant
    best_ant_idx = tour_lengths.index(min(tour_lengths))
    print("\nCONCLUSION ON WHICH ANT IS BETTER FOR ITERATION")
    print(f"Ant {best_ant_idx + 1} is the most desirable with tour length {tour_lengths[best_ant_idx]}")
    print(f"This ant's tour: {population[best_ant_idx]}")

if __name__ == "__main__":
    main()