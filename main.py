'''
AUTHOR:      Andrej Bartulin
PROJECT:     3x
LICENSE:     Public Domain
DESCRIPTION: Main file for Python version
'''

import sys

def main(mode: int, n: int) -> int:
    previous = 0;
    max = n;
    starter = n;

    if mode == 1:
        while 1:
            if n == 1:
                break
            
            if n % 2 == 0:
                n = n / 2
                print(n)

            else:
                n = n * 3 + 1
                print(n)

        print(f"We come to the loop. Number n at start was {starter}, now is: {n}.")

    elif mode == 2:
        while 1:
            if n == 1:
                break

            if n % 2 == 0:
                n = n / 2
                print(n)

            else:
                n = n * 3 + 1
                print(n)

            if n > max:
                max = n
                
            previous = n

        print(f"We come to the loop. Number n at start was: {starter}, now is: {n}. Max is: {max}.")

    else:
        print(f"Wrong mode {mode}! Exiting with value 1...")
        return 1

    return 0

if __name__ == "__main__":
    if not len(sys.argv) == 3:
        print("Argument error")
        mode = int(input("Enter mode: "))
        number = int(input("Enter mode: "))

        main(mode, number)

    main(int(sys.argv[1]), int(sys.argv[2]))