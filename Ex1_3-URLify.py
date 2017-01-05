# 1.3 URLify: Algorithm to replace all spaces in a string with '%20'. String has sufficient space to hold the special characters. True length of string is passed

def URLify(s, length):
    str = list()
    for x in range(len(s)):
        str.insert(x, s[x])
    spaceCount = 0
    i = 0
    for i in range(length):
        if str[i] == ' ':
            spaceCount += 1

    index = length + spaceCount * 2

    for i in range(length - 1, 0, -1):
        if str[i] == ' ':
            str[index - 1] = '0'
            str[index - 2] = '2'
            str[index - 3] = '%'
            index -= 3
        else:
            str[index - 1] = str[i]
            index -= 1

    print(''.join(str))

if __name__ == '__main__':
    URLify("My John Smith        ", 13)
