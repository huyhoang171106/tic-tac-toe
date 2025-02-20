# Tic-Tac-Toe in C++

A simple command-line Tic-Tac-Toe game built in C++ with AI difficulty levels.

## Features
- Play against an AI with **Easy** and **Medium** difficulty.
- Smart AI that blocks winning moves.
- User-friendly interface in the console.

## Getting Started

### **Prerequisites**
Make sure you have a **C++ compiler** installed:
```sh
# For Linux/macOS
sudo apt install g++  # Ubuntu/Debian
brew install gcc       # macOS

# For Windows
Download MinGW from https://www.mingw-w64.org/
```

### **Installation**
Clone the repository:
```sh
git clone https://github.com/huyhoang171106/tic-tac-toe.git
cd tic-tac-toe/src
```

### **Build and Run**
Compile the program:
```sh
g++ main.cpp -o tic_tac_toe
./tic_tac_toe
```

Or use `Makefile` (if included):
```sh
make
./tic_tac_toe
```

## **How to Play**
1. Run the game.
2. Choose your marker (`X` or `O`).
3. Select difficulty level (Easy/Medium).
4. Enter a number (1-9) to place your marker.
5. Win by making a row, column, or diagonal.

## **File Structure**
```
tic-tac-toe/
│── src/
│   ├── main.cpp  # The main game logic
│── README.md     # Game documentation
│── .gitignore    # Ignore compiled files
│── LICENSE       # Open-source license
│── Makefile      # Compilation script (if needed)
```

## **License**
This project is licensed under the MIT License.

## **Contributing**
Pull requests are welcome. Open an issue for suggestions!

## **Author**
- [huyhoang171106](https://github.com/huyhoang171106)
