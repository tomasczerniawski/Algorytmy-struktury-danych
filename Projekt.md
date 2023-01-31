## Autor Tomas Czerniawski Student 2 roku Informatyki

 ## Projekt do przedmiotu "Algorytmy i struktury danych"
 
 ## Data 2023-01-31

 
 - Algorytm sprawdzania pierwszości nieparzystej liczby naturalnej testem Millera-Rabina.
 
 - Algorytm wyszukiwania najdłuższego sufiksu pasującego do prefiksu w drugim łańcuchu. 
 
 - Algorytm szybkiego sortowania listy dwukierunkowej.


                                 
 # Test Millera-Rabina.

 Udostępnia on szybką metodę sprawdzania pierwszości liczby z możliwością kontrolowania poziomu prawdopodobieństwa popełnienia błędu – jest to zatem metoda probabilistyczna, zwana testem Millera-Rabina.
 
 Test oparty jest na następującym twierdzeniu:

Niech p  będzie nieparzystą liczbą pierwszą zapisaną jako p  = 1 + 2 sd, gdzie d  jest nieparzyste. Wtedy dla dowolnej liczby naturalnej a   ∈  [ 2, p  - 2 ] ciąg Millera-Rabina:

![image](https://user-images.githubusercontent.com/115027239/213917422-74d4e27d-0921-4c04-bc49-23caa3f6a773.png)

Kończy się liczbą 1. Co więcej, jeśli a d  nie przystaje modulo p  do 1, to wyraz ciągu Millera-Rabina bezpośrednio poprzedzający 1 jest równy p  - 1.

## Algorytm sprawdzania pierwszości nieparzystej liczby naturalnej testem Millera-Rabina

Wejście:
p	 –  	liczba badana na pierwszość, p  ∈ N, p  > 2, p  jest nieparzyste.
n	 –	ilość powtórzeń testu Millera-Rabina, n  ∈ N.
Wyjście:
TAK, jeśli p  jest pierwsze lub silnie pseudopierwsze z prawdopodobieństwem ( 1/4 ) n.
NIE , jeśli p  jest liczbą złożoną.



# Pseudo kod Testu Millera-Rabina

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

### Kod Testu Millera-Rabina 
[Programy_dla_Projektu](./Test_Millera-Rabina.c)



# Przykład używania

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

**i wynik jest niejednoznaczny Zatem 341 nie jest liczbą złożoną.**

## Zalety

Algorytm ten może być używany do testowania pierwszorzędności dużych liczb.

Ze względu na przewagę szybkości w porównaniu z innymi testami pierwszości, test Millera Rabina będzie testem z wyboru w kilku zastosowaniach kryptograficznych.

W porównaniu z testami Eulera i Solovaya-Strassena test Millera Rabina jest bardziej dynamiczny, a istotnym aspektem jest zmniejszenie prawdopodobieństwa niepowodzenia.

Zgodnie z testem fermata jest zbyt wielu kłamców dla wszystkich liczb Carmichaela n, prawdopodobieństwo błędu jest bliskie 1, ta wada jest zapobiegana u Millera Rabina.



## Algorytm wyszukiwania najdłuższego sufiksu pasującego do prefiksu w drugim łańcuchu.

# Używałem KMP Algorytmu

 Używamy wartości z lps[], aby określić następną pozycję przesuwania. Kiedy porównujemy pat[j] z txt[i] i widzimy niezgodność, wiemy, że znaki pat[0..j-1] pasują do txt[i-j+1…i-1], wiemy też, że lps[j-1] znaki pat[0…j-1] są zarówno właściwym przedrostkiem, jak i sufiksem, co oznacza, że nie musimy dopasowywać tych znaków lps[j-1] do txt[i-j…i-1], ponieważ wiemy że te znaki i tak będą pasować.
 
 ![image](https://user-images.githubusercontent.com/115027239/213924490-3feafbbd-2770-4ee0-a769-911217a51d14.png)

## Pseudokod
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

# Kod 

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
## Zlożoność programu 
Funkcja KMPSearch najpierw oblicza tablicę Longest Proper Prefix-Suffix (LPS), co zajmuje O(m) czasu. Tablica LPS jest następnie używana do dopasowania wzorca do tekstu. Pętla while w funkcji KMPSearch działa n razy, a blok if-else wewnątrz pętli while zajmuje stały czas. Tak więc złożoność czasowa funkcji KMPSearch wynosi O(n + m).

Złożoność przestrzenna tego algorytmu wynosi O(m), ponieważ używa on tablicy o rozmiarze m (lps) do przechowywania wartości LPS.

Funkcja computeLPSArray ma złożoność czasową równą O(m), ponieważ wykonuje jednokrotną iterację wzorca i wykonuje operacje w stałym czasie.

Ogólnie złożoność czasowa tego algorytmu KMP wynosi O(n + m), a złożoność przestrzenna to O(m).

 ## Zaleta algorytmu KMP
 
KMP ma tę zaletę, że gwarantuje skuteczność w najgorszym przypadku. Czas przetwarzania wstępnego to zawsze O(n), a czas wyszukiwania to zawsze O(m). Nie ma najgorszych danych wejściowych.
W przypadkach, gdy szukasz bardzo długich ciągów (duże n) wewnątrz naprawdę dużych ciągów (duże m), może to być bardzo pożądane w porównaniu z innymi algorytmami.

## Algorytm szybkiego sortowania listy dwukierunkowej.

Podobnie jak  Merge Sort, QuickSort jest algorytmem dziel i zwyciężaj. Wybiera element jako oś i dzieli podaną tablicę wokół wybranej osi. Istnieje wiele różnych wersji quickSort, które wybierają elementy przestawne na różne sposoby.

## Szybkiego sortowania

Zawsze wybieraj pierwszy element jako oś obrotu.
Zawsze wybieraj ostatni element jako oś obrotu
Wybierz losowy element jako oś.
Wybierz medianę jako oś obrotu.
Kluczowym procesem w quickSort jest partition(). Celem partycji jest tablica i element x tablicy jako punkt obrotu, umieszczenie x na właściwej pozycji w posortowanej tablicy i umieszczenie wszystkich mniejszych elementów (mniejszych niż x) przed x i umieszczenie wszystkich większych elementów (większe niż x) po x. Wszystko to powinno odbywać się w czasie liniowym.

![image](https://user-images.githubusercontent.com/115027239/213930520-975ae9a5-472e-4a1d-b7c0-eef08d534574.png)


## Pseudokod

```
void QuickSort(node left, node right)
{
    if (right != null && left != right && left != right.next)
    {
        node p = PARTITION(left, right);
        QuickSort(left, p.prev);
        QuickSort(p.next, right);
    }
}
```

# Kod

```
#include <stdio.h>
#include <stdlib.h>
  

struct wezel
{
    int data;
    struct wezel *next;
    struct wezel *prev;
};
  

void swap ( int* a, int* b )
{ int t = *a; *a = *b; *b = t; }
  

struct wezel *lastNode(struct wezel *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
  

struct wezel* przegroda(struct wezel *l, struct wezel *h)
{
 
    int x = h->data;
  
   
    struct wezel *i = l->prev;
  
    
    for (struct wezel *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
          
            i = (i == NULL) ? l : i->next;
  
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->next; 
    swap(&(i->data), &(h->data));
    return i;
}
  

void _quickSort(struct wezel* l, struct wezel *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct wezel *p = przegroda(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
  


void quickSort(struct wezel *head)
{
 
    struct wezel *h = lastNode(head);
  
    
    _quickSort(head, h);
}
  

void printList(struct wezel *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
  

void push(struct wezel** head_ref, int new_data)
{
    struct wezel* new_node = (struct wezel*) 
               malloc(sizeof(struct wezel)); 
    new_node->data = new_data;
  
   
    new_node->prev = NULL;
  
    
    new_node->next = (*head_ref);
  
   
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node ;
  
   
    (*head_ref) = new_node;
}
  

int main(int argc, char **argv)
{
    struct wezel *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
  
    printf("Linked List before sorting \n");
    printList(a);
  
    quickSort(a);
  
    printf("Linked List after sorting \n");
    printList(a);
  
    return 0;
}
```
## Zlozoność szybkiego Sortowania

Złożoność czasowa szybkiego sortowania zależy od zastosowanej strategii podziału. W najgorszym przypadku element przestawny jest najmniejszym lub największym elementem na liście, co powoduje, że jedna partycja ma n-1 elementów, a druga zero elementów. Skutkowałoby to złożonością czasową O(n^2). Jednak w przeciętnym przypadku element przestawny dzieli listę mniej więcej na pół, co skutkuje złożonością czasową O(n log n).

Złożoność przestrzenna szybkiego sortowania wynosi O (log n), ponieważ wykorzystuje rekurencję, a maksymalna głębokość rekurencji wyniesie log n (w przypadku skośnej partycji).

Należy zauważyć, że złożoność czasowa szybkiego sortowania zależy od wyboru elementu przestawnego. Losowe wybranie elementu przestawnego sprawi, że scenariusz przeciętnego przypadku będzie się powtarzał częściej.




