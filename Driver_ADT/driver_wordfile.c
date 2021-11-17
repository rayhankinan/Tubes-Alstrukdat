// driver wordfile

#include "../ADT/Mesin/wordmachinefile.h"
#include <stdio.h>

int main()
{
    int i;

    char input[20];
    printf("put in path file\n");
    scanf("%[^\n]s", input);

    // inisialisasi pembacaan file
    startWordFile(input);
    printf("isi dari file adalah sebagai berikut: \n\n");
    while (currentCharFile != '.'){
        //display kata
        for (i = 0; i < currentWordFile.length; i++){
            printf("%c", currentWordFile.contents[i]);
        }
        printf("\n");
        // lanjut ke kata berikutnya
        advWordFile();
        if (currentCharFile = '\n'){
            advCharFile();
        }
        // berhenti kalau sudah ada mark
        if (currentCharFile == '.' ){
            stopWordFile();
        }
    }
    return 0;
}

