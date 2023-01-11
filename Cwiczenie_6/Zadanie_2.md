# Zadanie 1
 Znaleźć ile jest liczb w tekście.


```

int liczy_liczby(char *s)
{
    int length = strlen(s);
    int count = 0;
    
    for (int i = 0; i < length; i++)
    
        if(isdigit(s[i])) count++;
        
        return count;
        
    
}
```
