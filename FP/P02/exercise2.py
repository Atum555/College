hours = int(input())
minutes = int(input())

# Sanitize inputs
if hours not in range(0,24) or minutes not in range(0,60):
    print("INVALID DATE FORMAT")
    exit()

amPM = "am" if hours < 12 else "pm"
hours = 12 if hours == 0 else hours if hours <= 12 else hours - 12

print(hours, end="")
if minutes:
    print(f":{minutes:02}", end="")
print(f" {amPM}")