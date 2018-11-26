/* c program to merge files */
#include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main() {
        int ch;
        FILE *fp1, *fp2, *fp3;
        char fname1[MAX], fname2[MAX], temp[] = {"temp.txt"};

        /* get the first input file name from the user */
        printf("Enter your first file name:");
        fgets(fname1, MAX, stdin);
        fname1[strlen(fname1) - 1] = '\0';

        /* get the second input file name from the user */
        printf("Enter your second file name:");
        fgets(fname2, MAX, stdin);
        fname2[strlen(fname2) - 1] = '\0';

        /* open first input file in read mode */
        fp1 = fopen(fname1, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open input file %s\n", fname1);
                return 0;
        }

        /* open second input file in read mode */
        fp2 = fopen(fname2, "r");

        /* error handling */
        if (!fp2) {
                printf("Unable to open input file %s\n", fname2);
                fclose(fp1);
                return 0;
        }

        /*
         * open a temporary file to write the contents
         * of first and second input files
         */
        fp3 = fopen(temp, "w");

        /* error handling */
        if (!fp3) {
                printf("Unable to open temporary file to write!!\n");
                return 0;
        }

        /* copy the contents of first file to temporary file */
        while ((ch = fgetc(fp1)) != EOF) {
                fputc(ch, fp3);
        }

        /* copy the contents of second file to temporary file */
        while ((ch = fgetc(fp2)) != EOF) {
                fputc(ch, fp3);
        }

        /* close all opened files */
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);

        /* remove the input files */
        remove(fname1);
        remove(fname2);
        /* rename the temporary file to first file name */
        rename(temp, fname1);

        return 0;
        }
