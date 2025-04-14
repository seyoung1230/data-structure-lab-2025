#pragma once
#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <cstdio>
#include <vector>

#define MAX_DEGREE 101

class SparsePoly {
    int numTerms;
    std::vector<int> exponents;
    std::vector<float> coefficients;

public:
    SparsePoly() : numTerms(0) {}

    void read() {
        printf("항의 개수를 입력하세요: ");
        scanf_s("%d", &numTerms);

        exponents.resize(numTerms);
        coefficients.resize(numTerms);

        for (int i = 0; i < numTerms; ++i) {
            float coef;
            int expo;
            printf("%d번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ", i + 1);
            scanf_s("%f %d", &coef, &expo);
            coefficients[i] = coef;
            exponents[i] = expo;
        }
    }

    void display(const char* str) {
        printf("%s", str);
        for (int i = 0; i < numTerms; ++i) {
            printf("%.1fx^%d", coefficients[i], exponents[i]);
            if (i != numTerms - 1) printf(" + ");
        }
        printf("\n");
    }

    void add(SparsePoly a, SparsePoly b) {
        numTerms = 0;
        int i = 0, j = 0;
        exponents.clear();
        coefficients.clear();

        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] == b.exponents[j]) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i] + b.coefficients[j]);
                ++i; ++j;
            }
            else if (a.exponents[i] > b.exponents[j]) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                ++i;
            }
            else {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                ++j;
            }
            ++numTerms;
        }

        while (i < a.numTerms) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            ++i; ++numTerms;
        }

        while (j < b.numTerms) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            ++j; ++numTerms;
        }
    }
};

#endif
