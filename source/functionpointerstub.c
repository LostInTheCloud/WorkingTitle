#include <stdio.h>

int func1(const char* name)
{
   printf("Hello %s! I'm Func 1\n", name);
   return 1;
}

int func2(const char* name)
{
    printf("Hello %s! I'm Func 2\n", name);
    return 2;
}

// int is the return data type
// funcs is the name of the array
// const char* is the parameter list, could be multiple params
int (*funcs[2])(const char*) = {func1, func2};

int main()
{
    int num;
    for(int i = 0; i<2; i++)
    {
        // call the funcstion like this
        num = funcs[i]("Tom");
        printf("*That was Func %i*\n", num);
    }
}