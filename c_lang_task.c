#include "c_lang_task.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>


void print_number_table(short col, short row) {
    printf(" ");

    for(int j = 0; j < col*2-1; j++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("|%d", rand() % 9 + 0);
        }
        printf("|\n");
        if (i<row-1) printf("|");
        for (int j = 0; (j < col-1)&(i<row-1); j++) {
            printf("-+");
        }
        if (i<row-1) printf("-|\n");
    }
    printf(" ");
    for (int j = 0; j < col*2-1; j++) {
        printf("*");
    }
    printf("\n");
}

void write_nils_to_head_file(const char* full_fname, int N) {
    FILE *fp;
    fp = fopen(full_fname, "w");
    if (fp == NULL)
      {
        printf("Error: Failed to create file. Task 2.");
        fclose (fp);
        return;
      }
    //char c = 0x0;
    for (int i = 0; i < N; i++) fputc(0x00,fp);
    fclose(fp);
}

void write_ones_to_tail_file(const char* full_fname, int N) {
    FILE *fp;
    fp = fopen(full_fname, "a");
    if (fp == NULL) {
        printf("Error: Failed to create file. Task 3.");
        fclose (fp);
        return;
    }
    //char c = 0xff;
    for (int i = 0; i < N; i++) fputc(0xff,fp);

    fclose(fp);
}

void Init_file (const char* full_fname){
    FILE *fp;
    fp = fopen(full_fname, "w");
    if (fp == NULL) {
        printf("Error: Failed to create file. Task 4.");
        fclose (fp);
        return;
    }

    fprintf(fp, "Aloha\n"
                "Eat some big Kahuna burgers\n"
                "It's very tasty\n"
                "I'm your burger guide\n"
                "Because I stadied bad\n");
    fclose(fp);
    printf(     "Aloha\n"
                "Eat some big Kahuna burgers\n"
                "It's very tasty\n"
                "I'm your burger guide\n"
                "Because I stadied bad\n");

}

int read_i_string_from_file(const char* full_fname, int i, char* out_str, int max_sz) {
    int i_str=1;
    int c;
    FILE *fp;
    fp = fopen(full_fname, "r");

    if (fp == NULL) {
        printf("File not found. Task 4.\n");
        return -1;
      }
    else printf("\nFile open.\n");

    while (i_str <  i) {
         c=fgetc(fp);
         if (c=='\n') {
             i_str++;
         }
         if (feof(fp)) {
             printf("Not enough lines %d in file. Task 4.",i);
             return -1;
         }
    }
    int j = 0;
    out_str[j]=fgetc(fp);
    j++;
    while((!feof(fp))&(j<max_sz)&(out_str[j-1]!='\n')){
        out_str[j]=fgetc(fp);
        j++;
    }
    out_str[j-1]='\0';

    fclose(fp);
    return j;
}


int main() {
    //Task 1
    int a = 0, b = 0;
    printf("Введите количество строк и столбцов:\n");
    scanf("%d%d", &a,&b);
    print_number_table(a, b);
   

    //Task 2, 3
    const char* full_fname = "/home/student/Projects/c_lang_task/File.txt";
    write_nils_to_head_file(full_fname, 5);
    write_ones_to_tail_file(full_fname, 7);


    //Task 6
    read_i_string_from_file();

    printf("\n\nThe END.\n");
}
