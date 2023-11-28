hh1 = int(input())
mm1 = int(input())
hh2 = int(input())
mm2 = int(input())

abs1 = hh1 *60 + mm1
abs2 = hh2 *60 + mm2

if abs1 == abs2: print("identical times"); exit()
if abs1 < abs2: print(f"{hh1:02d}:{mm1:02d} is before {hh2:02d}:{mm2:02d}"); exit()
if abs1 > abs2: print(f"{hh1:02d}:{mm1:02d} is after {hh2:02d}:{mm2:02d}"); exit()
