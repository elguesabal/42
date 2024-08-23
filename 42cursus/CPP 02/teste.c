#include <unistd.h>
#include <stdio.h>

// int main(void) {
//     char c;

//     c = c << 0;
//     c = c << 1;
//     c = c << 0;
//     c = c << 0;
//     c = c << 0;
//     c = c << 0;
//     c = c << 0;
//     c = c << 1;

//     printf("teste: \"%c\"\n", c);

//     return (0);
// }



int main(void) {
    // int x = 10;

    // printf("teste: %d\n", x);
    // x = x << 1;
    // printf("teste: %d\n", x);
    // x = x | 1;
    // printf("teste: %d\n", x);



    // 42             -> 101010
    // 666            -> 1010011010
    // int ft = 42;   // 101010

    // ft = ft >> 1;  // 10101
    // ft = ft >> 1;  // 1010
    // ft = ft << 1;  // 10100
    // ft = ft << 1;  // 101000
    // ft = ft | 1;   // 101001
    // ft = ft << 1;  // 1010010
    // ft = ft | 1;   // 1010011
    // ft = ft << 1;  // 10100110
    // ft = ft << 1;  // 101001100
    // ft = ft | 1;   // 101001101
    // ft = ft << 1;  // 1010011010

    // printf("teste: %d\n", ft);



    // 0              -> 000000
    // 42             -> 101010
    int ft = 0;       // 0

    ft = ft | 1;      // 1
    ft = ft << 1;     // 10
    ft = ft << 1;     // 100
    ft = ft | 1;      // 101
    ft = ft << 1;     // 1010
    ft = ft << 1;     // 10100
    ft = ft | 1;      // 10101
    ft = ft << 1;     // 101010

    printf("teste: %d\n", ft);

    return (0);
}
