#include <stdio.h>

int main() {
    // Force input values into specific registers
    register int a asm("x18") = 11;
    register int b asm("x19") = 22;

    // Use fixed register x10 for chaining result
    register int r asm("x20") = 0;

    // Perform a chain of dependent operations 1000 times
    for (int i = 0; i < 1000; i++) {
        asm volatile (
            // Perform addition: r = r + a
            "add x20, x20, x18\n"
            // Perform subtraction: r = r - a
            "sub x20, x20, x18\n"
            // Perform multiplication: r = r * b
            "mul x20, x20, x19\n"
            // Perform addition: r = r + a
            "add x20, x20, x18\n"
            // Perform multiplication: r = r * b
            "mul x20, x20, x19\n"
            // Perform addition: r = r + b
            "add x20, x20, x19\n"
            // Perform subtraction: r = r - a
            "sub x20, x20, x18\n"
            // Perform multiplication: r = r * b
            "mul x20, x20, x19\n"
            
        );
    }

    // Print the final accumulated result
    printf("Result = %d\n", r);
    return 0;
}
