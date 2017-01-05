# 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
# Clarification: Does the whitespace matter? Is the string case sensitive (is God and permutation of dog?)

def CheckPermutationForStrings1(str1, str2):
    sorted_str1 = ''.join(sorted(str1))
    sorted_str2 = ''.join(sorted(str2))
    return (sorted_str1 == sorted_str2)

def CheckPermutationForStrings2(str1, str2):
    letters = [0] * 128 # Assuming ASCII (128 characters)
    for i in range(len(str1)):
        letters[ord(str1[i])] += 1

    for j in range(len(str2)):
        letters[ord(str2[j])] -= 1

    if sum(letters) != 0:
        return False
    return True

if __name__ == '__main__':
    string_pair = [["abcc", "bca"],
                   ["asdfgrteyujghb", "nvbcnjkfghrtihdbfj"],
                   ["asdfghjklpoiuytrewq", "qwertyuioplkjhgfdsa"]]
    for s in string_pair:
        print('Is {} permutation of {}?: {}'.format(s[0], s[1], CheckPermutationForStrings2(s[0], s[1])))
        #print('Is {} permutation of {}?: {}'.format(s[0], s[1], CheckPermutationForStrings1(s[0], s[1])))
