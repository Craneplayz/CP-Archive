s = input() # Get input

# Insert all characters in string `s` to a set
# This extracts all the unique alphabets from the original string
alphabets = {x for x in s} 

# The size of the set is the number of unique alphabets
n = len(alphabets)

if n%2 == 1: # Odd number
    print("IGNORE HIM!")
else: # Even number
    print("CHAT WITH HER!")
