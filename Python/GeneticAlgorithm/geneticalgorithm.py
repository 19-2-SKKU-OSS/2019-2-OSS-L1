import random
def gen_individual(length):
    genes=[]
    while len(genes)<length:
        sampleSize=min(length-len(genes),len(geneSet))
        genes.extend(random.sample(geneSet,sampleSize))
    return ''.join(genes)

def get_fitness(guess, target):
    return sum(1 for expected,actual in zip(target,guess) if expected==actual)

def mutate(parent):
    index=random.randrange(0,len(parent))
    childGenes=list(parent)
    newGene,alternate=random.sample(geneSet,2)
    childGenes[index]=alternate if newGene==childGenes[index] else newGene
    return ''.join(childGenes)


def reproduce(x, y):
    n = len(x)
    c = random.randint(1, n-2)
    individual = x[:c] + y[c:]
    return individual

import random
def random_selection_index(fitness):
    sum_fitness = 0
    acc_fitness = []
    for i in fitness:
        sum_fitness += i
        acc_fitness.append(sum_fitness)
        
    roulette = random.randint(1, sum_fitness)
    i = 0
    while roulette > acc_fitness[i]:
        i += 1
    return i

def GA(population, fitness, target, n=2000):
    for k in range(n):
        new_population = []
        new_fitness = []

        for i in range(len(population)):
            x = random_selection_index(fitness)
            y = random_selection_index(fitness)
            child = reproduce(population[x], population[y])
            if random.randint(1, 100) <= 20 :
                child = mutate(child)
            new_population.append(child)
            new_fitness.append( get_fitness(child, target) )

        population = new_population[:]
        fitness = new_fitness[:]
        best_fitness = max(new_fitness)
        if best_fitness >= len(child):
            break

    individual = new_population[fitness.index(best_fitness)]
    return individual

