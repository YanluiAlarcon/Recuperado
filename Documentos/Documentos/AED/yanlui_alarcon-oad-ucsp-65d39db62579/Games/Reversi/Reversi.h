#ifndef REVERSI_H
#define REVERSI_H


class Reversi
{
    public:
        Reversi();
        void display();
        ~Reversi();
    protected:
    private:
        int **pInt;
        int row,col;
};

#endif // REVERSI_H
