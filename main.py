'''
AUTHOR:      Andrej Bartulin
PROJECT:     3x
LICENSE:     Public Domain
DESCRIPTION: Main file for Python version
'''

import sys

def main(mode: int, n: int) -> int:
    start = n
    max = n

    while 1:
        if n == 0 or n == 1:
            break
        
        if n % 2 == 0:
            n //= 2
            print(n)

        else:
            n *= 3
            n +=1
            print(n)

        if mode == 2:
            if n > max:
                max = n

    print("We came to the loop!")
    print(f"Start: {start}, end: {n}, max: {max}.")

    return 0

if __name__ == "__main__":
    if not len(sys.argv) == 3:
        mode = int(input("Enter a mode: "))
        number = int(input("Enter a number: "))

        main(mode, number)

    else:
        main(int(sys.argv[1]), int(sys.argv[2]))
