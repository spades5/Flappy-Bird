#include <stdio.h>
#include <string.h>

void swap(int *p, int *q) {
    int temp=*p;
    *p=*q;
    *q=temp;
}

void strangeFunc(int a[], int size){
    int*p = a;
    int*q = a+size-1;

    while (p < q) {
        while (p<q && *p>= 0) {  // ���� p �V�k����J��t�ƩζW�L q
            p++;
        }
        while (p<q && *q>= 0) { // ���� q �V������J��t�ƩζW�L p
            q--;
        }
        if (p<q) { // �Y p �M q �����V�t�ơA�h�洫�������~��V������
            swap(p,q);
            p++;
            q--;
        }
    }
}

void printword(int a[], int size){
    printf("{");
    for(int i=0;i<size;i++){
        printf("%d",a[i]);
        if (i < size - 1) printf(", ");
    }
    printf("}\n");
}

int main() {
    int a[13] = {65, 0, -5, -22, 9, 231, 43, -7, 11, -65, 0, -18, 65};
    int b[12] = {65, 0, -5, -22, 9, 231, 43, -7, 11, 65, 0, -18};
    int c[12] = {65, 0, 5, 22, 9, 231, 43, 7, 11, 65, 0, 18};

    printf("��� a[] �� ");
    printword(a,13);

    printf("��� b[] �� ");
    printword(b,12);

    printf("��� c[] �� ");
    printword(c,12);
    printf("\n");

    strangeFunc(a,13);
    strangeFunc(b,12);
    strangeFunc(c,12);

    printf("��� a[] �� ");
    printword(a,13);

    printf("��� b[] �� ");
    printword(b,12);

    printf("��� c[] �� ");
    printword(c,12);

    return 0;
}
