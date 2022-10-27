#include <stdio.h>
int main()
{
    struct BitField
    {
        unsigned int a : 3;
        int b : 2;
        unsigned int c : 1;
    };
    struct BitField bitfield;
    bitfield.a = 125; // bitfield.a = x  -> while(bitfield.a is not in the range) -> bitfield.a = num +- (2^3)
    bitfield.b = -5;  // bitfield.b = x  -> while(bitfield.b is not in the range) -> bitfield.b = num +- (2^2)
    bitfield.c = -1;
    printf("%d\n%d\n%d\n", bitfield.a, bitfield.b, bitfield.c);
    printf("sizeof(struct BitField) is %llu\n", sizeof(struct BitField));

    printf("125%(2^3)=%d\n", 125 % (1 << 3));
    printf("(-5)%(2^2)=%d\n", -5 % (1 << 2));
}
