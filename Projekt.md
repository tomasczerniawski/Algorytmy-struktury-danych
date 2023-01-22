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

Twierdzenie 1
Załóżmy, że 
�
n jest liczbą pierwszą oraz że 
�
∈
�
�
⋆
.
{\displaystyle a\in \mathbb {Z} _{n}^{\star }.}

Niech dalej 
�
=
(
�
−
1
)
/
2
�
,
{\displaystyle d=(n-1)/2^{s},} gdzie 
�
=
max
{
�
:
2
�
|
(
�
−
1
)
}
.
{\displaystyle s=\max\{j:2^{j}|(n-1)\}.} Wówczas albo 
�
�
≡
1
(
mod
�
)
,
{\displaystyle a^{d}\equiv 1({\bmod {n}}),} albo istnieje 
�
∈
�
�
,
{\displaystyle r\in \mathbb {Z} _{s},} dla którego 
�
2
�
⋅
�
≡
−
1
(
mod
�
)
{\displaystyle a^{2^{r}\cdot d}\equiv -1({\bmod {n}})}[potrzebny przypis].

Liczbę 
�
∈
�
�
⋆
,
{\displaystyle a\in \mathbb {Z} _{n}^{\star },} która nie spełnia warunków powyższego twierdzenia nazywa się świadkiem złożoności liczby 
�
.
n.

Twierdzenie 2
Jeśli 
�
⩾
3
{\displaystyle n\geqslant 3} jest nieparzystą liczbą złożoną, to w zbiorze 
�
�
⋆{\displaystyle \mathbb {Z} _{n}^{\star }} jest co najwyżej 
(
�
−
1
)
/
4
{\displaystyle (n-1)/4} liczb niebędących świadkami jej złożonośc
