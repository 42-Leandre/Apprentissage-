#include <stdio.h>
#include <stdlib.h>

int is_sep(char c, char *charset)
{
    int i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return (1);
        i++;    
    }
    return (0);
}

int wordlen (char *str, char *charset)
{
    int i = 0;
    while (str[i] && !is_sep(str[i], charset))
        i++;
    return (i);
}

int countword(char *str, char *charset)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0')
    {
        if (!is_sep(str[i], charset) &&
         (i == 0 || is_sep(str[i - 1], charset)))
            count++;
        i++;
    }
    return(count);

}
char *mallocword(char *str, char *charset)
{
    int len = wordlen(str, charset);
    char *word = malloc(sizeof(char) * (len + 1));
        if (word == NULL)
            return (NULL);
    
    int i = 0;
    while (i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int j = 0;

    int numberword = countword(str, charset);
    char **result = malloc(sizeof(char *) * (numberword + 1));
    if (!result)
        return (NULL);
    
    while (str[i])
    {
        if (!is_sep(str[i], charset))
        {
            result[j] = mallocword(&str[i], charset);
            j++;

            while (str[i] && !is_sep(str[i], charset))
                i++;
        }
        else
            i++;

    }
    result[j] = NULL;
    
    return (result);
}

int main(void)
{
    int i = 0;
    char **result;
    result = ft_split("   hello! , world  ", ",! ");
    
    if (result == NULL)
        return (1);

    while (result[i])
    {
        printf("mot %d : %s\n", i, result[i]);
        i++;
    }

    i = 0;
    while(result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);    
    
    return(0);
}