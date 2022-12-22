//Mirage Mohammad
//header question 1
class Piece {
public:
    Piece();
    Piece(char color, int row, char col);
    virtual bool move(int row, char col) = 0;
    virtual void print() = 0;
protected:
    char color;
    int row;
    char col;
};
