#include <stdio.h>

// Group together elements of a variety of datatypes that have a logical connection
// like a "super-variable"
// Varuabke declaration
struct car
{
    // Fields
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engine_size;
}

int main(void)
{
    // Varuabke declaration
    struct car mycar;

    // Filed accessing
    mycar.year = 2011;
    strcpy(mycar.plate, "CS50");
    mycar.odometer = 5050;

    // Dynamically allocate at run time
    // Variable declaration
    struct car *mycar2 = malloc(sizeof(struct car));

    // Field accessing
    // *dereferences
    (*mycar).year = 2012;
    strcpy((*mycar).plate, "CS50");
    (*mycar).odometer = 5050;

    // using arrow operator
    mycar->year = 2012;
    strcpy(mycar->plate, "CS50");
    mycar->odometer = 5050;

}
