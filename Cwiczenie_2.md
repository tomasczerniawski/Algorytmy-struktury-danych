# Zadanie 1

* Tomas Czerniawski. Student
* Factorial
* 2022-10-24
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

* Tomas Czerniawski. Student
* Iloczyn i reszta. Realizacja z warunkem pocztkawym calkowita liczba - n, wyjsce licby(lista) - q i r
* 2022-10-24
```
ilocyzn_reszta(iloczyn reszta){
q=iloczyn
r=reszta
iloczyn=n*d

reszta= iloczyn%n
return iloczyn reszta
}


```
# Zadanie 3
* Tomas Czerniawski. Student
* NWD 
* 2022-10-24

```
NWD(zbiur, max){
for(int i =1; i<98;i++) {
		zbiur[i]=zbiur[i]+i;
		}
	
	max=zbiur[0];
	for(int i = 1; i<98;i++) {
		if(a % zbiur[i] == 0 && b % zbiur[i] == 0) {
			max=zbiur[i];
		}
	}
	retun max
	}

Pierwszy for zapelnia automatycznie tabele do 98 drugi for puska petle aby sprawdzic przez if maksymalny dzielni  (jezeli a = 4 b = 14 to w ifie podstawujisie pierwsza liczba tabelki to 1 przeruwnuje do max puzniej poruwnuje dodrugiej liczby i tak do puki nie przestanie byc if prawdziwy i jak przestanie to ostatnia liczba bedzi maksymalnym dzilnikiem )
```
# Zadanie 4
* Tomas Czerniawski. Student
* Srednia arytmetyczna
* 2022-10-24
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
# Zadanie 5
* Tomas Czerniawski. Student
* Wyszukiwanie maksimum (minimum) w tablice liczb naturalnych
* 2022-10-24
```
maksymum(zbiur,max){
 max = zbiur[0]
 
	for( i = 0;i<n;i++) {
 
		if(max<zbiur[i]) {
  
			 max = zbiur[i];	
		}
	}
 return max;
 }
 
minimum(zbiur, min){
 min = zbiur[0];
 
	for( i = 0;i<n;i++) {
 
		if(min>zbiur[i]) {
  
			 min = zbiur[i];
			
		}
	}
 return min
}

Spoczatku przeruwnujemy liczbe ktura jest na zerowej pozycji jako maksymum tej tablicy i wprowadzamy petle for zeby poruwnac kazda liczbe w tabeli i sprawdzamy przez if jezeli  if jest prawdziwy to zamiast maksymuma wprowadzasie nowa zmienna itakie robi dobukej nieporuwna wszytkie liczby w tabeli 
A w minimu wzystko tosamo tyko szuk mniejszej liczby

```
