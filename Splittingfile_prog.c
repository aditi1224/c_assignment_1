/* c [rogram to split a file into equal parts */
  #include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main()
  {
        int i = 0, line = 0;
        FILE *fp1, *fp2, *fp3;
        char file1[MAX], file2[MAX], file3[MAX], str[MAX];

        /* get the name without file format(.txt) from user */
        printf("Enter your input file name:");
        scanf("%s", file1);

        /* form the output file names */
        sprintf(file2, "%s_part_%d.txt", file1, 1);
        sprintf(file3, "%s_part_%d.txt", file1, 2);
        strcat(file1, ".txt");

        /* open the input file in read mode */
        fp1 = fopen(file1, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open input file in read mode!!\n");
                return 0;
        }

        /* open the output file in write mode */
        fp2 = fopen(file2, "w");

        /* error handling */
        if (!fp2) {
                printf("Unable to open output file in write mode\n");
                fclose(fp1);
                return 0;
        }

        /* open the output file in write mode */
        fp3 = fopen(file3, "w");

        /* error handling */
        if (!fp3) {
                printf("Unable to open output file2 in write mode\n");
                fclose(fp1);
                fclose(fp2);
                return 0;
        }

        /* calculate the number of lines in input file */
        while (!feof(fp1)) {
                fgets(str, MAX, fp1);
                if (!feof(fp1))
                        line++;
        }

        /* moving the file pointer to the start of file */
        rewind(fp1);

        /* writing first half of data to first output file */
        while (i < line/2) {
                fgets(str, MAX, fp1);
                if (!feof(fp1)) {
                        fputs(str, fp2);
                }
                i++;
        }

        /* writing second half to second output file */
        while (!feof(fp1)) {
                fgets(str, MAX, fp1);
                if (!feof(fp1)) {
                        fputs(str, fp3);
                }
        }

        /* close all opened files */
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);

        /* remove the input file */
        remove(file1);
        return 0;
  }


  
