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

Przykład używania

Korzystając z algorytmu Millera-Rabina, możemy przetestować liczbę 341 w następujący sposób −

 Krok 1: $341 − 1 = 2^2$ x 85. Zatem p = 341, k = 2 and q = 85
 
Krok 2: x = 2 (dany)

Krok 3: $S = x^q$ mod p
         = $2^{85}$  mod 341 = $(2^{10})$ x $2^5$ mod 341 8
         = $2^{10}$ mod 341 x $2^{13}$ mod 341
         = 1 x 8192 mod 341 = 8192 mod 341
         = 8
         
Krok 4: Ponieważ 8 ≠ 1 przechodzimy do następnego kroku.

Krok 5: dla j = 1, $S = x^{2q}$ mod p
         = $2^{170}$ mod 341 = $(2^{20})^8$ x $2^{10}$ mod 341
         = $2^{20}$ mod 341 x $2^8$ mod 341 x $2^{10}$ mod 341
         = 1 x 256 x 1 = 256
teraz, = 256 ≠ 1

**i wynik jest niejednoznaczny
Zatem 341 nie jest liczbą złożoną.**

**Zalety**

Algorytm ten może być używany do testowania pierwszorzędności dużych liczb.

Ze względu na przewagę szybkości w porównaniu z innymi testami pierwszości, test Millera Rabina będzie testem z wyboru w kilku zastosowaniach kryptograficznych.

W porównaniu z testami Eulera i Solovaya-Strassena test Millera Rabina jest bardziej dynamiczny, a istotnym aspektem jest zmniejszenie prawdopodobieństwa niepowodzenia.

Zgodnie z testem fermata jest zbyt wielu kłamców dla wszystkich liczb Carmichaela n, prawdopodobieństwo błędu jest bliskie 1, ta wada jest zapobiegana u Millera Rabina.



**-Algorytm wyszukiwania najdłuższego sufiksu pasującego do prefiksu w drugim łańcuchu. **

Używałem KMP Algorytmu
 Używamy wartości z lps[], aby określić następną pozycję przesuwania. Kiedy porównujemy pat[j] z txt[i] i widzimy niezgodność, wiemy, że znaki pat[0..j-1] pasują do txt[i-j+1…i-1], wiemy też, że lps[j-1] znaki pat[0…j-1] są zarówno właściwym przedrostkiem, jak i sufiksem, co oznacza, że nie musimy dopasowywać tych znaków lps[j-1] do txt[i-j…i-1], ponieważ wiemy że te znaki i tak będą pasować.
 
 ![image](https://user-images.githubusercontent.com/115027239/213924490-3feafbbd-2770-4ee0-a769-911217a51d14.png)

**Pseudokod**
```
KMPSearch(pat, txt){
   
    computeLPSArray(pat, M, lps)
    
    while i < N
        if pat[j] == txt[i]
            j++
            i++
        if j == M
            print "znaleziono na indeksie", i - j
            j = lps[j - 1]
        if i < N and pat[j] != txt[i]
            if j != 0
                j = lps[j - 1]
            else
                i = i + 1
procedure computeLPSArray(pat, M, lps)
   
    while i < M
        if pat[i] == pat[len]
            len++
            lps[i] = len
            i++
        else // pat[i] != pat[len]
            if len != 0
                len = lps[len - 1]
                
            else // len == 0
                lps[i] = 0
                i++
}
```

**Kod** 

```
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
 
    
    int *lps = (int *) malloc(sizeof(int) * M);
    int j = 0; 
 
   
    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            printf("Znaleziono na indeksie %d \n", i - j);
            j = lps[j - 1];
        }
 
    
        else if (i < N && pat[j] != txt[i]) {
           
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    free(lps); 
}
 
void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0; 
    int i;
 
    lps[0] = 0; 
    i = 1;
 
    
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else 
        {
            if (len != 0) {
                
                len = lps[len - 1];
 
               
            } else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 

int main() {
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
```
 zaleta algorytmu KMP
 
KMP ma tę zaletę, że gwarantuje skuteczność w najgorszym przypadku. Czas przetwarzania wstępnego to zawsze O(n), a czas wyszukiwania to zawsze O(m). Nie ma najgorszych danych wejściowych.
W przypadkach, gdy szukasz bardzo długich ciągów (duże n) wewnątrz naprawdę dużych ciągów (duże m), może to być bardzo pożądane w porównaniu z innymi algorytmami.





