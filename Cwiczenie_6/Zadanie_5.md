# Zadanie 5
Sprawdzic czy słowo jest anagram.


```
int main ()  
{ 
    
    len1 = strlen (arr1);  
    len2 = strlen (arr2);  
      
  
    if (len1 == len2)  
    {  
        num = len1;   
        for ( i = 0; i < num; i++)  
        {  
            znaleziony = 0;  
            for ( j = 0; j < num; j++)  
            {  
                  
                if (arr1[i] == arr2[j])  
                {  
                    znaleziony = 1;  
                    break;  
                }  
            }  
              
            if (znaleziony == 0)  
            {  
                Nie_znaleziony = 1;
                break;  
            }  
        }  
        if (Nie_znaleziony == 1)  
            printf (" \n Nie jest anagrama ");  
        else  
            printf (" \n Jest anagrama. ");     
    }  
    else  
        printf (" \n Dwa wyrazy musza byc tego samego rozmiaru zeby byli anagrama. ");  
          
    return 0;     
}  
```
