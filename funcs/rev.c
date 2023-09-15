#include <stdio.h>
void reversesen();
int main() {
    printf("enter the sen u wanna rev: ");
    reversesen();
    return 0;
}
void reversesen(){
    char x;
    scanf_s("%c",&x);
    if (x !='\n'){
        reversesen();
        printf("%c",x);
    }

}

