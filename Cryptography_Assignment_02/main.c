//
//  main.c
//  Cryptography_Assignment_02
//
//  Created by Luke Queenan on 2016-07-03.
//  Copyright © 2016 Luke Queenan. All rights reserved.
//

#include <stdio.h>

#define KEY_LENGTH 31

void oneTimePad();

int main(int argc, const char * argv[]) {

    oneTimePad();
    
    return 0;
}


/* Function used to generate the ciphertext. */
void oneTimePad() {
    unsigned char ch;
    FILE *fpIn, *fpOut;
    int i;
    unsigned char key[KEY_LENGTH] = {0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00};
    // Of course, I did not use the all-0 key when generating the 7 ciphertexts above!
    
    fpIn = fopen("messages.txt", "r");
    fpOut = fopen("ctexts.txt", "w");
    
    i=0;
    
    while (fscanf(fpIn, "%c", &ch) != EOF) {
        fprintf(fpOut, "%02X", ch^key[i]);
        i++;
        if (i==31) {
            fprintf(fpOut, "\n");
            i=0;
            fscanf(fpIn, "%c", &ch);
        }
    }
    
    fclose(fpIn);
    fclose(fpOut);
}
