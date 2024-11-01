n = int(input("n:"))
valores = []
for i in range(1, n+1):
    valores.append(int(input(f"value {i}:")))
    
avg = sum(valores)/len(valores)
print(f"Arithmetic mean = {avg:.2f}")
