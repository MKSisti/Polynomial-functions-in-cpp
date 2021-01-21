#include "func.hpp"

void showAll(vector<poly>);
int main()
{
    vector<poly> PV;
    poly P;
    int choice, num, i;
    while (1)
    {
        system("cls");
        cout << "----------------------------------------------------------------------" << endl;
        cout << "         1 > add a polynomial function " << endl;
        cout << "         2 > evaluate a function at a point  " << endl;
        cout << "         3 > evaluate the integral of a function  " << endl;
        cout << "         4 > list entered polynomials  " << endl;
        cout << "         5 > exit program  " << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "         >> Your choice :  ";

        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "\n----------------------------------------------------------------------" << endl;
            cout << "         >> enter the number of monomials   :  ";
            cin >> num;

            for (int i = 0; i < num; i++)
            {

                float tmpc, tmpp;
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "         >> enter the coefficient and exponent (" << i + 1 << "/" << num << ") :  ";
                cin >> tmpc >> tmpp;

                P.addBlock(block(tmpc, tmpp));
            }
            PV.push_back(P);
            P.POL.clear();
            break;

        case 2:
            cout << "\n----------------------------------------------------------------------" << endl;
            system("cls");
            cout << "-------------------- choose a function -------------------------------" << endl;
            showAll(PV);

            cout << "----------------------------------------------------------------------" << endl;
            cout << "         >> Your choice :  ";

            cin >> i;
            cout << "         >> enter a number   :  ";
            cin >> num;
            cout << "\n f( " << num << " ) = " << PV[i].eval(num) << endl;
            break;
        case 3:
            int lb, rb, pr;
            cout << "\n----------------------------------------------------------------------" << endl;
            system("cls");
            cout << "-------------------- choose a function -------------------------------" << endl;
            showAll(PV);

            cout << "----------------------------------------------------------------------" << endl;
            cout << "         >> Your choice :  ";
            cin >> i;
            cout << "         >> enter the left bound then the right bound   :  ";
            cin >> lb >> rb;
            cout << "\n----------------------------------------------------------------------" << endl;
            cout << "         >> enter the precision   :";
            cin >> pr;
            cout << "\n Integral[f(x)](" << lb << "," << rb << ") = " << PV[i].RiemannInt(lb, rb, pr) << endl;
            break;
        case 4:
            cout << "\n----------------------------------------------------------------------" << endl;
            showAll(PV);
            break;

        case 5:
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "unvalid value!" << endl;
            break;
        }
        cin.ignore();
        cin.get();
    }

    return 0;
}
void showAll(vector<poly> PV)
{

    if (PV.size())
    {

        for (unsigned int i = 0; i < PV.size(); i++)
        {
            cout << "< " << i << " >";
            PV[i].showPoly();
        }
    }
    else
    {
        cout << "         >> please add a polynomial using the first option ...";
    }
}