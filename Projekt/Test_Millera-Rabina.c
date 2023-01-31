#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

long long modulo(long long base, long long pote, long long mod)
{
    long long x = 1;
    long long y = base;
    while (pote > 0)
    {
        if (pote % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        pote = pote / 2;
    }
    return x % mod;
}
 

int Miller(long long p,int powtuzenie)
{
 
    int i;
    long long s;
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2==0)
    {
        return 0;
    }
     s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (i = 0; i < powtuzenie; i++)
    {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int powtuzenie = 5;
    long long num;
    printf("Wprowadź liczbę całkowitą, aby przetestować pierwszorzędność: ");
    scanf("%lld", &num);
    if ( Miller( num, powtuzenie))
        printf("\n%lld jest pierwszorzędny\n", num);
    else
        printf("\n%lld nie jest pierwszorzędny\n", num);
    return 0;
}
