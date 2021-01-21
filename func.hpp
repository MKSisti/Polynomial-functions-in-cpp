#ifndef _FUNC__
#define _FUNC__

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
*
*   MONOMES ↓
*
*/

class block
{
public:
    float coef;
    int power;

    block(float = 0, int = 0);
    float evaluate(float);
    void showBlock();
};

void block::showBlock()
{
    if (coef == 0)
    {
        cout << "";
    }
    else if (power == 0)
    {
        cout << coef;
    }
    else
    {
        if (power == 1 && coef != 1)
        {
            cout << coef << "X";
        }
        else if (power == 1 && coef == 1)
        {
            cout << "X";
        }
        else if (power != 1 && coef == 1)
        {
            cout << "X^" << power;
        }
        else
        {
            cout << coef << "X^" << power;
        }
    }
}

block::block(float C, int P)
{
    coef = C;
    power = P;
}

float block::evaluate(float x)
{
    return coef * pow(x, power);
}

/*
*
* POLYNOM ↓
*
*/
class poly
{
public:
    vector<block> POL;

    //poly(int=0 );
    poly() {}
    void addBlock(block);
    void addPoly(poly);
    float eval(float);
    float RiemannInt(float, float, int);
    void showPoly();
};

void poly::showPoly()
{
    cout << "         >> ";
    for (signed int i = 0; i < POL.size() - 1; i++)
    {
        POL[i].showBlock();
        cout << " + ";
    }
    POL.back().showBlock();
    cout << endl;
}

void poly::addBlock(block B)
{
    for (signed int i = 0; i < POL.size(); i++)
    {
        if (B.power == POL[i].power)
        {
            POL[i].coef += B.coef;
            return;
        }
    }
    POL.push_back(B);
}

void poly::addPoly(poly P)
{
    for (signed int i = 0; i < P.POL.size(); i++)
    {
        addBlock(P.POL[i]);
    }
}

float poly::eval(float x)
{
    float S = 0;

    for (signed int i = 0; i < POL.size(); i++)
    {
        S += POL[i].evaluate(x);
    }

    return S;
}

float poly::RiemannInt(float a, float b, int pre)
{
    float RIEM = 0, DX, L, R;
    //a<=b?L=a,R=b:L=b,R=a;
    DX = (b - a) / pre;
    L = a;
    R = a + DX;

    for (int i = 0; i < pre; i++)
    {
        RIEM += ((eval(L) + eval(R)) / 2) * DX;
        L += DX;
        R += DX;
    }

    return RIEM;
}

#endif