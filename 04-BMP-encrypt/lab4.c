#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// bitmap constants
#define HEADER_SIZE 54
#define SIZE_BEGIN 2
#define WIDTH_BEGIN 18
#define HEIGHT_BEGIN 22

// custom datatype struct for Bitmaps
typedef struct Bitmap {
    unsigned int filesize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    char * bmpStr;
} Bitmap;

Bitmap construct() {
    unsigned int filesize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    // malloc() a char[] which can fit contents of the file

    Bitmap bmp = {filesize, imageWidth, imageHeight, bmpStr}; 
    return bmp;
}

// prototypes :: file IO & output
char* read_file(char* filename, unsigned long * filesize);
int  write_file(char* filename, unsigned long   filesize, char* text);
Bitmap       read_bmp (char *filename);
unsigned int write_bmp(char *filename, Bitmap m);
void printMenu();

// prototypes :: encryption
void make_rand_key(char* key, int length);
void encrypt(char* clearFile, char* keyFile, char* cipherFile);
void decrypt(char* keyFile, char* cipherFile, char* decryptedFile);
void encode ();
void decode ();

// #########################
// LAB 3 functions
// #########################

char* read_file(char* filename, unsigned long * filesize) {
    FILE * file = fopen(filename, "rb");                        // Open file.
    if (file == NULL) { perror("Error "); exit(0); }           // If failure, print error and quit program
    fseek(file, 0, SEEK_END);                                   // get size (bytes), assign to filesize, rewind strm
    *filesize = (unsigned long) ftell(file);
    rewind(file);
    
    char* contents = (char*) malloc(*filesize * sizeof(char));  // allocate space in bytes. If failure, return text
    if (contents == NULL) { perror("Error "); exit(0); }       // If failure, print error and quit program
    fread(contents, 1, *filesize, file);                        // save string,  close file, return pointer
    fclose(file);
    return contents;
}

int write_file(char* filename, unsigned long filesize, char* text) {
    FILE * file = fopen(filename, "wb");
    if (file == NULL) { perror("Error "); exit(0); }

    int written = 0;
    written = fwrite(text, 1, filesize, file);
    if (written < filesize) { printf("Could not write all characters\n"); exit(0); }

    fclose(file);
    return written;
}

void make_rand_key(char* key, int length) {     // makes random key in-place (through pointer), and writes it to a file.
    if (length < 0) exit(0);                    // handle case of negative length (as requested in doc)
    int i = 0;
    srand(time(NULL));
    while (i < length) {
        key[i] = (char) (rand()%255 + 1);       // + 1 so range of vals is 1-255 --- i.e. NO 0 i.e. '\0'
        i++;
    }
}

void encrypt(char* clearFile, char* keyFile, char* cipherFile) {
    printf("Encrypting!\n");
    // Get clearText and filesize
    unsigned long filesize = 0;
    char* clearText = read_file(clearFile, &filesize);
    // Make keyText (appropriately sized by filesize), and write to key.txt 
    char* keyText = (char*) malloc(filesize);
    if (keyText == NULL) { perror("Error "); exit(0); }
    int length = filesize / sizeof(char);
    make_rand_key(keyText, length);
    write_file(keyFile, filesize, keyText);
    // Make cipherText via OTP (appropriately sized by filesize), and write to cipher.txt
    char* cipherText = (char*) malloc(filesize);
    if (cipherText == NULL) { perror("Error "); exit(0); }
    int i = 0;
    for (i = 0; i < length; i++) { cipherText[i] = clearText[i] ^ keyText[i]; }
    cipherText[i] = '\0';
    write_file(cipherFile, filesize, cipherText);

    free(clearText);
    free(keyText);
    free(cipherText);
}

void decrypt(char* keyFile, char* cipherFile, char* decryptedFile) {
    printf("Decrypting!\n");
    // Get cipherText, keyText, and filesize
    unsigned long filesize = 0;
    char* cipherText = read_file(cipherFile, &filesize);
    char* keyText = read_file(keyFile, &filesize);
    // Make decryptedText via OTP (appropriately sized by filesize), and write to decrypted.txt
    char* decryptedText = (char*) malloc(filesize);
    if (decryptedText == NULL) { perror("Error"); exit(0); }
    int length = filesize / sizeof(char);
    int i = 0;
    for (i=0; i < length; i++) { decryptedText[i] = keyText[i] ^ cipherText[i]; }
    decryptedText[i] = '\0';
    write_file(decryptedFile, filesize, decryptedText);

    free(decryptedText);
    free(keyText);
    free(cipherText);
}

// #########################
// LAB 4 functions
// #########################

Bitmap read_bmp(char* filename) {
    Bitmap bmp;
    return bmp;
}

unsigned int write_bmp(char* filename, Bitmap m)  {
    unsigned int i = 1;
    return i;
}

void encode(char* clearBmp) {
    printf("Encoding!\n");
    // Get bmp
    // unsigned long filesize = 0;      // not used
    Bitmap bmp = read_bmp(clearFile);
}

void decode() {
    printf("Decoding!\n");
}

void printMenu() {
    printf("    Encrypt a file:  1\n");
    printf("    Decrypt a file:  2\n");
    printf("    Encode a bitmap: 3\n");
    printf("    Decode a bitmap: 4\n");
    printf("    Exit:            5\n");
    printf("    Enter a choice:  ");
}

int main() {
    char clearFile[] = "clear.txt";         // file strings :: lab3
    char cipherFile[] = "cipher.txt";
    char keyFile[] = "key.txt";
    char decryptedFile[] = "decrypted.txt";
    
    char clearBmp[] = "clear.bmp";          // file strings :: lab4
    char cipherBmp[] = "coded.bmp";    
    char keyBmp[] = "bmpKey.txt";
    char decryptedBmp[] = "decoded.bmp";

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
        if (coerced == 3) { encode (clearBmp); }
        if (coerced == 4) { decode (); }
        if (coerced == 5) { return 0; }
    }
}