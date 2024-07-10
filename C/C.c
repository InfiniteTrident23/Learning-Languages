#include <stdio.h>
#include <stdlib.h>
// %f for float DECIMALS
// %d for digits
// %s for string
int main()
{

    char name[]= "Linda";
    int Age= 69;
    printf("\tHello world!\n");
    printf("how are you %s ?\n", name);
    printf("Are %d yrs old?\n", Age);
    printf("No? then?\n");
    Age = 54;
    printf("%d", Age);

    // DATA TYPES

    //integer
    int smth = 420;
    //float (decimal)
    double height = 172.5;
    //Single character
    char smth2= 'm';
    //Multiple Character
    char smth3[]= "fish";
    printf("\n%s", smth3);
    //exponents function
    printf("\n%f", pow(2,3));

    // constants
    const int nigs = 69;
    printf("\n%d\n", nigs);


    //inputs
    /*in scanf, for digits, %d
    for character, %c
    for float, %lf
    for string, %s
    */
    char cunt; //do not give any value
    printf("What is your grade? ");
    // scanf is opposite to printf and allows to take input
    scanf("%c", &cunt);
    //for float, the % in the following line remains same as %f
    printf("Doesn't matter if you said %c, you still are a failure.", cunt);

    //input with strings
    // the number inside [] is the amount of characters allowed
    char hoe[20];
    printf("whats your name? ");
    //no need for & in the case of strings
    scanf("%s", hoe); //but the problem is it won't take " ", spaces, it will only consider the first word
    printf("your fucking name is: %s", hoe);

    //new way to get input is "fgets()", it is more general and can take a whole line as an input
    char FullName[30];
    printf("what your fucking name? ");
    fgets(FullName, 20, stdin);// the number is the amount of characters we want so the user does not enter too many characters and crash the device
    //stdin stands for "Standard Input
    printf("you said ur name was fucking %s ?", FullName);//if I put smth after %s here, it will be printed in a new line

    SayingHello();
    return 0;
}

//making a function
/* "void" means no return
*/
//"main" function is special, don't need to call it
void SayingHello(){
    printf("Hello there!");
}
