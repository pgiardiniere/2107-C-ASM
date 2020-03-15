#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// bitmap constants
#define SIZE_BEGIN 1500056      // 1,500,000 = 1000 x 500 x 3 (bytes / pixel. 24 bit-depth) + 56 (header)
#define HEADER_SIZE 56          // actually, disregard header. we aren't reading/writing at all. SIZE_BEGIN.
#define WIDTH_BEGIN 1000
#define HEIGHT_BEGIN 500

typedef struct Bitmap {         // custom datatype struct for Bitmaps
    unsigned long filesize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    char * str;
} Bitmap;

// Prototypes
char* read_file(char* filename, unsigned long * filesize);
int  write_file(char* filename, unsigned long   filesize, char* text);
Bitmap       read_bmp (char *filename);
unsigned int write_bmp(char *filename, Bitmap m);
void printMenu();
                    
void make_rand_key(char* key, int length);
void encrypt(char* clearFile, char* keyFile, char* cipherFile);
void decrypt(char* keyFile, char* cipherFile, char* decryptedFile);

void encode ();
void decode ();

// ##############################
// File IO block
// ##############################
char* read_file(char* filename, unsigned long * filesize) {
    FILE * file = fopen(filename, "rb");                            // Open file.
    if (file == NULL) { perror("Error "); exit(1); }                // If failure, print error and quit program
    fseek(file,  0, SEEK_END);                                  // get size (bytes), assign to filesize, rewind strm
    *filesize = (unsigned long) ftell(file);
    rewind(file);
    
    char* contents = (char*) malloc(*filesize * sizeof(char));  // allocate space in bytes. If failure, return text
    if (contents == NULL) { perror("Error "); exit(1); }        // If failure, print error and quit program
    fread(contents, 1, *filesize, file);                        // save string,  close file, return pointer
    fclose(file);
    return contents;
}

int write_file(char* filename, unsigned long filesize, char* text) {
    FILE * file = fopen(filename, "wb");
    if (file == NULL) { perror("Error "); exit(1); }

    int written = 0;
    written = fwrite(text, 1, filesize, file);
    if (written < filesize) { printf("Could not write all characters\n"); exit(1); }
    fclose(file);
    return written;
}

void make_rand_key(char* key, int length) {     // makes random key in-place (through pointer), and writes it to a file.
    if (length < 0) exit(1);                    // handle case of negative length (as requested in doc)
    int i = 0;
    srand(time(NULL));
    while (i < length) {
        key[i] = (char) (rand()%255 + 1);       // + 1 so range of vals is 1-255 --- i.e. NO 0 i.e. '\0'
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
    char* clearText = read_file(clearFile, &filesize);
    // Make keyText (appropriately sized by filesize), and write to key.txt 
    char* keyText = (char*) malloc(filesize);
    if (keyText == NULL) { perror("Error "); exit(1); }
    int length = filesize / sizeof(char);
    make_rand_key(keyText, length);
    write_file(keyFile, filesize, keyText);
    // Make cipherText via OTP (appropriately sized by filesize), and write to cipher.txt
    char* cipherText = (char*) malloc(filesize);
    if (cipherText == NULL) { perror("Error "); exit(1); }
    int i = 0;
    for (i = 0; i < length; i++) { cipherText[i] = clearText[i] ^ keyText[i]; }
    cipherText[i] = '\0';
    write_file(cipherFile, filesize, cipherText);

    free(clearText);
    free(keyText);
    free(cipherText);
}

// Second Step : Encode

// Third  Step : Decode

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
}


int main() {
    // file strings
    char clearFile[] = "clear.txt";
    char cipherFile[] = "cipher.txt";
    char keyFile[] = "key.txt";
    char decryptedFile[] = "decrypted.txt";
    char initBmp[] = "sample.bmp";
    char encodedBmp[] = "encoded.bmp";
    char decodedBmp[] = "decoded.bmp";

    // Bitmap bmp = construct();
    // printf("Bitmap 'bmp' data field 'filesize' is: %lu\n", bmp.filesize);
    // printf("Bitmap 'bmp' data field 'str' is: %s\n", bmp.str);
    // free(bmp.str);

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
        if (coerced == 3) printf("todo : encode\n"); // { encode (clearBmp); }
        if (coerced == 4) printf("todo : decode\n"); // { decode (); }
        if (coerced == 5) { 
            // free all memory before exit
            // free(bmp.str);
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