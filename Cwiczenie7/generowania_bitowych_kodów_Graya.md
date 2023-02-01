# Zadania z algorytmow śledzenia wstecznego

Napisac pseudokody do programow pracy z wzorcamy.

### Podejście wsteczne do generowania n bitowych kodów Graya

```
void generuj_kod_Graya(n)
{
   
     lista_kodów_Graya = new int[pow(2, n)];

  
    lista_kodów_Graya[0] = 0;

   
    for (i = 1; i < pow(2, n); i++)
    {
      
        lista_kodów_Graya[i] = lista_kodów_Graya[i-1] ^ (lista_kodów_Graya[i-1] >> 1);
    }
}
```
