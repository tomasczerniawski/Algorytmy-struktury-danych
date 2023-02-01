//Tomas Czerniawski. Student

// Algorytmow śledzenia wstecznego

// 2023.02.01


Napisac pseudokody do programow pracy z wzorcamy.

## Napisz program, który wypisze wszystkie permutacje podanego ciągu znaków

```
void permutacje(*ciag_znaków, pozycja, dlugosc)
{
    if (pozycja == dlugosc)
    {
        printf("%s\n", ciag_znaków);
    }
    else
    {
        for (int i = pozycja; i < dlugosc; i++)
        {
            swap((ciag_znaków + pozycja), (ciag_znaków + i));
            permutacje(ciag_znaków, pozycja + 1, dlugosc);
            swap((ciag_znaków + pozycja), (ciag_znaków + i));
        }
    }
}
```
