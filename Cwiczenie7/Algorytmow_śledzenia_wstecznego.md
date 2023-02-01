//Tomas Czerniawski. Student

// Algorytmow śledzenia wstecznego

// 2023.02.01

# Algorytmow śledzenia wstecznego

Pseudokod:

```
void hetmanyWsteczne(int rozwiazanie[], int kolumna, int n)
{
    if (kolumna == n)
    {
        wypiszRozwiazanie(rozwiazanie, n);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            rozwiazanie[kolumna] = i;
            if (jestBezpieczne(rozwiazanie, kolumna))
            {
                hetmanyWsteczne(rozwiazanie, kolumna + 1, n);
            }
        }
    }
}
```
