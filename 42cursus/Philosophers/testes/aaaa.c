// int main()
// {
//     int n = 0;
//     while (1)
//         n++;
// }



// int main(void)
// {
//     pthread_t   id1, id2;

    
//     return (0);
// }



// #include <stdio.h>

// int main(void)
// {
//     if (-1)
//         printf("teste\n");
//     return (0);
// }




// #include <stdio.h>

// int *teste()
// {
//     static int  i = 0;

//     i++;
//     return (&i);
// }

// int main(void)
// {
//     int *ptr;

//     ptr = teste();

//     int i = 0;
//     while (i < 3)
//     {
//         printf("teste: %d\n", *ptr);
//         teste();
//         i++;
//     }

//     return (0);
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *teste(char c)
{
    static char  *str = malloc(10 * sizeof(char));

    str[strlen(str)] = c;
    return (str);
}

int main(void)
{
    char *ptr;

    ptr = teste('a');

    int i = 0;
    while (i < 3)
    {
        printf("teste: %s\n", ptr);
        teste('a');
        i++;
    }

    return (0);
}