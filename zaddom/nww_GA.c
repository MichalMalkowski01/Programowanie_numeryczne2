#include <stdio.h>

int main() 
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    int x, y, z;
    for (x = a, y = b; y != 0;)
    {
        z = x % y;
        x = y;
        y = z;
    }
    
    printf("%d", a*b/x);

    return 0;
}