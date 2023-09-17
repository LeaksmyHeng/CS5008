#include <stdio.h>
#include <math.h>


int double_power(int double_base, int double_int){
    int result;
    result = pow(double_base, double_int);
    return result;
}

int main()
{
    int loop, double_power_result;
    int double_base = 2, max_loop = 11;
    int double_power();
    for(loop = 1; loop < max_loop; loop++){
        double_power_result = double_power(double_base, loop); 
        printf("Result of 2^%d: %d\n", loop, double_power_result);
    }

    return 0;
}
