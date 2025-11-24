#include <stdio.h>

int main() {
    FILE *fp = fopen("myfile.txt", "w");

    if(fp == NULL) {
        printf("File creation failed.\n");
        return 1;
    }

    fprintf(fp, "Hello! This is a sample file.\n");
    fclose(fp);

    printf("File written successfully.\n");
    return 0;
}
