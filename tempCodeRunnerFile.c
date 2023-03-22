#include <stdio.h>

#define MAX_DEGREE 50

struct Polynomial {
    int degree;
    float coefficients[MAX_DEGREE + 1];
};

void add_polynomials(struct Polynomial p1, struct Polynomial p2, struct Polynomial *result) {
    int i;
    result->degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;

    for (i = 0; i <= result->degree; i++) {
        result->coefficients[i] = p1.coefficients[i] + p2.coefficients[i];
    }
}

void print_polynomial(struct Polynomial p) {
    int i;
    printf("%0.2fx^%d", p.coefficients[0], p.degree);

    for (i = 1; i <= p.degree; i++) {
        if (p.coefficients[i] != 0) {
            printf(" + %0.2fx^%d", p.coefficients[i], p.degree - i);
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial p1, p2, result;
    int i;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &p1.degree);

    printf("Enter the coefficients of the first polynomial: ");
    for (i = 0; i <= p1.degree; i++) {
        scanf("%f", &p1.coefficients[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &p2.degree);

    printf("Enter the coefficients of the second polynomial: ");
    for (i = 0; i <= p2.degree; i++) {
        scanf("%f", &p2.coefficients[i]);
    }

    add_polynomials(p1, p2, &result);

    printf("Polynomial 1: ");
    print_polynomial(p1);

    printf("Polynomial 2: ");
    print_polynomial(p2);

    printf("Result: ");
    print_polynomial(result);

    return 0;
}