#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * We can use struct to group information together.
 * We can pass structs to a function.
*/
struct Student_t
{

    char name[16];
    int age;
    double gpa;
};
void print_student(struct Student_t stud)
{
    printf("%s\n", stud.name);
    printf("%d\n", stud.age);
    printf("%f\n", stud.gpa);
}
/**
 * If we use the typedef keyword in conjunction with the struct declaration
 * we can declare an instance of the struct without having to use the struct keyword 
 * every time.
*/
typedef struct {
    char name[16];
    char subject[16];
    int age;
} Teacher_t;

void print_teacher(Teacher_t teach)
{
    printf("%s\n", teach.name);
    printf("%d\n", teach.age);
    printf("%s\n", teach.subject); 
}


/**
 * If we declare a struct like the following we can access the members in p1, p2 and p3.
 * So in a way, it's an initialization 
*/
struct Point_t
{
    int x;
    int y;
} p1, p2, p3;

void print_point(struct Point_t p)
{
    printf("x: %d\ty: %d\n", p.x, p.y);
}

void init_points(struct Point_t points[], int size)
{
    /** x values will be increasing, y values decreasing*/
    for (int i = 0; i < size; i++) {
        points[i].x = i;
        points[i].y = size - i - 1;
    }
}

void print_points(struct Point_t points[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d: (%d, %d)\n", i, points[i].x, points[i].y);
    }
}


struct Data_t
{
    int *arr;
};

int main(int argc, char *argv[])
{
    struct Student_t Joseph;
    /** * We cannot asign a string value to an array of characters, we have to use the strcpy() function.*/
    strcpy(Joseph.name, "Joseph");
    Joseph.age = 21;
    Joseph.gpa = 3.5;
    /** We can assign a struct to another struct, and the members will have the same values.
     * Essentially, it's a memory copy
    */
    struct Student_t Kevin = Joseph;
    
    print_student(Joseph);
    print_student(Kevin);

    /** Note that we don't have to use the struct keyword like we did with Student_t
     * This is because we used the typdef keyword when defining the Teacher_t struct
    */
    Teacher_t Bjorn;
    strcpy(Bjorn.name, "Bjorn");
    Bjorn.age = 47;
    strcpy(Bjorn.subject, "History");
    print_teacher(Bjorn);


    /** Here we can access p1 because of the way we declared the struct Point*/
    p1.x = 5;
    p1.y = 7;
    print_point(p1);


    /** We can initialize a declaration of a struct by using '{}',
     * the values will get assigned in the way they are ordered.
    */
    struct Point_t p4 = {10, 20};
    print_point(p4);
    /** Another way of initializing*/
    struct Point_t p5 = {.y = 15, .x = 25};
    print_point(p5);

    /**
     * We can have arrays of structs
    */
    int amount = 3;
   struct Point_t points[amount];
   init_points(points, amount);
   print_points(points, amount);


   struct Data_t d, e;
   d.arr = malloc(sizeof(int) * 5);
   e.arr = malloc(sizeof(int) * 5);

   for (int i = 0; i < 5; i++) {
    d.arr[i] = i;
    e.arr[i] = 5 - i - 1;
   }

   /** Note that if we assign the e variable to the d variable
    * the array is not copied but, instead the address of the array is what's copied.
    * Therefore if we change a value in the d variable, the change also happens in the
    * e variable.
   */
    d = e;
    d.arr[2] = 5;
    printf("e.arr[2]: %d\n", e.arr[2]);
    return 0;
}