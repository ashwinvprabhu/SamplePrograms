# 1.9 String Rotation: Algorithm to check if the first string is a piglatin of second string
# string1 = water, string2 = erwat

def IsRotate(str1, str2):
    if len(str1) == len(str2) and len(str1) > 0:
        s1s1 = str1 + str1
        return str2 in str1

if __name__ == '__main__':
    str1 = "waterbottle"
    str2 = "erbottlewat"
    print("{} substring of {}".format(str1, str2, IsRotate(str1, str2)))
