/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/


#include <stdio.h>
#include <time.h>
#include <math.h>
#include<stdlib.h>

int isGen(int a, int p);
int modexp(int base, int exp, int mod);
int isPrime(int n);
int nextPrime(int n);
int isGen(int a, int p);

int main() {

    srand(time(0));

    // Get one prime.
    int p;
    printf("Please enter an approximate value for p < 32000.\n");
    scanf("%d", &p);
    p = nextPrime(p);

    // Find a generator for p.
    int gen = 1;
    while (!isGen(gen, p))
        gen = rand()%p;

    // Print the public keys.
    printf("The public keys are prime = %d, gen = %d\n", p, gen);

    // Generate both secret keys.
    int a = rand()%p;
    int b = rand()%p;
    printf("Alice's private key is %d\n", a);
    printf("Bob's private key is %d\n", b);

    // Calculate public keys for Alice and Bob.
    int publicA = modexp(gen, a, p);
    int publicB = modexp(gen, b, p);
    printf("Alice sends to Bob %d\n", publicA);
    printf("Bob sends to Alice %d\n", publicB);

    // Show their recovery.
    int aliceRecovers = modexp(publicB, a, p);
    int bobRecovers = modexp(publicA, b, p);
    printf("Alice gets %d\n", aliceRecovers);
    printf("Bob gets %d\n", bobRecovers);

}

// Performs fast modular exponentiation, only works if base < 2^15.
int modexp(int base, int exp, int mod) {

    // Easy base cases.
    if (exp == 0)
        return 1;
    else if (exp == 1)
        return base%mod;

    // This is what makes this fast.
    else if (exp%2 == 0) {
        int mysqrt = modexp(base, exp/2, mod);
        return (mysqrt*mysqrt)%mod;
    }

    // No optimization in the odd case.
    else
        return (modexp(base, exp-1, mod)*base)%mod;

}

// Returns 1 iff n is prime.
int isPrime(int n) {

    int i;
    if (n == 2) return 1;
    if (n%2 == 0) return 0;
    for (i=3; i<=sqrt(n)+1; i+=2) {
        if (n%i == 0)
            return 0;
    }

    return 1;
}

// Returns the next prime equal or greater to n.
int nextPrime(int n) {

    while (!isPrime(n))
        n++;

    return n;
}

// Returns 1 iff a is a generator mod p.
// This is written inefficiently!!!
int isGen(int a, int p) {

    int i, ans = 1;
    for (i=1; i<=(p-1)/2+1; i++) {
        ans = (ans*a)%p;

        // We hit this value too soon!!!
        if (ans == 1) return 0;

    }

    // Found a generator.
    return 1;
}
