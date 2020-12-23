'''
A 64-bit integer can be viewed as an array of 64bits, with the bit at index 0 corresponding to the
least significant bit (LSB), and the bit at index 63 corresponding to the most significant bit (MSB).
Implement code that takes as input a 64-bit integer and swaps the bits at indices i and j.

Hints:
There are a number of ways in which bit manipulations can be accelerated. For example
the expression x & (x - 1) clears the lowest set bit in x, and x & ~(x - 1) extracts
the lowest set bit of x. Here are a few examples: 16&(16-1) = 0,11&(11-1)= 10,20&(20-l) =16,
16&~(16 - 1) = 16, 11&~(11 - 1) = 1, and 20&~(20 - l) = 4.
'''
#O(1)
def swap_bits(x,i,j):
    if ((x >> i) & 1) != ((x >> j) & 1):
        bitmask = (1 << i)|(1 << j)
        x = x ^ bitmask
    return x 

#O(logn)
def binary(x):
    while(x):
        print(x%2,end = " ")
        x = x//2

print("LSB ---------> ----------> ---------> MSB")
binary(20)
print("")
x = swap_bits(20,0,2)
binary(x)