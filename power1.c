#include <stdio.h>
int power(int n, int p);
int main() {
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf(" %d power %d is %d.", n1, n2, power(n1, n2));
    return 0;
}

int power(int n, int p) {
    if (p!=0){
        return (n*power(n,p-1));
    }
    else{
            return 1;
    }
}
