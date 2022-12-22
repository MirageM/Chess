// Q1- A chessboard is like the picture shown below with rows are shown by numbers 2 to 8 and columns
// are shown with characters ‘a’ to ‘h’. Design a class called Piece, which represents pieces we have in
// chess. Each piece has a color, which can be white or black, and a current position. Then, you need to
// have a method called move that moves the piece to a new given position. The new position is given
// with an integer for the row and a character for the column. You need to inherit the following pieces
// from this class.
// King, Queen, Rook, Knight, Bishop.
// Pawn (Bonus mark), note that pawn can move one or two squares in the forward direction from its
// initial position but it can move one square only after in the forward direction. (Assume white pawns
// always start at row number 1 shown below, and black pawns start at row number 7 shown below)
// You should check the validity of the new position, and if the new position is a valid move for the given
// piece, move the piece to that position. Have proper default and user constructors for classes.
// (10 + 3 marks)

#include "Piece.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


//Default Constructor
Piece :: Piece() {
    color = 'w';
    row = 1;
    col = 'a';
}
//User Constructor
Piece :: Piece(char color, int row, char col) {
    this->color = color;
    this->row = row;
    this->col = col;
}

//King
class King : public Piece {
public:
    King(char color, int row, char col) : Piece(color, row, col) {}
    bool move(int row, char col) {
        if (abs(this->row - row) <= 1 && abs(this->col - col) <= 1) {
            this->row = row;
            this->col = col;
            return true;
        }
        return false;
    }
    void print() {
        cout << "King " << color << " " << row << " " << col << endl;
    }
};

//Queen
class Queen : public Piece {
public:
    Queen(char color, int row, char col) : Piece(color, row, col) {}
    bool move(int row, char col) {
        if (this->row == row || this->col == col || abs(this->row - row) == abs(this->col - col)) {
            this->row = row;
            this->col = col;
            return true;
        }
        return false;
    }
    void print() {
        cout << "Queen " << color << " " << row << " " << col << endl;
    }
};

//Rook
class Rook : public Piece {
public:
    Rook(char color, int row, char col) : Piece(color, row, col) {}
    bool move(int row, char col) {
        if (this->row == row || this->col == col) {
            this->row = row;
            this->col = col;
            return true;
        }
        return false;
    }
    void print() {
        cout << "Rook " << color << " " << row << " " << col << endl;
    }
};

//Knight
class Knight : public Piece {
public:
    Knight(char color, int row, char col) : Piece(color, row, col) {}
    bool move(int row, char col) {
        if (abs(this->row - row) == 2 && abs(this->col - col) == 1) {
            this->row = row;
            this->col = col;
            return true;
        }
        if (abs(this->row - row) == 1 && abs(this->col - col) == 2) {
            this->row = row;
            this->col = col;
            return true;
        }
        return false;
    }
    void print() {
        cout << "Knight " << color << " " << row << " " << col << endl;
    }
};


//Bishop
class Bishop : public Piece {
public:
    Bishop(char color, int row, char col) : Piece(color, row, col) {}
    bool move(int row, char col) {
        if (abs(this->row - row) == abs(this->col - col)) {
            this->row = row;
            this->col = col;
            return true;
        }
        return false;
    }
    void print() {
        cout << "Bishop " << color << " " << row << " " << col << endl;
    }
};

//Pawn (Bonus)
//Pawn can move one or two squares in the forward direction from its initial position
class Pawn : public Piece {
public:
    Pawn(char color, int row, char col) : Piece(color, row, col) {}
    bool move(int row, char col) {
        if (this->color == 'w') {
            if (this->row == 1) {
                if (this->row + 2 == row && this->col == col) {
                    this->row = row;
                    this->col = col;
                    return true;
                }
            }
            if (this->row + 1 == row && this->col == col) {
                this->row = row;
                this->col = col;
                return true;
            }
        }
        if (this->color == 'b') {
            if (this->row == 7) {
                if (this->row - 2 == row && this->col == col) {
                    this->row = row;
                    this->col = col;
                    return true;
                }
            }
            if (this->row - 1 == row && this->col == col) {
                this->row = row;
                this->col = col;
                return true;
            }
        }
        return false;
    }
    void print() {
        cout << "Pawn " << color << " " << row << " " << col << endl;
    }
};

//test code
int main(){
    Piece *p = new King('w', 1, 'a');
    p->print();
    p->move(2, 'b');
    p->print();
    p = new Queen('b', 8, 'h');
    p->print();
    p->move(8, 'a');
    p->print();
    p = new Rook('w', 1, 'a');
    p->print();
    p->move(2, 'a');
    p->print();
    p = new Knight('b', 8, 'h');
    p->print();
    p->move(6, 'g');
    p->print();
    p = new Bishop('w', 1, 'a');
    p->print();
    p->move(3, 'c');
    p->print();
    p = new Pawn('w', 1, 'a');
    p->print();
    p->move(3, 'a');
    p->print();
    p = new Pawn('b', 7, 'h');
    p->print();
    p->move(5, 'h');
    p->print();
    return 0;
}