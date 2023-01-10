# Zadanie 1
 Znaleźć i skasować te same długie słowo w tekście.


```
for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			matrica[k][j] = '\0';
			k ++;
			j = 0;
		}
		else
		{
			matrica[k][j] = str[i];
			j ++;
		}
	}
 
	matrica[k][j] = '\0';
 
	j = 0;
	
	 length = i + 1;
	 
	  strcpy(large, matrica[0]); 
	  
	for (i = 0; i < k; i++)
	{
		int present = 0;
		for (l = 1; l < k + 1; l++)
		{
if (matrica[l][j] == '\0' || l == i )
			{
			     
				continue;
			}
 
			if (strcmp (matrica[i], matrica[l]) == 0 && strlen(large) < strlen(matrica[l])) { 
				matrica[l][j] = '\0';
				present = present + 1;
			}
			
		
		}
		if (present > 0 )	   
		{			     
		matrica[i][j] = '\0';   
		 }	
	
	}
 
	j = 0;
 
	for (i = 0; i < k + 1; i++)
	{
		if (matrica[i][j] == '\0')
			continue;
		else
			printf ("%s ", matrica[i]);
	}
```
