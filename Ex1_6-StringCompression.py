# 1.6 A method to perform basic string compression using the counts of repeated characters

def CountCompression(str):
    compressLength = 0
    countConsecutive = 0
    for i in range(len(str)):
        countConsecutive += 1
        if (i + 1 >= len(str) or str[i] != str[i + 1]):
            compressLength += 1 + len(countConsecutive.__str__())
            countConsecutive = 0
    return compressLength

def Compress(str):
    finalLength = CountCompression(str)
    if finalLength >= len(str):
        return str

    compressed = ""
    countConsecutive = 0
    for i in range(len(str)):
        countConsecutive += 1
        if (i + 1 >= len(str) or str[i] != str[i + 1]):
            compressed = ''.join(compressed + str[i])
            compressed = ''.join(compressed + countConsecutive.__str__())
            countConsecutive = 0
    return compressed

if __name__ == '__main__':
    str = ["aaasssddccffvvvvttyyyy", "ssddeeeewwqtghyyyyyy"]
    for s in str:
        compressed = Compress(s)
        print("Compressed string of {} is {}".format(s, compressed))
