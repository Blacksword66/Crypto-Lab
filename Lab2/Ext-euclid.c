#include <stdio.h>
int checkCoprime(int a, int b)
{
    int gcd = 1, less;
    if (b < a)
        less = b;
    else
        less = a;
    for (int i = 2; i <= less; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}
int extendedEucliid(int b, int a)
{
    int gcd = checkCoprime(a, b);
    if (gcd != 1)
    {
        printf("The Multiplicative inverse of %d mod %d does not exist\n", b, a);
        return 0;
    }
    int n1 = a;
    int q, r, xi = 0, yi = 1, x;
    while (1)
    {
        q = a / b;
        r = a % b;
        if (r == 0)
        {
            break;
        }
        x = xi - (yi * q);
        a = b;
        b = r;
        xi = yi;
        yi = x;
    }
    if (yi < 0)
    {
        yi += n1;
    }
    return yi;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], m[n], M = 1, Mn[n], Mni[n], X = 0;
    // input a and m
    for (int i = 0; i < n; i++)
    {
        printf("a ");
        scanf("%d", &a[i]);
        printf("m ");
        scanf("%d", &m[i]);
        if (a[i] < 0)
            a[i] += m[i];
    }
    for (int i = 0; i < n; i++)
    { // to find M
        M *= m[i];
    }
    for (int i = 0; i < n; i++)
    { // to find M1, M2, ...
        Mn[i] = M / m[i];
    }
    for (int i = 0; i < n; i++)
    { // to find inverses of M1,M2,...
        Mni[i] = extendedEucliid(Mn[i], m[i]);
    }
    for (int i = 0; i < n; i++)
    { // to calculate X
        X += (a[i] * Mn[i] * Mni[i]);
    }
    X = X % M;
    printf("The common solution to all equations is %d\n", X);
    return 0;
}