/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : 13224031
 *   Nama File           : soal2.c
 *   Deskripsi           : Mengerjakan soal 2 - Tambahan Segel Menggunakan Struct dan Dynamic Array yaitu Stack
 * 
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;


void push(Node** top, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}


void pop(Node** top) {
    if (*top != NULL) {
        Node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    char str[255];
    scanf("%s", str);

    Node* stack = NULL;
    int kurang_buka = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(&stack, str[i]);
        } else if (str[i] == ')') {
            if (stack != NULL) {
                pop(&stack);
            } else {
                kurang_buka++;
            }
        }
    }

    
    int kurang_tutup = 0;
    while (stack != NULL) {
        kurang_tutup++;
        pop(&stack); 
    }

    int kurung_total = kurang_buka + kurang_tutup;
    printf("%d\n", kurung_total);

    return 0;
}
