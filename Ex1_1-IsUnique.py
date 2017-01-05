# 1.1 Is Unique: Implement an algprithm to determine if a string has all the unique characters.
# What if you cannot use additional character?
# If we can't usr additional data structures, then, (1) compare each character with every other character
# of the string. This will take O(n²) time
# (2) If we can modify the string, then sort the string in O(nlogn) time and linearly check for identical
# neighbouring characters. Sorting takes extra space
# Clarification: character-set is ASCII (128 characters), Extended ASCII (256 characters),
# and Unicode (2^21 characters). Depending on this the storage space will change

def IsWordUnique(str):
    character_set = set()
    for character in str:
        if character in character_set:
            return False
        character_set.add(character)
    return True

if __name__ == '__main__':
    words = ['qwerfdvcthiyoljsfhjgnvmsasw12!@#$:"',
             'qwertyuiop[]{}asdfghjkl:";']
    for w in words:
        print('Is the input word ({}) unique?: {}'.format(w, IsWordUnique(w)))
