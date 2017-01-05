# 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
# Clarification: Does the whitespace matter? Is the string case sensitive (is God and permutation of dog?)

def CheckPermutationForStrings(str1, str2):
    sorted_str1 = ''.join(sorted(str1))
    sorted_str2 = ''.join(sorted(str2))
    return (sorted_str1 == sorted_str2)

if __name__ == '__main__':
    string_pair = [["abc", "bca"],
                   ["asdfgrteyujghb", "nvbcnjkfghrtihdbfj"],
                   ["asdfghjklpoiuytrewq", "qwertyuioplkjhgfdsa"]]
    for s in string_pair:
        print('Is {} permutation of {}?: {}'.format(s[0], s[1], CheckPermutationForStrings(s[0], s[1])))
