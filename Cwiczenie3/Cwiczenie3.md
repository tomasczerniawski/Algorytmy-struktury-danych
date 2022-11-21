## Big-O i Big-Omega
# Zadania

Czy jest 2n + 1 ∊ Θ(2n)? Wiezmiemy 2n+1 = 0*2n. Wtedy mamy zauważyć ze przy 2n - 20n = -1. Tak samo możemy twierdzić ze n = 2 -20 nie = 0 ale to słabsze twierdzenie niż n = - 1/2-20 0 nie= 1

Czy jest (x + y)² ∊ Θ(x² + y²)?

Czy jest 17 ∊ Θ(1)?

Czy jest 2(n - 1)/2 ∊ Θ(n²)? Wiezmiemy 2(n - 1)= 2n²0. Wtedy mamy zauważyć ze przy n -1 = n²0. Tak samo możemy twierdzić ze n²0 = n-1 ale to słabsze twierdzienie niż 0 = n-1/n² n nie = 0

Czy jest max(n³,10n²) ∊ Θ(n³)?

Czy jest $ \sum_{i=1}^{n}i^k ∊ Θ(n^{k+1})$ i Ω(n^{k+1}) dla calkowitych k?


# Uporządkuj następujące funkcje według rosnącej

(1/2)ⁿ,  
17,  
loglogn,  
logn,  
log²n,  
n/logn,  
√nlog²n,  
n,  
(3/2)ⁿ


# Oblicz złożoność czasową dla każdego fragmentu kodu ćwiczenia.



# Notacja Big-O

1 function someFunction(n) {  
2       i = 0;  
3       for (i; i < 1000 ; i++) {  
4           printf("%d", i);  
5       }  
6   }  

Złożoność liniowa

 
1 function someFunction(n) {  
2       i = 0;  
3       for (i; i < n * 10 ; i++) {  
4           printf("%d", i);  
5       }  
6   }  

Złożoność liniowa


1 function someFunction(n) {   
2       i = 0;  
3       for (i; i < n  ; i = i * 2) {  
4           printf("%d", i);  
5       }  
6   }  

Złożoność logarytmiczna


1 function someFunction(n) {  
3       while (true) {  
4           printf("%d", n);  
5       }  
6   }  

Złożoność nieskończona
