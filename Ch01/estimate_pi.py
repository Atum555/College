import random
import statistics

neddleNumber = 1000
average = 0.0
standardDeviation = 1
while standardDeviation >= 0.005:
    estimates = []
    for i in range(100):
        hits = 0
        for _ in range(neddleNumber): hits += (random.random()**2 + random.random()**2 <= 1) * 1 
        estimates.append(4.0 * hits / neddleNumber)

    average = sum(estimates) / len(estimates)
    standardDeviation = statistics.stdev(estimates)
    print(f"Pi: {average}, deviation: {standardDeviation}, neddle count: {neddleNumber}")
    neddleNumber *= 2