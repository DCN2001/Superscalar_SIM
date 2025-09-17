#include <stdio.h>

int main() {
    register int a asm("x18") = 11;
    register int b asm("x19") = 22;

    for (int i = 0; i < 50; i++) {
      asm volatile(
          "add x20, x18, x19\n"
          "sub x20, x18, x19\n"
    );
}


    return 0;
}