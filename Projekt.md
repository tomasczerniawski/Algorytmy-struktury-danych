 - Algorytm sprawdzania pierwszości nieparzystej liczby naturalnej testem Millera-Rabina.
 
 - Algorytm wyszukiwania najdłuższego sufiksu pasującego do prefiksu w drugim łańcuchu. 
 
 - Algorytm szybkiego sortowania listy dwukierunkowej.


                                   **Autor Tomas Czerniawski Student 2 roku Informatyki**

 1. Test Millera-Rabina.

 Udostępnia on szybką metodę sprawdzania pierwszości liczby z możliwością kontrolowania poziomu prawdopodobieństwa popełnienia błędu – jest to zatem metoda probabilistyczna, zwana testem Millera-Rabina.
 
 Test oparty jest na następującym twierdzeniu:

Niech p  będzie nieparzystą liczbą pierwszą zapisaną jako p  = 1 + 2 sd, gdzie d  jest nieparzyste. Wtedy dla dowolnej liczby naturalnej a   ∈  [ 2, p  - 2 ] ciąg Millera-Rabina:

![image](https://user-images.githubusercontent.com/115027239/213917422-74d4e27d-0921-4c04-bc49-23caa3f6a773.png)

Kończy się liczbą 1. Co więcej, jeśli a d  nie przystaje modulo p  do 1, to wyraz ciągu Millera-Rabina bezpośrednio poprzedzający 1 jest równy p  - 1.

**Algorytm sprawdzania pierwszości nieparzystej liczby naturalnej testem Millera-Rabina**

Wejście:
p	 –  	liczba badana na pierwszość, p  ∈ N, p  > 2, p  jest nieparzyste.
n	 –	ilość powtórzeń testu Millera-Rabina, n  ∈ N.
Wyjście:
TAK, jeśli p  jest pierwsze lub silnie pseudopierwsze z prawdopodobieństwem ( 1/4 ) n.
NIE , jeśli p  jest liczbą złożoną.



Pseudo kod Testu Millera-Rabina

```
int Miller(p, powtuzenie)
{
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
```

Kod Testu Millera-Rabina

```
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
```
Czy jest (x + y)² ∊ Θ(x² + y²)?

Przykład używania

Using Miller-Rabin Algorithm, we can test the number 341 as follows −
```math
$$ Step1: 341 − 1 = 2^2 x 85. Thus p = 341, k = 2 and q = 85
Step2: x = 2 (given)
Step3: S = x mod p
         = 285 mod 341 = (210) x 25 mod 341 8
         = 210 mod 341 x 213 mod 341
         = 1 x 8192 mod 341 = 8192 mod 341
         = 8
Step4: As 8 ≠ 1, we move to the next step.
Step5: For j = 1, S = x2q mod p
         = 2170 mod 341 = (220)8 x 210 mod 341
         = 220 mod 341 x 28 mod 341 x 210 mod 341
         = 1 x 256 x 1 = 256
Now, = 256 ≠ 1
```
and result is inconclusive
So, 341 is not a composite number.

