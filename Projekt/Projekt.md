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
[Test_Millera-Rabina.c](./Test_Millera-Rabina.c)

###### Udowodnianie że jest poprawne:
Kod jest uważany za poprawny, ponieważ dokładnie odpowiada algorytmowi testu pierwszości Millera-Rabina. Algorytm opiera się na Małym Twierdzeniu Fermata, które stwierdza, że jeśli n jest liczbą pierwszą, a a jest liczbą całkowitą taką, że 1 < a < n, to a^{n-1} \equiv 1 \pmod{n}


W kodzie test polega na losowym wybraniu liczby „a” i sprawdzeniu, czy a^{n-1} \equiv 1 \pmod{n} (mod n) czy nie. Jeśli tak nie jest, liczba jest uważana za złożoną. Kod implementuje również optymalizacje, takie jak podniesienie wyniku do kwadratu i podzielenie wykładnika przez 2 w każdej iteracji, aby zmniejszyć liczbę wymaganych obliczeń.

Liczbę iteracji ( powtuzenie ) można dostosować, aby zwiększyć dokładność testu, przy czym większa liczba iteracji zwiększa prawdopodobieństwo poprawnego zidentyfikowania liczby pierwszej. Kod poprawnie implementuje wszystkie te elementy testu pierwszości Millera-Rabina, co czyni go poprawną implementacją.

##### funkcji modulo i mulmod

Funkcja modulo (mod) jest to operator w języku programowania, który oblicza resztę z dzielenia dwóch liczb.

1. Przyjmij dwie liczby a i b.
2. Oblicza a modulo b.
3. Zwróć resztę z dzielenia a przez b.

Pseudokod :
```
int mod(int a, int b) {
return a % b;
}
```

Funkcja mulmod jest to funkcja, która oblicza iloczyn dwóch liczb i zwraca resztę z dzielenia wyniku przez określoną wartość.

1. Przyjmij trzy liczby a, b i m.
2. Oblicz iloczyn a i b.
3. Oblicz resztę z dzielenia wyniku przez m.
4. Zwróć resztę.

Pseudokod :
```
int mulmod(int a, int b, int m) {
return (a * b) % m;
}
```

###### Złożoność czasowa

Złożoność czasowa kodu to O(k \log p), gdzie k to liczba wykonań testu pierwszości Millera-Rabina (powtuzenie w kodzie), a p to liczba testowana pod kątem pierwszości. Najbardziej czasochłonną operacją są modułowe funkcje potęgowania (modulo) i modularnego mnożenia (mulmod), których obliczenie zajmuje O (log p). Zatem ogólna złożoność czasowa kodu wynosi O(k \log p).

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

###### i wynik jest niejednoznaczny Zatem 341 nie jest liczbą złożoną.

## Zalety

Algorytm ten może być używany do testowania pierwszorzędności dużych liczb.

Ze względu na przewagę szybkości w porównaniu z innymi testami pierwszości, test Millera Rabina będzie testem z wyboru w kilku zastosowaniach kryptograficznych.

W porównaniu z testami Eulera i Solovaya-Strassena test Millera Rabina jest bardziej dynamiczny, a istotnym aspektem jest zmniejszenie prawdopodobieństwa niepowodzenia.

Zgodnie z testem fermata jest zbyt wielu kłamców dla wszystkich liczb Carmichaela n, prawdopodobieństwo błędu jest bliskie 1, ta wada jest zapobiegana u Millera Rabina.



# Algorytm wyszukiwania najdłuższego sufiksu pasującego do prefiksu w drugim łańcuchu.

 Używałem KMP Algorytmu

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

### Kod KMP
[KMP.c](./KMP.c)

###### Udowodnianie że jest poprawne:
Kod jest implementacją algorytmu dopasowywania ciągów znaków Knutha-Morrisa-Pratta (KMP). Jest to algorytm wyszukiwania wzorców, który wykorzystuje informacje o kilku ostatnich znakach tekstu i wzorcu w najgorszej złożoności czasowej O(n + m), gdzie n to długość tekstu, a m to długość wzór. Kod jest poprawny, ponieważ wykonuje prawidłowe kroki algorytmu KMP:

1. Oblicz tablicę najdłuższego właściwego sufiksu prefiksu (LPS) wzorca.
2. Zainicjuj dwie zmienne i i j, aby przejść odpowiednio przez tekst i wzorzec.
3. Jeśli znaki w i i j pasują do siebie, zwiększ zarówno i, jak i j.
4. Jeśli znaki w i i j nie pasują do siebie, zaktualizuj j o wartość lps[j-1].
5. Powtarzaj kroki 3 i 4, aż j będzie równe długości wzoru.
6. Jeśli j stanie się równe długości wzoru, wydrukuj początkowy indeks wzoru w tekście.
7. Powtórz proces od kroku 3, aby znaleźć wszystkie wystąpienia wzorca w tekście.

Kod poprawnie realizuje powyższe kroki, dlatego można go uznać za poprawną implementację algorytmu KMP.

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

# Szybkiego sortowania

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

# Kod QuickSort
[QuickSort.c](./QuickSort.c)

## Zlozoność szybkiego Sortowania

Złożoność czasowa szybkiego sortowania zależy od zastosowanej strategii podziału. W najgorszym przypadku element przestawny jest najmniejszym lub największym elementem na liście, co powoduje, że jedna partycja ma n-1 elementów, a druga zero elementów. Skutkowałoby to złożonością czasową O(n^2). Jednak w przeciętnym przypadku element przestawny dzieli listę mniej więcej na pół, co skutkuje złożonością czasową O(n log n).

Złożoność przestrzenna szybkiego sortowania wynosi O (log n), ponieważ wykorzystuje rekurencję, a maksymalna głębokość rekurencji wyniesie log n (w przypadku skośnej partycji).

Należy zauważyć, że złożoność czasowa szybkiego sortowania zależy od wyboru elementu przestawnego. Losowe wybranie elementu przestawnego sprawi, że scenariusz przeciętnego przypadku będzie się powtarzał częściej.

## Źriódła

- [test Millera-Rabina](https://eduinf.waw.pl/inf/alg/001_search/0019.php)
- [Szybkie wyszukiwanie wzorca algorytmem Knutha-Morrisa-Pratta](https://eduinf.waw.pl/inf/alg/001_search/0049.php)
- [Sortowanie szybkie listy dwukierunkowej](https://eduinf.waw.pl/inf/alg/001_search/0098.php)



