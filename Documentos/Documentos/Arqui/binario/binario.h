#ifndef BINARIO_H
#define BINARIO_H


class binario
{
private:
    int tam;
    int listBin1[],listBin2[],listBinRes[];
public:
    binario(const binario&);
    binario(int);
    int *decToBin(int);
    int binToDec(int);
    int *bitwise(int[]);
    int *addBin(int, int);
    int *subtractBin(int,int);
    int *copy(int);
    int *copy2(int);
    int *changeSing(int[]);
    int *multiply(int,int);
    int *multiplySing(int,int);
    int *split(int,int);
};

#endif // BINARIO_H
