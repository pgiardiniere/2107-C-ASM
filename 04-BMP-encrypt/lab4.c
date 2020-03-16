#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// bitmap constants
#define HEADER_SIZE 56
#define SIZE_BEGIN 2
#define WIDTH_BEGIN 18
#define HEIGHT_BEGIN 22

typedef struct Bitmap {         // custom datatype struct for Bitmaps
    unsigned long filesize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    unsigned char * str;
} Bitmap;

// Prototypes
char* read_file(char* filename, unsigned long * filesize);
int  write_file(char* filename, unsigned long   filesize, unsigned char* text);
void make_rand_key(char* key, int length);
void encrypt(char* clearFile, char* keyFile, char* cipherFile);
void decrypt(char* keyFile, char* cipherFile, char* decryptedFile);
Bitmap encode (char* initialBmp, char* encodedBmp, char* cipherFile);
void decode (Bitmap bmp, char* keyFile, char* cipherFile);
void printMenu();

void stringReverse(char * str) {
    char temp[sizeof(str)];
    int i = 0;
    int j = 0;
    while (str[i]) { i++; } i--;    // walk index to end of data

    while (i > -1) {                // reverse in a temp array
        temp[j] = str[i];
        j++;
        i--;
    }
    temp[j] = '\0';
    strcpy(str, temp);              // overwrite original, reverse complete
}

// ##############################
// File IO block
// ##############################
char* read_file(char* filename, unsigned long * filesize) {
    FILE * file = fopen(filename, "rb");
    if (file == NULL) { perror("Error "); exit(1); }
    fseek(file,  0, SEEK_END);
    *filesize = (unsigned long) ftell(file);
    rewind(file);
    
    unsigned char* contents = (unsigned char*) malloc(*filesize * sizeof(char));
    if (contents == NULL) { perror("Error "); exit(1); }
    int read = fread(contents, 1, *filesize, file);
    if (read < *filesize) { printf("Could not read all characters into contents\n"); exit(1); }
    fclose(file);
    return contents;
}

int write_file(char* filename, unsigned long filesize, unsigned char* text) {
    FILE * file = fopen(filename, "wb");
    if (file == NULL) { perror("Error "); exit(1); }

    int written = fwrite(text, 1, filesize, file);
    if (written < filesize) { printf("Could not write all characters\n"); exit(1); }
    fclose(file);
    return written;
}

void make_rand_key(char* key, int length) {     // makes random key in-place (through pointer), and writes it to a file.
    if (length < 0) exit(1);                    // handle case of negative length (as requested in doc)
    int i = 0;
    srand(time(NULL));
    while (i < length) {
        key[i] = (unsigned char) (rand()%255 + 1);       // + 1 so range of vals is 1-255 --- i.e. NO 0 i.e. '\0'
        i++;
    }
}

// ##############################
// Driver methods block
// ##############################

// First  Step : Encrypt
void encrypt(char* clearFile, char* keyFile, char* cipherFile) {
    printf("Encrypting!\n");
    // Get clearText and filesize
    unsigned long filesize = 0;
    unsigned char* clearText = read_file(clearFile, &filesize);
    // Make keyText (appropriately sized by filesize), and write to key.txt 
    unsigned char* keyText = (unsigned char*) malloc(filesize);
    if (keyText == NULL) { perror("Error "); exit(1); }
    int length = filesize / sizeof(char);
    make_rand_key(keyText, length);
    write_file(keyFile, filesize, keyText);
    // Make cipherText via OTP (appropriately sized by filesize), and write to cipher.txt
    unsigned char* cipherText = (unsigned char*) malloc(filesize);
    if (cipherText == NULL) { perror("Error "); exit(1); }
    int i = 0;
    for (i = 0; i < length; i++) { cipherText[i] = clearText[i] ^ keyText[i]; }
    cipherText[i] = '\0';
    write_file(cipherFile, filesize, cipherText);

    free(clearText);
    free(keyText);
    free(cipherText);
    printf("Encrypt complete.\n");
    printf("--Read from : %s and %s\n", keyFile, clearFile);
    printf("--Wrote to  : %s and %s\n", keyFile, cipherFile);
}

// Second Step : Encode
Bitmap encode(char* initialBmp, char* encodedBmp, char* cipherFile) {
    printf("Encoding!\n");
    // Get contents from entire file. Get filesize, width, height, from HEADER
    unsigned int filesize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    unsigned char * str;

    // Open bmp for reading binary
    FILE* file = fopen(initialBmp, "rb");
    if (file == NULL) { perror("Error "); exit(1); }
    // Get filesize from Header
    fseek(file, SIZE_BEGIN, 0);
    fread(&filesize, sizeof(int), 1, file);
    rewind(file);
    // Get imageWidth from Header
    fseek(file, WIDTH_BEGIN, 0);
    fread(&imageWidth, sizeof(int), 1, file);
    rewind(file);
    // Get imageHeight from Header
    fseek(file, HEIGHT_BEGIN, 0);
    fread(&imageHeight, sizeof(int), 1, file);
    fclose(file);
    // Get file contents in buffer (str)
    unsigned long garbage;
    str = read_file(initialBmp, &garbage);
    // feed into BitMap struct
    Bitmap bmp = { filesize, imageWidth, imageHeight, str };

    // first :: manually insert the char '0' --> 48 --> 0011 0000    into our encoded bmp
    unsigned long  cipherSize;
    unsigned char* cipherText = read_file(cipherFile, &cipherSize);

    // write each bit of cipher char 'val' onto the Least Significant bit of 8 chars in bmp.str (w/ begin index after header data)
    unsigned char val;
    int i = 0;
    int j = 56;
    for (i = 0; i < cipherSize; i++) {
        val = cipherText[i];
        j += 7;                         // advance j to end of current byte-block
        while (val) {
            while (bmp.str[j]) {
                if (val & 1)
                    { bmp.str[j] |= 1; break; }         // write '1' to least bit in str[j] (0000 0001)
                else
                    { bmp.str[j] &= 254; break; }       // write '0' to least bit in str[j] (1111 1110)
            }
            j--;
            val >>= 1;
        }
        while ( (j+1) % 8 != 0) {       // append leading 0s to current byte-block
            while (bmp.str[j]) {
                bmp.str[j] &= 254;
                break;
            }            
            j--;
        }
        j += 9;                         // advance j to next byte-block
    }

    write_file(encodedBmp, bmp.filesize, bmp.str);
    free(cipherText);
    printf("Encode complete.\n");
    printf("--Read from : %s and %s\n", initialBmp, cipherFile);
    printf("--Wrote to  : %s\n", encodedBmp);
    return bmp;
}

// Third Step : Decode
void decode(Bitmap bmp, char* keyFile, char* cipherFile) { // given encoded bmp and length of keyFile, create cipherFile.
    printf("Decoding!\n");
    // get length of cipherText. OTP works on strings of same size. Thus, encoded cipher must be same length as the recipient's keyFile
    unsigned long len = 0;
    read_file(keyFile, &len);

    char* cipherTxt = (char*) malloc(len + 1);
    if (cipherTxt == NULL) { perror("Error :"); exit(1); }

    // over length of cipher in chars, read 8 least significant bits of bmp.str[] into chars val
    unsigned char val;
    unsigned int i = 0;
    unsigned int j = 56;
    for (i = 0; i < len; i++) {
        val = 255;                  // set val to uchar 255 ->  1111 1111    bin rep.
        int k = 0;
        while (val && k < 8) {
            while (bmp.str[j]) {
                if (bmp.str[j] & 1)
                    { val |=   1; break; } // val = val | 1     1111 1111 | 0000 0001 == 1111 1111
                else {
                    { val &= 254; break; } // val = val & 254   1111 1111 & 1111 1110 == 1111 1110
                }
            }
            j++;
            k++;
            if (k == 8) break;            
            val <<= 1;
        }
        // printf("From the read-in binary, we see decimal value of char 'val' is %d.\n it's char value is : %c\n\n", val, val);
        cipherTxt[i] = val;
    }
    cipherTxt[i] = '\0';                                // cipherTxt now contains all hidden chars, and is null-terminated. write to file.
    write_file("decoded-cipher.txt", len, cipherTxt);   // Do string literal "cipher.txt" if you want decrypt() to use it.

    printf("Decode complete.\n");
    printf("--Read from : bmp.str (passed in), %s and %s\n", keyFile, cipherFile);
    printf("--Wrote to  : %s\n", "decoded-cipher.txt");
    free(cipherTxt);
    free(bmp.str);
}

// Fourth Step : Decrypt
void decrypt(char* keyFile, char* cipherFile, char* decryptedFile) {
    printf("Decrypting!\n");
    // Get cipherText, keyText, and filesize
    unsigned long filesize = 0;
    char* cipherText = read_file(cipherFile, &filesize);
    char* keyText = read_file(keyFile, &filesize);
    // Make decryptedText via OTP (appropriately sized by filesize), and write to decrypted.txt
    char* decryptedText = (char*) malloc(filesize);
    if (decryptedText == NULL) { perror("Error"); exit(1); }
    int length = filesize / sizeof(char);
    int i = 0;
    for (i=0; i < length; i++) { decryptedText[i] = keyText[i] ^ cipherText[i]; }
    decryptedText[i] = '\0';
    write_file(decryptedFile, filesize, decryptedText);

    free(decryptedText);
    free(keyText);
    free(cipherText);
    printf("Decrypt complete.\n");
    printf("--Read from : %s and %s\n", keyFile, cipherFile);
    printf("--Wrote to  : %s\n", decryptedFile);
}

int main() {
    // file strings
    char clearFile[] = "clear.txt";
    char cipherFile[] = "cipher.txt";
    char keyFile[] = "key.txt";
    char decryptedFile[] = "decrypted.txt";
    char initialBmp[] = "sample.bmp";
    char encodedBmp[] = "encoded.bmp";
    Bitmap bmp;

    // User input loop :: choose between 5 menu options.
    int coerced = 1;
    char in[256];
    while (1) {
        printMenu();
        fgets(in, 256, stdin);
        in[strcspn(in, "\n")] = 0;          // fgets reads in newline char, replace it w/ null (ascii 0) 
        coerced = atoi(in);
        // perform menu option selected or re-prompt for input.
        if (coerced < 1 || coerced > 5) { printf("That didn't work. Try a valid menu option. They are:\n"); }
        if (coerced == 1) { encrypt(clearFile, keyFile, cipherFile); }
        if (coerced == 2) { decrypt(keyFile, cipherFile, decryptedFile); }
        if (coerced == 3) { bmp = encode(initialBmp, encodedBmp, cipherFile); }
        if (coerced == 4) {       decode(bmp, keyFile, cipherFile); }
        if (coerced == 5) { 
            // all string/buffer memory was freed in methods used in. No free()s required here.
            return 0;
        }
    }
}

void printMenu() {
    printf("    Encrypt a file:  1\n");
    printf("    Decrypt a file:  2\n");
    printf("    Encode a bitmap: 3\n");
    printf("    Decode a bitmap: 4\n");
    printf("    Exit:            5\n");
    printf("    Enter a choice:  ");
}