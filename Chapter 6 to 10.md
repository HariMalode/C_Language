#  Q1. Explain
1. Pointers in C
2. Example Application
3. Pointer to Pointer
4. Example using all above , show value using pointer
5. Types of Function calls ( by Value and by Reference)


### 1. Pointers in C
**Pointers** are variables that store the memory address of another variable. They are a powerful feature in C that allows for efficient manipulation of arrays, dynamic memory allocation, and other advanced programming techniques.

**Syntax:**
```c
datatype *pointer_name;
```

**Example:**
```c
int *p; // p is a pointer to an integer
```

### 2. Example Application
Pointers can be used in various applications such as dynamic memory allocation, passing arguments to functions by reference, and working with arrays and strings.

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    p = (int*) malloc(sizeof(int)); // Dynamically allocate memory for an integer
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *p = 10; // Assign value to the allocated memory
    printf("Value at allocated memory: %d\n", *p);
    free(p); // Free the allocated memory
    return 0;
}
```

### 3. Pointer to Pointer
A **pointer to pointer** is a pointer that stores the address of another pointer. This can be useful for dynamic memory allocation and for passing a pointer to a function, allowing the function to modify the original pointer.

**Syntax:**
```c
datatype **pointer_to_pointer_name;
```

**Example:**
```c
int **pp; // pp is a pointer to a pointer to an integer
```

### 4. Example Using All Above, Show Value Using Pointer
Here, we'll combine pointers, pointer to pointer, and pass by reference to manipulate values and demonstrate the concept.

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

// Function prototype
void modifyValue(int *p);
void modifyPointer(int **pp);

int main() {
    int a = 10;
    int *p = &a;
    int **pp = &p;

    printf("Initial value of a: %d\n", a);
    printf("Initial value using pointer p: %d\n", *p);
    printf("Initial value using pointer to pointer pp: %d\n\n", **pp);

    // Modify value using pointer
    modifyValue(p);
    printf("Value of a after modifyValue: %d\n", a);
    printf("Value using pointer p after modifyValue: %d\n", *p);
    printf("Value using pointer to pointer pp after modifyValue: %d\n\n", **pp);

    // Modify pointer itself
    modifyPointer(pp);
    printf("Value of a after modifyPointer: %d\n", a);
    printf("Value using pointer p after modifyPointer: %d\n", *p);
    printf("Value using pointer to pointer pp after modifyPointer: %d\n", **pp);

    return 0;
}

void modifyValue(int *p) {
    *p = 20; // Change the value at the memory location pointed by p
}

void modifyPointer(int **pp) {
    *pp = (int*) malloc(sizeof(int)); // Allocate new memory
    if (*pp != NULL) {
        **pp = 30; // Set new value at the new memory location
    }
}
```

### 5. Types of Function Calls (by Value and by Reference)
Functions in C can be called by value or by reference.

#### Pass by Value
In pass by value, a copy of the actual parameter's value is passed to the function. Changes made to the parameter inside the function do not affect the original argument.

**Example:**
```c
#include <stdio.h>

void increment(int a);

int main() {
    int x = 5;
    increment(x);
    printf("Value of x after increment (by value): %d\n", x); // x remains 5
    return 0;
}

void increment(int a) {
    a = a + 1; // This change will not affect x in main
}
```

#### Pass by Reference
In pass by reference, the address of the actual parameter is passed to the function. Changes made to the parameter inside the function affect the original argument.

**Example:**
```c
#include <stdio.h>

void increment(int *a);

int main() {
    int x = 5;
    increment(&x);
    printf("Value of x after increment (by reference): %d\n", x); // x is now 6
    return 0;
}

void increment(int *a) {
    *a = *a + 1; // This change will affect x in main
}
```

By understanding and using pointers, pointer to pointer, and function calls by value and by reference, you can write efficient and powerful C programs.


----

# Q2. Explain
1.  Arrays in C
2. Methods of accessing elements in array
3. Array in Memory (Explain according to size of datatype)
4. Pointer Arithmetic 
5. Accessing array using pointer
6. Passing Arrays to function (all methods such as (int *i) , (int i[])
7. Multidimensional Array and methods to access
8. 2D array in memory
9. Example of 2D array 



### 1. Arrays in C
An **array** in C is a collection of elements of the same type, stored in contiguous memory locations. Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.

**Syntax:**
```c
datatype array_name[size];
```

**Example:**
```c
int numbers[5]; // Array of 5 integers
```

### 2. Methods of Accessing Elements in Array
Elements in an array can be accessed using the array name followed by the index of the element in square brackets. Array indices start from 0.

**Example:**
```c
#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printf("First element: %d\n", numbers[0]); // Accessing the first element
    printf("Third element: %d\n", numbers[2]); // Accessing the third element
    return 0;
}
```

### 3. Array in Memory
Arrays are stored in contiguous memory locations. The size of each element depends on the datatype of the array. For example, an `int` array with 5 elements on a system where an `int` is 4 bytes will require `5 * 4 = 20` bytes of contiguous memory.

**Example:**
```c
int numbers[5]; // Each int typically takes 4 bytes, so 5 ints take 20 bytes
```

### 4. Pointer Arithmetic
Pointer arithmetic allows us to navigate through array elements using pointers. When a pointer is incremented, it points to the next element of its type.

**Example:**
```c
#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int *p = numbers;
    
    printf("First element: %d\n", *p); // Accessing the first element
    p++; // Increment the pointer to point to the next element
    printf("Second element: %d\n", *p); // Accessing the second element
    
    return 0;
}
```

int i=32
int *a=&i   //a=8784
a++         // a= 8788


### 5. Accessing Array Using Pointer
Arrays can be accessed using pointers by incrementing the pointer to traverse through the array elements.

**Example:**
```c
#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int *p = numbers; // OR *p = &numbers[0]
    
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(p + i)); // Accessing elements using pointer arithmetic
    }
    
    return 0;
}
```

### 6. Passing Arrays to Function
Arrays can be passed to functions by passing the array name (which acts as a pointer) or explicitly passing a pointer to the array.

**Example 1: Using array name:**
```c
#include <stdio.h>

void printArray(int arr[], int size);

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printArray(numbers, 5);
    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, arr[i]);
    }
}
```

**Example 2: Using pointer:**
```c
#include <stdio.h>

void printArray(int *arr, int size);

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printArray(numbers, 5);
    return 0;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(arr + i));
    }
}
```

### 7. Multidimensional Array and Methods to Access
Multidimensional arrays are arrays of arrays. The most common type is the 2D array, which can be visualized as a table with rows and columns.

**Syntax:**
```c
datatype array_name[rows][columns];
```

**Accessing Elements:**
```c
#include <stdio.h>

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("Element at [0][0]: %d\n", matrix[0][0]);
    printf("Element at [1][2]: %d\n", matrix[1][2]);
    return 0;
}
```

### 8. 2D Array in Memory
A 2D array is stored in row-major order in memory, meaning that elements of each row are stored in contiguous memory locations.

**Example:**
```c
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
// Memory layout: 1, 2, 3, 4, 5, 6 (assuming int takes 4 bytes)
```

### 9. Example of 2D Array
Let's put it all together with an example demonstrating a 2D array and accessing its elements using pointers.

**Example:**
```c
#include <stdio.h>

void print2DArray(int arr[][3], int rows);

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // Print the 2D array using function
    print2DArray(matrix, 2);
    
    // Accessing using pointers
    int *p = &matrix[0][0];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element at [%d][%d]: %d\n", i, j, *(p + i*3 + j));
        }
    }
    
    return 0;
}

void print2DArray(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element at [%d][%d]: %d\n", i, j, arr[i][j]);
        }
    }
}
```

In this example, we have demonstrated the creation of a 2D array, accessing its elements directly and via pointers, and passing the 2D array to a function.

---

# Q3. Explain
1. Strings in C (also tell aboyt \0)
2. String Initialization methods ('h','a') ("ha")
3. Strings in memory
4. Accessing Strings (%c%s) with String Program 
5. gets() and puts() example
6.  Strings with Pointers (program taking input and display) Both methods using loop and non loop
7. Std Library Functions for stings


### 1. Strings in C (also tell about `\0`)
A **string** in C is a sequence of characters terminated by a null character `\0`. This null character is used to mark the end of the string. 

**Example:**
```c
char str[] = "Hello"; // This is stored as {'H', 'e', 'l', 'l', 'o', '\0'}
```

### 2. String Initialization Methods
Strings can be initialized in two main ways:

**Character Array:**
```c
char str1[] = {'h', 'a', '\0'}; // Explicitly adding the null terminator
```

**String Literal:**
```c
char str2[] = "ha"; // Implicitly adds the null terminator
```

### 3. Strings in Memory
In memory, strings are stored as arrays of characters with the last character being the null terminator (`\0`).

**Example:**
```c
char str[] = "Hello"; 
// Memory layout: {'H', 'e', 'l', 'l', 'o', '\0'}
```

### 4. Accessing Strings (`%c`, `%s`) with String Program
You can access individual characters in a string using the `%c` format specifier and the entire string using the `%s` format specifier.

**Example:**
```c
#include <stdio.h>

int main() {
    char str[] = "Hello";
    
    // Accessing individual characters
    printf("First character: %c\n", str[0]); // Output: H
    printf("Second character: %c\n", str[1]); // Output: e
    
    // Accessing the entire string
    printf("String: %s\n", str); // Output: Hello
    
    return 0;
}
```

### 5. `gets()` and `puts()` Example
The `gets()` function is used to read a string from the standard input (until a newline is encountered), and `puts()` is used to write a string to the standard output.

**Example:**
```c
#include <stdio.h>

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str); // Read string from user (Note: unsafe, use fgets in practice)
    
    printf("You entered: ");
    puts(str); // Output the string
    
    return 0;
}
```

### 6. Strings with Pointers (program taking input and display) Both Methods Using Loop and Non-loop
**Using Loop:**
```c
#include <stdio.h>

int main() {
    char str[100];
    char *p;
    
    printf("Enter a string: ");
    gets(str); // Read string from user (Note: unsafe, use fgets in practice)
    
    p = str; // Point to the beginning of the string
    
    printf("You entered: ");
    while (*p != '\0') {
        putchar(*p);
        p++;
    }
    printf("\n");
    
    return 0;
}
```

**Non-Loop:**
```c
#include <stdio.h>

int main() {
    char str[100];
    char *p;
    
    printf("Enter a string: ");
    gets(str); // Read string from user (Note: unsafe, use fgets in practice)
    
    p = str; // Point to the beginning of the string
    
    printf("You entered: %s\n", p); // Print the string directly
    
    return 0;
}
```

### 7. Standard Library Functions for Strings
C provides several standard library functions for string manipulation, declared in `<string.h>`.

**Common Functions:**

- `strlen(str)`: Returns the length of the string `str` (excluding the null character).
- `strcpy(dest, src)`: Copies the string `src` to `dest`.
- `strncpy(dest, src, n)`: Copies up to `n` characters from `src` to `dest`.
- `strcat(dest, src)`: Concatenates `src` to the end of `dest`.
- `strncat(dest, src, n)`: Concatenates up to `n` characters from `src` to `dest`.
- `strcmp(str1, str2)`: Compares `str1` and `str2` lexicographically.
- `strncmp(str1, str2, n)`: Compares up to `n` characters of `str1` and `str2`.
- `strchr(str, c)`: Returns a pointer to the first occurrence of character `c` in `str`.
- `strstr(haystack, needle)`: Returns a pointer to the first occurrence of `needle` in `haystack`.

**Example Using Standard Library Functions:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    
    // strlen
    printf("Length of str1: %zu\n", strlen(str1));
    
    // strcpy
    strcpy(str3, str1);
    printf("str3 after strcpy: %s\n", str3);
    
    // strcat
    strcat(str1, str2);
    printf("str1 after strcat: %s\n", str1);
    
    // strcmp
    int result = strcmp(str1, str2);
    if (result == 0) {
        printf("str1 and str2 are equal\n");
    } else if (result < 0) {
        printf("str1 is less than str2\n");
    } else {
        printf("str1 is greater than str2\n");
    }
    
    return 0;
}
```

These examples demonstrate the basics of working with strings in C, including initialization, memory representation, accessing elements, using standard I/O functions, and manipulating strings with pointers and standard library functions.

---

# Q4(A). Write a program to count the occurrence of given character in a string?
 Below is a C program that takes a string and a character as input from the user and counts the occurrence of the given character in the string using a function.

```c
#include <stdio.h>

// Function prototype
int countCharacterOccurrence(char *str, char ch);

int main() {
    char str[100], ch;
    int count;
    
    // Take string input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Use fgets for safe input
    
    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    
    // Take character input from the user
    printf("Enter a character to count: ");
    scanf("%c", &ch);
    
    // Count the occurrence of the given character
    count = countCharacterOccurrence(str, ch);
    
    // Display the result
    printf("The character '%c' appears %d time(s) in the string.\n", ch, count);
    
    return 0;
}

// Function to count the occurrence of a given character in a string
int countCharacterOccurrence(char *str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}
```

### Explanation:
1. **Function `countCharacterOccurrence`:** 
   - This function takes a string pointer (`char *str`) and a character (`char ch`) as inputs.
   - It iterates through the string using a while loop until the null character (`'\0'`) is encountered.
   - For each character in the string, it checks if it matches the given character (`ch`). If it does, it increments the `count`.
   - The function returns the total count of occurrences of the given character.

2. **Main Function:**
   - The program first takes a string input from the user using `fgets()`. This ensures safe input handling, including strings with spaces.
   - The newline character added by `fgets()` at the end of the input is removed.
   - Then, it takes a single character input from the user using `scanf("%c", &ch)`.
   - The `countCharacterOccurrence` function is called with the string and the character as arguments.
   - Finally, the program prints the number of times the given character appears in the string.

### Notes:
- Using `fgets` for string input helps avoid buffer overflow issues that can occur with `gets`.
- The program handles spaces and special characters in the string.
- The program ensures to remove the newline character added by `fgets` to accurately count the character occurrences.


# Q4(B). Write a program to encrypt a string by adding 1 to ASCII  value to its character.

Below is a C program that takes a string input from the user and encrypts it by adding 1 to the ASCII value of each character in the string. The encryption is done using a function.

```c
#include <stdio.h>

// Function prototype
void encryptString(char *str);

int main() {
    char str[100];
    
    // Take string input from the user
    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin); // Use fgets for safe input
    
    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    
    // Encrypt the string
    encryptString(str);
    
    // Display the encrypted string
    printf("Encrypted string: %s\n", str);
    
    return 0;
}

// Function to encrypt the string by adding 1 to the ASCII value of each character
void encryptString(char *str) {
    while (*str != '\0') {
        *str = *str + 1; // Increment ASCII value of each character by 1
        str++;
    }
}
```

### Explanation:
1. **Function `encryptString`:** 
   - This function takes a string pointer (`char *str`) as input.
   - It iterates through the string using a while loop until the null character (`'\0'`) is encountered.
   - For each character in the string, it increments its ASCII value by 1 (`*str = *str + 1`).
   - The function modifies the original string in place.

2. **Main Function:**
   - The program first takes a string input from the user using `fgets()`. This ensures safe input handling, including strings with spaces.
   - The newline character added by `fgets()` at the end of the input is removed.
   - The `encryptString` function is called with the string as an argument.
   - Finally, the program prints the encrypted string.

### Notes:
- Using `fgets` for string input helps avoid buffer overflow issues that can occur with `gets`.
- The program handles spaces and special characters in the string.
- The program ensures to remove the newline character added by `fgets` to correctly encrypt the string without an additional newline character.

---


# Q5. Explain
1. Structures in C and its use
2. Program to store details of 3 employee using structures
3. Array of Structures with example
4. Structure in Memory
5. Pointer to structures, explain both arrow operator and normal way to write structure[(*ptr).name   and ptr-> name) with proper example
6. Passing structure to a function
7. typedef Keyword

Sure, let's go through each topic related to structures in C.

### 1. Structures in C and Its Use
A **structure** in C is a user-defined data type that allows grouping variables of different data types under a single name. Structures are useful for creating complex data types that represent real-world entities, such as records or objects.

**Syntax:**
```c
struct structure_name {
    data_type member1;
    data_type member2;
    ...
};
```

**Example:**
```c
struct Employee {
    int id;
    char name[50];
    float salary;
};
```

### 2. Program to Store Details of 3 Employees Using Structures

```c
#include <stdio.h>

// Define the structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[3]; // Array of 3 employees

    // Input details for 3 employees
    for (int i = 0; i < 3; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Display employee details
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    return 0;
}
```

### 3. Array of Structures with Example

An array of structures allows us to store multiple records of the same structure type.

**Example:**
```c
#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp[3] = {
        {1, "Alice", 50000},
        {2, "Bob", 60000},
        {3, "Charlie", 70000}
    };

    for (int i = 0; i < 3; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    return 0;
}
```

### 4. Structure in Memory

Structures in memory are stored as contiguous blocks of memory, with each member occupying space according to its data type.

**Example:**
For `struct Employee`, assuming `int` is 4 bytes, `char[50]` is 50 bytes, and `float` is 4 bytes, an `Employee` structure would occupy 58 bytes in memory.

### 5. Pointer to Structures

Pointers to structures allow for efficient access and manipulation of structure data.

**Normal Way:**
```c
#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp = {1, "Alice", 50000};
    struct Employee *ptr = &emp;

    // Accessing using normal way
    printf("ID: %d\n", (*ptr).id);
    printf("Name: %s\n", (*ptr).name);
    printf("Salary: %.2f\n", (*ptr).salary);

    return 0;
}
```

**Arrow Operator:**
```c
#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp = {1, "Alice", 50000};
    struct Employee *ptr = &emp;

    // Accessing using arrow operator
    printf("ID: %d\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Salary: %.2f\n", ptr->salary);

    return 0;
}
```

### 6. Passing Structure to a Function

Structures can be passed to functions by value or by reference (using pointers).

**By Value:**
```c
#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void display(struct Employee emp) {
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);
}

int main() {
    struct Employee emp = {1, "Alice", 50000};
    display(emp);

    return 0;
}
```

**By Reference:**
```c
#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void display(struct Employee *emp) {
    printf("ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Salary: %.2f\n", emp->salary);
}

int main() {
    struct Employee emp = {1, "Alice", 50000};
    display(&emp);

    return 0;
}
```

### 7. `typedef` Keyword

The `typedef` keyword in C allows you to create an alias for existing data types, making code more readable and easier to maintain.

**Example:**
```c
#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    Employee emp = {1, "Alice", 50000};

    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}
```

In this example, `typedef` is used to create an alias `Employee` for the structure type, so you can declare variables of this type without using the `struct` keyword.

---


# Q6. Explain 
1. File I/O in C
2. File Pointer
3. Types of files
4. File opening modes
5. Program - Reading a file and print
6. Program - Creating a file and insert content from user
7. fgetc() and fputc()


Sure! Let's go through each topic related to file I/O in C.

### 1. File I/O in C
File I/O (Input/Output) in C allows programs to read from and write to files stored on the disk. This is essential for data persistence, logging, configuration management, and more.

### 2. File Pointer
A **file pointer** is a pointer of type `FILE` that points to a structure containing information about the file being accessed. The `FILE` structure is defined in the `stdio.h` header file. You must use a file pointer to perform file operations such as reading, writing, and closing a file.

**Example:**
```c
FILE *fp;
```

### 3. Types of Files
There are two main types of files:
1. **Text Files:** Store data in human-readable format. Each line ends with a newline character (`\n`).
2. **Binary Files:** Store data in binary format, which is not human-readable. These files are more efficient in terms of storage and access.

### 4. File Opening Modes
The `fopen` function is used to open a file in various modes. Some common modes are:
- `"r"`: Open a file for reading.
- `"w"`: Create an empty file for writing. If the file exists, its content is erased.
- `"a"`: Append to a file. If the file does not exist, it is created.
- `"r+"`: Open a file for both reading and writing.
- `"w+"`: Create an empty file for both reading and writing. If the file exists, its content is erased.
- `"a+"`: Open a file for reading and appending. If the file does not exist, it is created.

### 5. Program - Reading a File and Printing its Contents
```c
#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // Open file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read and print file contents character by character
    while ((ch = fgetc(fp)) != EOF) {  //EOF - End of file
        putchar(ch);
    }

    // Close the file
    fclose(fp);
    
    return 0;
}
```

### 6. Program - Creating a File and Inserting Content from User
```c
#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // Open file for writing
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter content to write to the file (Press Ctrl+D to end input):\n");
    while ((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }

    // Close the file
    fclose(fp);
    
    return 0;
}
```

### 7. `fgetc()` and `fputc()`
- `fgetc(FILE *stream)`: Reads a single character from the file pointed to by `stream`. It returns the character read as an `unsigned char` cast to an `int` or `EOF` on end of file or error.
- `fputc(int char, FILE *stream)`: Writes the character specified by `char` (converted to an `unsigned char`) to the file pointed to by `stream`. It returns the character written or `EOF` on error.

**Example of `fgetc()` and `fputc()`:**
```c
#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    // Open file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("File contents:\n");
    // Read and print file contents character by character
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    // Open file for writing
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nEnter a character to append to the file: ");
    ch = getchar();
    fputc(ch, fp);
    fclose(fp);

    printf("Character appended to file successfully.\n");

    return 0;
}
```

This code first reads and prints the contents of a file using `fgetc()`. Then, it appends a character entered by the user to the file using `fputc()`.

### 8. Write a program using fscan and fprint

Certainly! The `fscanf` and `fprintf` functions in C are used for reading from and writing to files, respectively. They work similarly to `scanf` and `printf`, but with an additional parameter for the file pointer.

### Program to Read from a File Using `fscanf` and Write to a File Using `fprintf`

Below is a program that reads data from one file using `fscanf` and writes it to another file using `fprintf`.

**Example:**

1. Create an input file `input.txt` with the following content:
```
John 25 75000
Jane 30 80000
Doe 22 68000
```

2. Program to read from `input.txt` and write to `output.txt`:

```c
#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char name[50];
    int age;
    float salary;

    // Open the input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read data from input file and write to output file
    while (fscanf(inputFile, "%s %d %f", name, &age, &salary) != EOF) {
        fprintf(outputFile, "Name: %s, Age: %d, Salary: %.2f\n", name, age, salary);
    }

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    printf("Data successfully copied from input.txt to output.txt\n");
    
    return 0;
}
```

### Explanation:
1. **Opening Files:**
   - The input file `input.txt` is opened for reading using `fopen("input.txt", "r")`.
   - The output file `output.txt` is opened for writing using `fopen("output.txt", "w")`.

2. **Reading and Writing Data:**
   - `fscanf(inputFile, "%s %d %f", name, &age, &salary)` reads a string, an integer, and a float from the input file.
   - `fprintf(outputFile, "Name: %s, Age: %d, Salary: %.2f\n", name, age, salary)` writes the read data to the output file in a formatted manner.
   - The loop continues until the end of the file is reached (`EOF`).

3. **Closing Files:**
   - Both files are closed using `fclose()` to free the resources.

### Sample Output in `output.txt`:
```
Name: John, Age: 25, Salary: 75000.00
Name: Jane, Age: 30, Salary: 80000.00
Name: Doe, Age: 22, Salary: 68000.00
```

This program demonstrates the use of `fscanf` to read formatted data from a file and `fprintf` to write formatted data to another file.


