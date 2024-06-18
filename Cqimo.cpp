// #include<stdio.h>
// #include<iostream>
// #include<cstring>
// int main(){
//     // int n1 = 0, n2 = 1, *p = &n2, *q = &n1;
//     // p = q;
//     // std::cout << p << ' ' << *p << std::endl;
//     // std::cout << q << ' ' << *q << std::endl;
//     // std::cout << n1 << ' ' << n2 << std::endl;
//     // char ch1[] = {'a', 'b', 'c', 'd','\0'};
//     // char ch2[] = {'A', 'B', 'C', 'D','\0'};
//     // std::cout << ch1 << std::endl;
//     // std::cout << ch2 << std::endl;
//     // strcpy(ch1, ch2);
//     // std::cout << ch1 << std::endl;
//     // std::cout << ch2 << std::endl;
//     // char *p1, *p2, str[50] = "ABCDEFG";

//     // p1 = "abcd";
//     // p2 = "efgh";

//     // strcpy(str + 1, p2 + 1);//Afgh

//     // strcpy(str + 3, p1 + 3);//Afgd

//     // printf("%s", str);
//     char ch[] = {'a', 'b', 'c', 'd'};
//     std::cout << sizeof(ch) << std::endl;
//     char ch1[20] = {'a', 'b', 'c', 'd'};
//     std::cout << sizeof(ch1) << std::endl;
//     char ch2[] = "abcd";
//     std::cout << sizeof(ch2) << std::endl;
//     std::cout << strlen(ch2) << std::endl;
//     // char p[20] = {'a', 'b', 'c', 'd'}, q[] = "abc", r[] = "abcde";

//     // strcpy(p + strlen(q), r);

//     // strcat(p, q);

//     // printf("%d%d\n", sizeof(p), strlen(p));
//     return 0;
// }
#include <stdio.h>
#include<iostream>
#define PT 5.5

#define S(x) PT *x *x

int main()

{

    int a = 1, b = 2;
    // std::cout << S(a + b);
    std::cout << S(1 + 2) << std::endl;
    std::cout << S(3) << std::endl;
    std::cout << std::endl;
    std::cout << PT * a + b * a + b << std::endl;
    printf("%4.1f\n", S(1+2));
    printf("%4.1f\n", S(3));
    std::cout << std::max(2, 1)*10 << std::endl;
    return 0;
}