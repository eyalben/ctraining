/*
    Strings
*/

#include <stdio.h>
#include <stdint.h>

/* We can change global variables, so this line is changable: */
char  g_question1[] = { "Hodor?" };

/* We can change the pointer - but it points to the data-section which is r/o */
char *g_question2 = "Hodor?";

int main(void) 
{
    /* (0) Strings */

    /* All equivalent - all size of 6 */
    char name1[] = { "hodor" };
    char name2[] = { 'h', 'o', 'd', 'o', 'r', '\0' };
    char name3[6] = { 'h', 'o', 'd', 'o', 'r', '\0' };
    char name4[] = "hodor";

    /* Null-Termination is Zero*/
    printf("Is equal? %d\n", ('\0' == 0));


    /* (1) Global vs Data Section vs Stack */

    /* Data Section (r/o) */
    char *question = "Hodor?";
    printf("Size of question: %ld\n", sizeof(question));

    /* Illegal: */
    /* question[5] = "!"; */

    /* Global Variables */
    printf("Size of g_question1: %ld\n", sizeof(g_question1));
    printf("Size of g_question2: %ld\n", sizeof(g_question2));
    
    g_question1[5] = '!';
    printf("Hodor? %s\n", g_question1);

    // All annoying questions answered:

    char * name_string = "hodor";
    g_question1[3] = 1; // OK
    // g_question1++; // not allowed
    // g_question2[2] = 1; // segmentation fault
    g_question2 = g_question1;
    g_question2[2] = 1; // OK
    name1[3] = 1; // OK
    // name_string[2] = 1; // segmentation fault
    name_string = name1;
    name_string[2] = 1; // OK

    // Advanced - sometimes doesnt work:
    // show that gcc -m32 -S compiles the below into the stack (maybe needs -masm=intel)
    // char name1[] = { "AAAA" }; => hex(1094795585)

    return 0;
}