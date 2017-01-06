# 1.4 Palindrome Permutation: Check if the permutation of the string is a palindrome
# Insight into solution: Using a bit vector, we can map each letter present in the string to a bit position in the vector (0-26). Every time a character
# is encountered, the value at the bit position is toggled. The final value of the bit position can have 1 at atmost one position (in case of odd numbered
# string, odd character will be in the middle, and in case of even numbered string, all characters appears in multiples of 2 times).

def CheckExactlyOneBitSet(bitVector):
    return ((bitVector & (bitVector - 1)) == 0)

def Toggle(bitVector, index):
    if index < 0:
        return bitVector
    mask = 1 << index
    if (bitVector & mask) == 0:
        bitVector |= mask
    else:
        bitVector &= ~mask
    return bitVector

def CreateBitVector(str):
    characters = list()
    bitVector = 0
    for x in range(len(str)):
        characters.insert(x, str[x])
    for chr in characters:
        x = GetCharNumber(chr)
        bitVector = Toggle(bitVector, x)
    return bitVector

def GetCharNumber(c):
    a = ord('a')
    z = ord('z')
    numeric_c = ord(c)
    if (a <= numeric_c and numeric_c <= z):
        return numeric_c - a
    return -1

def IsPermutationPalindrome(str):
    bitVector = CreateBitVector(str)
    return (bitVector == 0 or CheckExactlyOneBitSet(bitVector))

if __name__ == '__main__':
    str = ["Tact Coaa", "Tact Coa", "ABcvtbavc"]
    for word in str:
        word = word.lower()
        if IsPermutationPalindrome(word):
            print('Permutation of "{}" is a palindrome'.format(word))
        else:
            print('Permutation of "{}" is not a palindrome'.format(word))
