#include <iostream>

void swap(char *a, char *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int *n, int *m)
{
    int temp;

    temp = *n;
    *n = *m;
    *m = temp;
}

void swap(double *n, double *m)
{
    double temp;

    temp = *n;
    *n = *m;
    *m = temp;
}



int main(void)
{
    int num1=20, num2=30;
    swap(&num1, &num2);
    std::cout<<num1<<' '<<num2<<std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;

    double db1 = 1.111, db2=5.555;
    swap(&db1, &db2);
    std::cout<<db1<<' '<<db2<<std::endl;
    return 0;
}
