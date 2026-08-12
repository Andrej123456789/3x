# 3x

C/Python program design to play with this [math problem](https://www.youtube.com/watch?v=094y1Z2wpJg).

The Collatz conjecture (also known as 3x+1) states that any positive integer will eventually reach 1 if you repeatedly apply:

- if even → divide by 2
- if odd → multiply by 3 and add 1.

[Latest release - v5.0.0](https://github.com/Andrej123456789/3x/releases/tag/v5.0.0)

## Build & run instructions - C version

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

<details>
<summary>CMake</summary>

| Number: | Step:                                                          | Command:                                          |
| ------- | -------------------------------------------------------------- | ------------------------------------------------- |
| 1       | Clone a repository                                             | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `src` folder                                         | `cd 3x\src`                                       |
| 3       | Create the `build` folder                                      | `mkdir build`                                     |
| 4       | Enter the `build` folder                                       | `cd build`                                        |
| 5       | Run CMake                                                      | `cmake .. -DGMP_ROOT="path_to_vcpkg"`             |
| 6       | Open Visual Studio and build the solution                      |                                                   |
| 7       | Run the program located inside the `Debug` or `Release` folder | `.\Debug\3x.exe` or `.\Release\3x.exe`            |

</details>

<details>
<summary>CMake without Visual Studio</summary>

**Notice! You still need to have Visual Studio with C/C++ development extension installed. Run following commands inside _Developer Command Prompt_ or _Developer Powershell_.**

| Number: | Step:                     | Command:                                                                                                 |
| ------- | ------------------------- | -------------------------------------------------------------------------------------------------------- |
| 1       | Clone a repository        | `git clone https://github.com/Andrej123456789/3x`                                                        |
| 2       | Enter the `src` folder    | `cd 3x\src`                                                                                              |
| 3       | Create the `build` folder | `mkdir build`                                                                                            |
| 4       | Enter the `build` folder  | `cd build`                                                                                               |
| 5       | Run CMake                 | `cmake -G "NMake Makefiles" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl -DGMP_ROOT="path_to_vcpkg" ..` |
| 6       | Compile                   | `nmake`                                                                                                  |
| 7       | Run the program           | `.\3x.exe`                                                                                               |

</details>

### Linux

<details>
<summary>Make</summary>

| Number: | Step:                     | Command:                                          |
| ------- | ------------------------- | ------------------------------------------------- |
| 1       | Clone a repository        | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `src` directory | `cd 3x/src`                                       |
| 3       | Compile                   | `make`                                            |
| 4       | Run the program           | `make run`                                        |

</details>

<details>
<summary>CMake</summary>

| Number: | Step:                        | Command:                                          |
| ------- | ---------------------------- | ------------------------------------------------- |
| 1       | Clone a repository           | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `src` directory    | `cd 3x/src`                                       |
| 3       | Create the `build` directory | `mkdir build`                                     |
| 4       | Enter the `build` directory  | `cd build`                                        |
| 5       | Run CMake                    | `cmake ..`                                        |
| 6       | Compile                      | `make`                                            |
| 7       | Run the program              | `./3x`                                            |

</details>

## Build & run instructions - Python version

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

| Number: | Step:                     | Command:                                          |
| ------- | ------------------------- | ------------------------------------------------- |
| 1       | Clone a repository        | `git clone https://github.com/Andrej123456789/3x` |
| 2       | Enter the `src` directory | `cd 3x/src`                                       |
| 3       | Run the program           | `python main.py` or `python3 main.py`             |

## Resources used

- [GMP tutorial](https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html)
- [`Integer-Comparisons` GNU GMP documentation](https://gmplib.org/manual/Integer-Comparisons)
- [`Integer-Division` GNU GMP documentation](https://gmplib.org/manual/Integer-Division)
