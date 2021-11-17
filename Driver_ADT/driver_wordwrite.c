// Driver writemachine

#include "../ADT/Mesin/writemachine.h"
#include <stdio.h>


int main(){
    char isifile[200];

    printf("masukkan isi yang ingin dimasukkan dalam file diakhiri '.' max(200 char)!!\n");
    scanf("%[^.]s", isifile);

    startFile("output_wordwrite.txt");
    printfFile("%s\n", isifile);
    endFile();
}
