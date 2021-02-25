#include "cgraph.h"
#include <stdio.h>

#define TYPE_FLOAT32
#include "template.h"

TYPE function_x(const TYPE x) { return x * x; }

int main(int argc, char *argv[])
{
    cgraph_size_t i, j, k;
    TYPE data[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    fprintf(stdout, "%g\n", FUNCTION(NAME, sqrt)(2));
    fprintf(stdout, "%g\n", FUNCTION(NAME, cube)(2));
    fprintf(stdout, "%g\n",
            FUNCTION(NAME, integral_range_trapezoidal)(0.1, 0.2, 0.00001,
                                                       &function_x));
    fprintf(stdout, "%g\n",
            FUNCTION(NAME, integral_range_trapezoidal)(0.2, 0.1, 0.00001,
                                                       &function_x));
    fprintf(
        stdout, "%g\n",
        FUNCTION(NAME, integral_range_simpson)(0.1, 0.2, 0.00001, &function_x));
    fprintf(
        stdout, "%g\n",
        FUNCTION(NAME, integral_range_simpson)(0.2, 0.1, 0.00001, &function_x));
    fprintf(stdout, "%g\n",
            FUNCTION(NAME, integral_range_simpson38)(0.1, 0.2, 0.00001,
                                                     &function_x));
    fprintf(stdout, "%g\n",
            FUNCTION(NAME, integral_range_simpson38)(0.2, 0.1, 0.00001,
                                                     &function_x));
    fprintf(
        stdout, "%g\n",
        FUNCTION(NAME, integral_range_cotes)(0.1, 0.2, 0.00001, &function_x));
    fprintf(
        stdout, "%g\n",
        FUNCTION(NAME, integral_range_cotes)(0.2, 0.1, 0.00001, &function_x));

    FUNCTION(NAME, transpose)(data, 2, 2);
    FUNCTION(NAME, transpose)(data, 1, 2);
    FUNCTION(NAME, sub_symmetry)(data, 2, 2);
    FUNCTION(NAME, sub_symmetry)(data, 1, 2);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            fprintf(stdout, "%g ", data[i * 2 + j]);
        }
        fprintf(stdout, "\n");
    }
    FUNCTION(NAME, rotation1I)(data, 2, 3);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            fprintf(stdout, "%g ", data[i * 2 + j]);
        }
        fprintf(stdout, "\n");
    }
    FUNCTION(NAME, rotation1I)(data, 1, 2);
    fprintf(stdout, "%g\n", FUNCTION(NAME, exp)(1.0));
    fprintf(stdout, "%g\n", FUNCTION(NAME, exp)(2.0));
    fprintf(stdout, "%g\n", FUNCTION(NAME, exp)(3.0));
    fprintf(stdout, "pi = %g\n", FUNCTION(NAME, pi)());

    return 0;
}

#include "template_off.h"