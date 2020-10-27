'''
Kevin and Stuart want to play the 'The Minion Game'.

Game Rules

Both players are given the same string, S .
Both players have to make substrings using the letters of the string S.
Stuart has to make words starting with consonants.
Kevin has to make words starting with vowels.
The game ends when both players have made all possible substrings.

Scoring
A player gets +1 point for each occurrence of the substring in the string .

For Example:
String S = BANANA
Kevin's vowel beginning word = ANA
Here, ANA occurs twice in BANANA. Hence, Kevin will get 2 Points.

Input Format:
A single line of input containing the string .
Note: The string  will contain only uppercase letters: .
Constraints
0<len(s)<10^6
Output Format
Print one line: the name of the winner and their score separated by a space.
If the game is a draw, print Draw.



Sample Input
BANANA

Sample Output
Stuart 12
'''

def minion_game(string):
    vowel = 'AEIOU'
    k=0
    s=0
    for i in range(len(string)):
        if string[i] in vowel:
            k = k + len(string) - i
        else:
            s = s + len(string) - i
    if k>s:
        print("Kevin %d"%k)
    elif s>k:
        print("Stuart %d"%s)
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)