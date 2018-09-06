#ifndef ALEATORIO_H
#define ALEATORIO_H
int const num = 10;
int const num1 = 5;

class Rand
{
    public:
        Rand();
        Rand(int value , int value2): module(value), index(value2){}
        Rand(int value): index(value){}
        int operator()(int value ,int value2) // Numero aleatorio
        {
            return ( num * value2 + num1 ) % value;
        }
    protected:
    private:
        int module;
        int index;
};

#endif // ALEATORIO_H
