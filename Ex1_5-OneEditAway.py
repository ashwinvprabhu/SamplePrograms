# 1.5 One Away: Given two string, check if they are one or zero edits away
# Implementation: Need to determine how many letters in the two string are string are different.
# In case of insertion and deletion, one string is shorter by one than the other.
# In case of replacement, both strings are of same length, but one or no charater is different

def OneEditAway(first, second):
    if len(first) == len(second):
        return OneEditReplace(first, second)
    elif abs(len(first) - len(second)) == 1:
        return OneEditInsert(first, second)

def OneEditReplace(first, second):
    foundDifference = False
    for i in range(len(first)):
        if first[i] != second[i]:
            if foundDifference:
                return False
            foundDifference = True
    return True

def OneEditInsert(first, second):
    s1 = first if len(first) < len(second) else second
    s2 = second if len(first) < len(second) else first
    index1 = 0
    index2 = 0

    while index1 < len(s1) and index2 < len(s2):
        if s1[index1] != s2[index2]:
            if index1 != index2:
                return False
            index2 += 1
        else:
            index1 += 1
            index2 += 1
    return True

if __name__ == '__main__':
    list_of_strings = [["pale", "bale"],
                       ["pale", "pales"],
                       ["pale", "ple"],
                       ["pale", "bae"],
                       ["abcc", "deff"],
                       ["fff", "ddddddddddddd"]]
    for pairs in list_of_strings:
        if OneEditAway(pairs[0], pairs[1]):
            print("Strings {} and {} are one edit away".format(pairs[0], pairs[1]))
        else:
            print("Strings {} and {} are not one edit away".format(pairs[0], pairs[1]))
