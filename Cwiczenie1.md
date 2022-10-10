# Zadanie 1
 napisac program ktora pyta ilsosc dni w miasacu i dzisieszy dzien. Wyprowadza ile zostalo dni do konca miesiaca.

```
miesionc(il_dni, dzien){
zost = il_dni - dzien
return zost
}
```
# Zadanie 2
napisac program ktory obliza jakegu roku urodzenia i jaki teraz jest rok. Wyporwadza ile lat uzytkowniku.

```
ile_lat(jaki_rok_urodz, teraz_rok){
ile_lat_uzyt=teraz_rok - jaki_rok_urodz
return ile_lat_uzyt
}

```
# Zadanie 3
dana calkowita liczba k (1 <= k <= 180) i ciag lizcb 10111213..9899, do ktorego sa zapisane wszytkie dwoznakowe liczby. Wyznaczyc numer pary liczb, to ktorej wpada liczba k
 ```
 numer_pary(k, array){
 k=array[0]
  while(i<len){
  if(array[i]=k){
  numer_pary = array[i]
  }
  i++
  }
  return numer_pary
  )
 ```
  # Zadanie 3
  liczba naturalna z n cyfr jst liczba Armstronga, jezelu suma jego liczb w pierwaztku n, jest rowna samej liczbie. Naprzyklad, 153 = 1^3 + 5^3 + 3^3. Napisac program otrzymania wszykich liczb Armstronga, z 3 i 4 liczb.
  ```
  liczb_armst(liczb, count){
  for(i = 100; i <= 10000; i++) {
  count = 0
  liczb = i
  //liczymy cyfry
  while(liczb > 0){
  ++count;
  liczb /=10
  sum=0
  liczb=i
  //pobierami potęgi wszystkich cyfr i
  while(liczb > 0){
  cyfra = liczb % 10
  sum = sum + pow(cyfra, count)
  num /=10
  }
  //jeśli suma jest równa i, to jest to liczba Armstronga
  if(sum == i){
  return liczba_armst
  }
  }
  
  
  
  }
  ```
