#include "../ADT/Mesin/wordmachine.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    int i,j;
    int number, sum, sub,times;
    Word sumversion;
    /* ALGORITMA */
    sum = 0;
    sub = 0;
    times = 1;
    printf("masukkan integer dengan spasi saja and nothing else\n");
    startWord();

    while (!endWord) {
        // Mendisplay masukan dari user
        printf("\"");
        for (i = 0; i < currentWord.length; i++) {
            printf("%c", currentWord.contents[i]);
        }
        printf("\"");
        printf("\n");

        // Mengubah input user jadi angka
        number = wordToInt(currentWord);
        sum += number;
        sub -= number;
        times = times* number;

        printf("hasil sum: %d\n", sum);
        printf("hasil sub: %d\n", sub);
        printf("hasil times: %d\n", times);
        sumversion = intToWord(sum);

        // Mengubah hasil penjumlahan jadi string kembali
        printf("back to string (sum): ");
        for (j=0; j < sumversion.length; j++){
            printf("%c", sumversion.contents[j]);
        }
        printf("\n");
        advWord();
    }
}