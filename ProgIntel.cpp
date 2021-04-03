#include <iostream>
#include <ctime>
using namespace std;
int main()
{
 srand(time(0));
 int n = rand() % 9 + 2;
 //int n = 4;
 //long long n = 100;
 int array[n][n];
 int tmpArray[n][n];
 int i,j;
 cout<<"\tArray"<<endl;
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < n; j++)
 {
 array[i][j] = rand() % 9 + 1;
 tmpArray[i][j] = 0;
 cout<<array[i][j]<<" ";
 }
 cout<<endl;
 }
 if (n<=1)
 {
 cout<< "Bad array size!"<<endl;
 return -1;
 }
 i=-1;
 j=0;
 asm volatile(
 ".intel_syntax noprefix\n\t"
 "xor eax, eax\n\t" // Поместили 8 в rax
 "outer:" // Умножили rax на n (получили сдвиг для
 "mov ecx, %3\n\t"//i
 "inc ecx\n\t" // i+1
 "mov %3, ecx\n\t" // i
 "mov ecx, 0\n\t" // -
 "mov %4, ecx\n\t" // j=0
 "mov ecx, %3\n\t" // i
 "cmp ecx, %2\n\t" // if i==n
 "je _close\n\t" // stop
 "jne inner\n\t" // inner iter
 "inner:\n\t"
 "mov ecx, %4\n\t" // j
 "cmp ecx, %2\n\t" // if j==n
 "je outer\n\t" // outer iter
 "jne contin\n\t"
 "contin:\n\t" 
 "mov ecx, %3\n\t"
 "imul ecx, %2\n\t"
 "imul ecx, 4\n\t"
 "mov ebx, ecx\n\t"
 "mov ecx, %4\n\t"
 "imul ecx, 4\n\t"
 "add ebx, ecx\n\t"
 "mov eax, %1[ebx]\n\t"
 "mov ecx, %4\n\t"
 "imul ecx, %2\n\t"
 "imul ecx, 4\n\t"
 "mov ebx, ecx\n\t"
 "mov ecx, %2\n\t"
 "dec ecx\n\t"
 "sub ecx, %3\n\t"
 "imul ecx, 4\n\t"
 "add ebx, ecx\n\t"
 "mov %0[ebx], eax\n\t"
 "mov eax, %4\n\t"
 "inc eax\n\t" 
 "mov %4, eax\n\t" 
 "jmp inner\n\t"
 "_close:\n\t"
 :"=m"(tmpArray)
 :"m"(array), 
 "m"(n), 
 "m"(i), 
 "m"(j)
 :"eax", "ebx", "ecx"
 );
 cout<<endl<<"--------------------------------"<<endl;
 cout<<"\tArray(T)"<<endl;
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < n; j++)
 {
 cout<<tmpArray[i][j]<<" ";
 }
 cout<<endl;
 }
 return 0;
}
