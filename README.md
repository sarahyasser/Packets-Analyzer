# Packet Analyzer
## Effective Coding - OOP Assignment

### Introduction

This Assignment is an Ethernet Packet Analyzer.

The program is given:
- An input text file that has some Ethernet packets.

The program does the following:

- Read the file into some packets. where each line in the input file represents one packet data.
- Parse each packet into its own fields.
- Write the parsed packets with their fields in an output text file.

There are 2 types of Ethernet Packets:
- Raw Ethernet Packet
- e-CPRI Packets


### UML Diagram

[UML Diagram here]


### How to run the program
The program is managed using CMake.

#### Prerequisites
- CMake
- C++ Compiler (MinGW)

#### Build and Run

Follow these steps to build and run the project:

1. Clone the repository:

    ```bash
    git clone git@github.com:sarahyasser/Packets-Analyzer.git
    cd Packets-Analyzer/Packet Analyzer
    ```

2. Generate the build files using CMake:
    ```bash
    cmake -G "MinGW Makefiles"  -S . -B build
    ```

3. Build the project:
    ```bash
    cd .\build
    make
    ```
4. Run the executable:
    ```bash
    .\PacketsHandler.exe
    ```