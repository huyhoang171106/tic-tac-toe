#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char player_marker, bot_marker;
int difficulty;

void drawBoard() {
    cout << "\nTic-Tac-Toe\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int position, char marker) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = marker;
        return true;
    }
    return false;
}

bool checkWin(char marker) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == marker && board[i][1] == marker && board[i][2] == marker) return true;
        if (board[0][i] == marker && board[1][i] == marker && board[2][i] == marker) return true;
    }
    if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker) return true;
    if (board[0][2] == marker && board[1][1] == marker && board[2][0] == marker) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Easy AI: Random moves
int botEasy() {
    int pos;
    do {
        pos = rand() % 9 + 1;
    } while (!placeMarker(pos, bot_marker));
    return pos;
}

// Medium AI: Blocks player if about to win, otherwise random move
int botMedium() {
    for (int i = 1; i <= 9; i++) {
        if (placeMarker(i, bot_marker)) {
            if (checkWin(bot_marker)) return i;
            board[(i - 1) / 3][(i - 1) % 3] = '0' + i; // Undo
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (placeMarker(i, player_marker)) {
            if (checkWin(player_marker)) {
                board[(i - 1) / 3][(i - 1) % 3] = bot_marker;
                return i;
            }
            board[(i - 1) / 3][(i - 1) % 3] = '0' + i; // Undo
        }
    }
    return botEasy();
}

// AI move function based on difficulty
int botMove() {
    if (difficulty == 1) return botEasy();
    return botMedium();
}

void game() {
    srand(time(0));
    cout << "Choose your marker (X or O): ";
    cin >> player_marker;
    bot_marker = (player_marker == 'X') ? 'O' : 'X';

    cout << "Select difficulty:\n1. Easy\n2. Medium\n> ";
    cin >> difficulty;

    int turn = (player_marker == 'X') ? 0 : 1;
    drawBoard();

    while (true) {
        if (turn == 0) {
            int position;
            cout << "Your turn (1-9): ";
            cin >> position;
            while (!placeMarker(position, player_marker)) {
                cout << "Invalid move. Try again: ";
                cin >> position;
            }
        } else {
            cout << "Bot is thinking...\n";
            int move = botMove();
            cout << "Bot played at position: " << move << endl;
        }

        drawBoard();

        if (checkWin(player_marker)) {
            cout << "You win!\n";
            break;
        }
        if (checkWin(bot_marker)) {
            cout << "Bot wins!\n";
            break;
        }
        if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        turn = 1 - turn;
    }
}

int main() {
    game();
    return 0;
}
