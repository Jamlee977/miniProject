#include <iostream>
using namespace std;

void co_ex(char p1[100], int coeffecients[], int exp[], int& len) {
    int countCo = 0;
    int countEx = 0;
    
    int co = 0;
    int ex = 0;
    int flag = 0;
    for (int i = 0; i <= len; i++) {
        if (p1[i] != 'x' && flag == 0 && p1[i] != '^') {
            co = co * 10 + (p1[i] - '0');
        }
        if (p1[i] == 'x' || (p1[i + 1] == '\0' && flag == 0)) {

            coeffecients[countCo++] = co;
            co = 0;
            continue;
        }
        if (p1[i] == '^') {
            flag = 1;
            //i++;
            ex = 0;
        }


        else if (flag == 1) {

            if (p1[i] == '+' || p1[i] == '\0') {
                exp[countEx++] = ex;

                ex = 0;
                flag = 0;

            }
            else {
                ex = ex * 10 + (p1[i] - '0');

            }
        }



    }

    /* for (int i = 0; i < countCo; i++) {
        cout << coeffecients[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < countEx; i++) {
        cout << exp[i] << " ";
    } */
}

void exLength(char p1[], int& exLen, int len) {
    for (int i = 0; i <= len; i++) {
        if (p1[i] == '^')
            exLen++;
    }
}

void firstDerOnSec(int coeffecients[], int exp[], int exLen) {
    int i;
    for (i = 0; i <= exLen; i++) {
        coeffecients[i] = coeffecients[i] * exp[i];
        exp[i] = exp[i] - 1;
    }
}

void firstDer(int coeffecients[], int exp[], int exLen) {
    int i;
    for (i = 0; i <= exLen; i++) {
        coeffecients[i] = coeffecients[i] * exp[i];
        exp[i] = exp[i] - 1;
    }
    for (int i = 0; i <= exLen; i++) {

        if (coeffecients[i] == 0)
            break;
        cout << coeffecients[i];
        if (exp[i] != 0) {
            cout << "x";
        }
        if (exp[i] != 1 && exp[i] != 0) {
            cout << "^" << exp[i];
        }
        if (i < exLen - 1) {

            cout << " + ";

        }

    }
}

void secondDer(int coeffecients[], int exp[], int exLen) {
    int i;
    firstDerOnSec(coeffecients, exp, exLen);
    for (i = 0; i <= exLen; i++) {
        coeffecients[i] = coeffecients[i] * exp[i];
        exp[i] = exp[i] - 1;
    }
    
    for (i = 0; i <= exLen; i++) {

        if (coeffecients[i] == 0)
            break;
        cout << coeffecients[i];
        if (exp[i] != 0) {
            cout << "x";
        }
        if (exp[i] != 1 && exp[i] != 0) {
            cout << "^" << exp[i];
        }
        if (i == exLen) {
            ----i;
            cout << NULL;
        }
        if (i < exLen - 1 || i) {
            cout << " + ";
        }
        
    }
    
}

void terms(int coeffecients[], int exp[], int len) {
    for (int i = 0; i < len; i++) {
        if (coeffecients[i] == 0 && (exp[i] <= 0))
            break;

        cout << "(" << coeffecients[i] << "," << exp[i] << ")";
    }

}

int main() {
    char p1[100];
    int coeffecients[100] = { 0 };
    int exp[100] = { 0 };
    int countCo = 0;
    int countEx = 0;
    int exLen = 0;
    int len=0;

    
    cout << "Enter the formula: ";
    cin >> p1;

    for (int i = 0;; i++) {
        if (p1[i] != '\0')
            len++;
        else
            break;

    }


    co_ex(p1, coeffecients, exp, len);
    exLength(p1, exLen, len);
    
    cout << endl << "The formula is: " << p1;

    cout << endl;
    cout << "\nThe first derivative of this function is: ";
    firstDer(coeffecients, exp, exLen);

    co_ex(p1, coeffecients, exp, len);
    exLength(p1, exLen, len);
    
    cout << "\n\nThe second derivative of this function is: ";
    secondDer(coeffecients, exp, exLen);
    
    cout << endl << endl;
    co_ex(p1, coeffecients, exp, len);
    exLength(p1, exLen, len);
    cout << "The terms are: ";
    terms(coeffecients, exp, len);
    

    



}

