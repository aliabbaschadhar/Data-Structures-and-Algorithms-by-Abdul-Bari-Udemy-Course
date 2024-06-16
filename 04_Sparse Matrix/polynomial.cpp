#include <iostream>
#include <cstdlib>

using namespace std;

// Class to represent a term in a polynomial
class Term {
public:
    int coeff; // Coefficient of the term
    int exp; // Exponent of the term
};

// Class to represent a polynomial
class Poly {
public:
    int n; // Number of terms
    Term *terms; // Array of terms

    // Method to create a polynomial
    void create() {
        int i;
        cout << "Number of terms? ";
        cin >> n;
        terms = new Term[n];

        cout << "Enter terms\n";
        for (i = 0; i < n; i++)
            cin >> terms[i].coeff >> terms[i].exp;
    }

    // Method to display the polynomial
    void display() {
        int i;
        for (i = 0; i < n; i++)
            cout << terms[i].coeff << "x^" << terms[i].exp << " + ";
        cout << "\n";
    }
};

// Method to add two polynomials
Poly *add(Poly *p1, Poly *p2) {
    int i, j, k;
    Poly *sum = new Poly;
    sum->terms = new Term[(p1->n) + (p2->n)];
    i = j = k = 0;

    while (i < p1->n && j < p2->n) {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;
    return sum;
}

int main() {
    Poly p1, p2, *p3;

    p1.create();
    p2.create();

    p3 = add(&p1, &p2);

    cout << "\n";
    p1.display();
    cout << "\n";
    p2.display();
    cout << "\n";
    p3->display();

    return 0;
}