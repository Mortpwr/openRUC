#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char expr[1000001] = {0};
    scanf("%s", expr);

    char *add_token, *add_saveptr;
    char *mul_token, *mul_saveptr;
    long long total = 0;

    
    add_token = strtok_r(expr, "+", &add_saveptr);
    while (add_token != NULL)
    {
        long long product = 1;

        
        mul_token = strtok_r(add_token, "*", &mul_saveptr);
        while (mul_token != NULL)
        {
            product = (product % 10000 *strtoll(mul_token, NULL, 10) % 10000) % 10000;
            mul_token = strtok_r(NULL, "*", &mul_saveptr);
        }

        total += product % 10000;
        add_token = strtok_r(NULL, "+", &add_saveptr);
        total = total % 10000;
    }

   
    printf("%lld\n", total);
    return 0;
}