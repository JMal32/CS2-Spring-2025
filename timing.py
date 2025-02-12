import time

def timeSumOfN(n):
    start = time.time()
    theSum = 0
    for i in range(1, n + 1):
        theSum = theSum + i

    end = time.time()
    return end-start

def main():
    ITS = 5
    N = 1000000
    for LEN in [N, N*5, N*10]:
        tot = 0
        for i in range(ITS):
            tot = tot + timeSumOfN(LEN)
        print("Summation up to %d required %10.7f seconds" % (LEN, tot/ITS))
main()
