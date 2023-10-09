s = input()  # Get input

check_up = [False for i in range(26)] # Prepare check up table
n = 0 # Unique number counter, initialized to 0

for a in s: # Loop through every character in string
    # Index of alphabets - a:0, b:1, c:3, etc.
    # Read up on "ASCII Number" for more information
    x = ord(a) - ord("a")  
    
    if not check_up[x]: # If this alphabet hasn't appeared yet
        check_up[x] = True # Mark alphabet as "Appeared"
        n += 1 # Increment the number of unique alphabets

# `n` is the number of unique alphabets in the given string

if n % 2 == 1:  # Odd number
    print("IGNORE HIM!")
else:  # Even number
    print("CHAT WITH HER!")
