# Zadanie 1

Factorial
```
factorial(fact,n){
fact=1

 for(i=1;i<=n;i++){
 
 fact=fact*i
 }
}
// Jezeli podamy liczbe 5 dla n (n=5) to w foru bedzie poruwnywana od jedynki do 5 i zamiast i bedzie wpisywana o jedna jednostka wiecej czym n i puzniej z mienna fact bedzie mnozona na kazda i ktura z tego wyszla to 5!=5*4*3*2*1;
```
# Zadanie 2

Iloczyn i reszta. Realizacja z warunkem pocztkawym calkowita liczba - n, wyjsce licby(lista) - q i r
```



```
# Zadanie 3

NWD 
```



```
# Zadanie 3
Srednia arytmetyczna
 
```
obliczenie_sriedniej(n,liczby[]){
suma=0
i=0

for(i=0;i<n;i++){

  suma=liczby[i]+suma

}
  sriednia=suma/n
  return sriednia
}
Z (forem) robimy loop gdzie (n) jest ilosc liczb w tabeli i w sriodku  (fora) jest obliczana suma tych liczb podstawia zamias (liczby[i] ) ilbe na pozycji zerowej i dodaje sume poprzedniego wyniku np. (suma(0)=liczby[0](2)+suma(0) to ruwnas 2 puzniej suma(2)=liczby[1](4)+suma(2)=6) puzniej wynik jest dzielony na (n) ilosc liczb
```

