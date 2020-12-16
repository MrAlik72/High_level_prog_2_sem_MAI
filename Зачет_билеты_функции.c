#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
// 1. strcpy function analog
char* my_strcpy(const char* from, char* to) {
if (from == NULL || to == NULL)
return NULL; // invalid params
int i;
for(i = 0; from[i] != 0; i++)
to[i] = from[i];
to[i] = 0; // null-terminator
return to; // success
}
// 2. strcmp function analog
int my_strcmp(const char* str1, char* str2) {
// params checking
assert(str1 != NULL);
assert(str2 != NULL);
int i = 0;
while (1) {
if (str1[i] == 0 && str2[i] == 0)
return 0; // equal strings
else {
if (str1[i] == 0)
return -1;
else if (str2[i] == 0)
return 1;
else {
if (str1[i] > str2[i])
return 1;
else if (str1[i] < str2[i])
return -1;
}
}
i++;
}
}
// 3. strlen function analog
size_t my_strlen(const char* str) {
assert(str != NULL);
int i;
for (i = 0; str[i] != 0; i++) {
// count i while we not find null-terminator}
return i;
}
// 4. strcat function analog
char* my_strcat(const char* from, char* to) {
if (from == NULL || to == NULL)
return NULL;
int i;
for (i = 0; to[i] != 0; i++) {
// count i while we not find null-terminator
}
int j;
for (j = 0; from[j] != 0; j++) {
to[i + j] = from[j];
}
to[i + j] = 0;
return to;
}
// 5. strchr function analog
const char* my_strchr(const char* str, int symbol) {
assert(str != NULL);
int i;
for (i = 0; str[i] != 0; i++) {
if (str[i] == symbol)
return &(str[i]);
}
return NULL;
}
// 6. print number
#define MAX_INT_DIGIT_COUNT 10
void print_number(int num) {
if (num < 0) {
putchar('-');
num = -num;
} c
har digits_reversed[MAX_INT_DIGIT_COUNT] = { 0 };
int last = 0;
int i;
for (i = 0; i < MAX_INT_DIGIT_COUNT && num != 0; i++) {
last = num % 10;
digits_reversed[i] = last + '0';
num = num / 10;}
while (i >= 0) {
putchar(digits_reversed[i]);
i--;
}
}
// 7. print number (binary)
void print_number_bin(int num) {
for (int i = 8 * sizeof(num) - 1; i >= 0; i--) {
if (num & 1 << i)
putchar('1');
else
putchar('0');
}
}
// 8. arithmetic mean of numbers bigger than N from the array
float arithmetic_mean(size_t in_size, int arr[in_size], int bigger_than)
{
int sum = 0;
int out_size = 0;
for (int i = 0; i < in_size; i++) {
if (arr[i] > bigger_than) {
sum += arr[i];
out_size++;
}
}
return sum/out_size;
}
// 9. arithmetic mean of even numbers from the array
int even_arithmetic_mean(size_t in_size, int arr[in_size]) {
int sum = 0;
int out_size = 0;
for (int i = 0; i < in_size; i++) {
if (arr[i] % 2 == 0) {
sum += arr[i];
out_size++;
}
}
return sum/out_size;
}
// 10. maximum '1' in a row
int max_1s(size_t in_size, int arr[in_size]) {
int max_size = 0;
int flag = 0;int counter = 0;
for (int i = 0; i < in_size; i++) {
if (arr[i] == 1) {
if (flag == 0)
counter = 0;
flag = 1;
counter++;
if (counter > max_size)
max_size = counter;
}
else
flag = 0;
}
return max_size;
}
// 11. extract the number from the string
int str2num(const char* str) {
assert(str != NULL);
unsigned char number_digits[MAX_INT_DIGIT_COUNT];
int flag = 0;
int counter = 0;
int is_negative = 0;
for (int i = 0; str[i] != 0; i++) {
if (str[i] == '-') {
is_negative = 1;
flag = 1;
counter = 0;
}
else if (str[i] >= '0' && str[i] <= '9') { // ASCII digit
if (flag == 0)
counter = 0;
number_digits[counter] = str[i] - '0';
flag = 1;
counter++;
}
else if (flag == 1)
break; // end of number
}
int number = 0;
for (int i = 0; i < counter; i++)
number += number_digits[i] * pow(10.0, counter - i - 1);
if (is_negative)number = -number;
return number;
}
// 12. delete numbers less than N from the array
int del_less_than(size_t in_size, int arr[in_size], int less_than) {
int new_size = 0;
for (int i = 0; i < in_size - 1; i++) {
for (int j = i + 1; j < in_size; j++) {
if (arr[i] < less_than) { // swap numbers
int old = arr[i];
arr[i] = arr[j];
arr[j] = old;
}
}
if (arr[i] >= less_than)
new_size++;
}
return new_size;
}
// 13. combine two sorted arrays
int combine(size_t size_1, int arr_1[size_1], size_t size_2, int
arr_2[size_2], int* dest) {
// size_1 >= size_2
// arr_1: { 1, 2, 4, 5, 7 }
// arr_2: { 3, 7, 8, 10 }
// 1 -> 2 -> 3 -> 4 -> 5 -> 7 -> 8 -> 10
int counter = 0;
int i = 0;
int j = 0;
while (i < size_1 && j < size_2) {
if (arr_1[i] < arr_2[j]) {
dest[counter] = arr_1[i];
i++;
}
else if (arr_1[i] > arr_2[j]) {
dest[counter] = arr_2[j];
j++;
}
else { // equals
dest[counter] = arr_1[i];
i++;
j++;
} c
ounter++;
}while (i < size_1) {
dest[counter] = arr_1[i];
counter++;
i++;
}
while (j < size_2) {
dest[counter] = arr_2[j];
counter++;
j++;
}
return counter;
}
// 14. arithmetic mean of even numbers on non-even indexes from the array
int even_arithmetic_mean_noneven_index(size_t in_size, int arr[in_size])
{
int sum = 0;
int out_size = 0;
for (int i = 0; i < in_size; i++) {
if (i % 2 == 1 && arr[i] % 2 == 0) {
sum += arr[i];
out_size++;
}
}
return sum/out_size;
}
// 15. count of N equal digits in the number
int find_equal_digits(int num, size_t equal_digits) {
if (num < 0)
num = -num;
int digits[10] = { 0 };
for (int i = 0; i < 10 && num != 0; i++) {
digits[num % 10]++;
num = num / 10;
}
for (int i = 0; i < 10; i++) {
if (digits[i] >= equal_digits)
return 1;
}
return 0;
}
// 17. get N bit
bool get_bit(uint8_t num, int bit_num) {
return num & (1 << bit_num);}
// 18. set N bit
void set_bit(uint8_t* num, int bit_num, bool value) {
assert(num != NULL);
short padding = 1 << bit_num;
if (value)
*num |= padding;
else
*num &= ~padding;
}
// 19. polyndrome
bool is_polyndrome(const char* str) {
assert(str != NULL);
int flag = 0;
int start_index = 0;
int counter = 0;
for (int i = 0; str[i] != 0; i++) {
if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <=
'Z')) {
if (flag == 0) {
start_index = i;
counter = 0;
}
flag = 1;
counter++;
}
else if (flag == 1)
break; // end of word
}
for (int i = start_index; i < start_index + counter; i++) {
if (str[i] != str[start_index + counter - i])
return 0;
}
return 1;
}
// 20. summa
int summa() {
int summa = 0;
for (int i = 20; i < 100; i++) {
if (i % 3 == 0)
summa += i;
}
return summa;
}int main() {
int result;
bool result_b;
float result_f;
char* result_s;
char buffer1[255];
const char* test_string = "some string from my fantasy. 123:!-_'-46-
'46:'__-;'_6436678-4$ 906";
result_s = my_strcpy(test_string, &buffer1);
if (result_s == NULL)
printf("my_strcpy: failed\n");
else
printf("my_strcpy: copied string: %s\n", result_s);
result = my_strcmp("gg 1245", "mai 228");
if (result > 0)
printf("my_strcmp: str1 longer than str2\n");
else if (result < 0)
printf("my_strcmp: str1 shorter than str2\n");
else
printf("my_strcmp: strings equals\n");
result = my_strlen("some string");
printf("my_strlen: string length is %d\n", result);
char buffer2[60] = "old string ";
result_s = my_strcat("added string", &buffer2);
if(result == NULL)
printf("my_strcat: failed\n");
else
printf("my_strcat: concatenated string: %s\n", result_s);
result_s = my_strchr("Vestyak one love", 'o');
if(result == NULL)
printf("my_strchr: symbol was not found\n");
else
printf("my_strchr: found: %s\n", result_s);
printf("print_number: ");
print_number(-2146743961);
printf("\n");
printf("print_number (binary): ");
print_number_bin(-2146743961);
printf("\n");
int arr_1[10] = { 2, 5, -3, 7, 10, 12, 8, 10, 0, 1};
result_f = arithmetic_mean(10, arr_1, 3);
printf("arithmetic_mean: %f\n", result_f);
result = even_arithmetic_mean(10, arr_1);printf("even_arithmetic_mean: %d\n", result);
result = even_arithmetic_mean_noneven_index(10, arr_1);
printf("even_arithmetic_mean_noneven_index: %d\n", result);
int arr_2[10] = { 0, 1, 0, 1, 1, 1, 0, 1, 1, 0 };
result = max_1s(10, arr_2);
printf("max_1s: %d\n", result);
char* str_2 = "max matan peresdacha count: 34";
result = str2num(str_2);
printf("str2num: %d\n", result);
int arr_3[50] = { 0 };
for (int i = 0; i < 50; i++)
arr_3[i] = i; // filling the input buffer by 0, 1, 2, ..., 49
result = del_less_than(50, arr_3, 15);
printf("del_less_than: processed array (size %d): [", result);
for (int i = 0; i < result; i++) {
if(i == 0)
printf("%d", arr_3[i]);
else
printf(", %d", arr_3[i]);
}
printf("]\n");
int arr_4_1[5] = { 1, 2, 4, 5, 7 };
int arr_4_2[4] = { 3, 7, 8, 10 };
int arr_4_dest[9] = { 0 };
result = combine(5, arr_4_1, 4, arr_4_2, arr_4_dest);
printf("combine: array of %d size: [", result);
for (int i = 0; i < result; i++) {
if(i == 0)
printf("%d", arr_4_dest[i]);
else
printf(", %d", arr_4_dest[i]);
}
printf("]\n");
int counter = 0;
for (int i = 111; i < 1000; i++) {
if (find_equal_digits(i, 2))
counter++;
}
printf("find_equal_digits(111-999): %d\n", counter);
result_b = get_bit(114, 6);
printf("get_bit: %hhu\n", result_b);
uint8_t num = 114;set_bit(&num, 6, false);
printf("set_bit: num after setting is %hhu\n", num);
result_b = is_polyndrome(" radar ");
printf("is_polyndrome: %hhu\n", result_b);
result = summa();
printf("summa: %d\n", result);
return 0;
}