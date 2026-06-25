# 3x

C/Python program design to play with this [math problem](https://www.youtube.com/watch?v=094y1Z2wpJg).

The Collatz conjecture (also known as 3x+1) states that any positive integer will eventually reach 1 if you repeatedly apply:

- if even → divide by 2
- if odd → multiply by 3 and add 1.

## Compile - C version

## Installing dependencies

### Windows

- Git
- Visual Studio with C/C++ development extension
- CMake
- GMP (x64 static version from vcpkg)

### Linux

| Package: | Command:                                                                                                                      |
| -------- | ----------------------------------------------------------------------------------------------------------------------------- |
| git      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install git`</td><td>`pacman -S git`</td></tr></table>         |
| make     | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install make`</td><td>`pacman -S make`</td></tr></table>       |
| gcc      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install gcc`</td><td>`pacman -S gcc`</td></tr></table>         |
| gmp      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install libgmp3-dev`</td><td>`pacman -S gmp`</td></tr></table> |

## Compiling & running

### Windows

| Number: | Step:                                                          | Command:                                          |
| ------- | -------------------------------------------------------------- | ------------------------------------------------- |
| 1       | Clone a repository                                             | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `3x` directory                                       | `cd 3x`                                           |
| 3       | Create the `build` directory and enter it                      | `mkdir build && cd build`                         |
| 4       | Run CMake                                                      | `cmake .. -DGMP_ROOT="path_to_vcpkg"`             |
| 5       | Open Visual Studio and build the solution                      |                                                   |
| 6       | Run the program located inside the `Debug` or `Release` folder | `.\Debug\3x.exe` or `.\Release\3x.exe`            |

**Notice! In order to not use Visual Studio (you still need to have it installed), you can use nmake. Run CMake with the following command: `cmake -G "NMake Makefiles" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl -DGMP_ROOT="path_to_vcpkg" ..`. To compile the project use command `nmake`. You need to be inside *Developer Command Prompt* or *Developer Powershell*.****

### Linux

| Number: | Step:                    | Command:                                          |
| ------- | ------------------------ | ------------------------------------------------- |
| 1       | Clone a repository       | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `3x` directory | `cd 3x`                                           |
| 3       | Compile                  | `make`                                            |
| 4       | Run the program          | `make run`                                        |

## Compile - Python version

## Installing dependencies

### Windows

- Git
- Python3

### Linux

| Package: | Command:                                                                                                                     |
| -------- | ---------------------------------------------------------------------------------------------------------------------------- |
| git      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install git`</td><td>`pacman -S git`</td></tr></table>        |
| python   | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install python3`</td><td>`pacman -S python`</td></tr></table> |

## Running

| Number: | Step:                    | Command:                                          |
| ------- | ------------------------ | ------------------------------------------------- |
| 1       | Clone a repository       | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `3x` directory | `cd 3x`                                           |
| 3       | Run the program          | `python main.py` or `python3 main.py`             |

## Resources used

- [GMP tutorial](https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html)
- [`Integer-Comparisons` GNU GMP documentation](https://gmplib.org/manual/Integer-Comparisons)
- [`Integer-Division` GNU GMP documentation](https://gmplib.org/manual/Integer-Division)
