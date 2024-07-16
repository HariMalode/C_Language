# Q1. Explain
1. Dyanamic memory allocation in  C
2. Function in DMA : 1) malloc 2) calloc 3) free 4) realloc

### 1. Dynamic Memory Allocation in C

Dynamic memory allocation in C allows you to allocate memory during runtime, which is useful when the size of the data structure (such as an array or linked list) is not known at compile time. This is done using functions provided in the `stdlib.h` library. The main functions for dynamic memory allocation are `malloc`, `calloc`, `realloc`, and `free`.

### 2. Functions in Dynamic Memory Allocation (DMA)

#### 2.1 `malloc`
The `malloc` (memory allocation) function allocates a block of memory of a specified size and returns a pointer to the beginning of the block. The memory is not initialized and contains garbage values.

**Syntax:**
```c
void* malloc(size_t size);
```

**Example:**
```c
int *ptr = (int*) malloc(5 * sizeof(int)); // Allocates memory for an array of 5 integers
if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}
```

#### 2.2 `calloc`
The `calloc` (contiguous allocation) function allocates memory for an array of elements, initializes the memory to zero, and returns a pointer to the allocated memory.

**Syntax:**
```c
void* calloc(size_t num, size_t size);
```

**Example:**
```c
int *ptr = (int*) calloc(5, sizeof(int)); // Allocates memory for an array of 5 integers and initializes to zero
if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}
```

#### 2.3 `free`
The `free` function deallocates previously allocated memory, making it available for future allocations. It takes a pointer to the allocated memory as an argument.

**Syntax:**
```c
void free(void* ptr);
```

**Example:**
```c
free(ptr); // Deallocates the memory previously allocated to ptr
ptr = NULL; // To avoid dangling pointer
```

#### 2.4 `realloc`
The `realloc` (reallocation) function changes the size of a previously allocated memory block. If the new size is larger, the contents are unchanged up to the minimum of the old and new sizes. If the new size is smaller, the contents are truncated.

**Syntax:**
```c
void* realloc(void* ptr, size_t size);
```

**Example:**
```c
int *ptr = (int*) malloc(5 * sizeof(int)); // Allocates memory for an array of 5 integers
if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}

ptr = (int*) realloc(ptr, 10 * sizeof(int)); // Reallocates memory to expand the array to 10 integers
if (ptr == NULL) {
    printf("Memory reallocation failed\n");
    return 1;
}
```

### Example Program Demonstrating DMA Functions

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *ptr;

    // Dynamic memory allocation using malloc
    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory successfully allocated using malloc\n");
    for (i = 0; i < n; ++i) {
        ptr[i] = i + 1;
    }

    printf("The elements of the array are: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Dynamic memory allocation using calloc
    ptr = (int*) calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory successfully allocated using calloc\n");
    for (i = 0; i < n; ++i) {
        ptr[i] = i + 1;
    }

    printf("The elements of the array are: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Reallocating the memory
    ptr = (int*) realloc(ptr, (n * 2) * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    printf("Memory successfully reallocated using realloc\n");
    for (i = n; i < n * 2; ++i) {
        ptr[i] = i + 1;
    }

    printf("The elements of the array are: ");
    for (i = 0; i < n * 2; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Freeing the allocated memory
    free(ptr);
    printf("Memory successfully freed\n");

    return 0;
}
```

### Explanation:
1. **`malloc`:** Allocates memory for `n` integers.
2. **`calloc`:** Allocates and initializes memory for `n` integers.
3. **`realloc`:** Reallocates memory to expand the array to hold `2n` integers.
4. **`free`:** Deallocates the memory previously allocated to `ptr`.

By using these functions, you can efficiently manage memory during the runtime of your program.

# Q2. Write Snake, Water, Gun game in C

Sure! Below is a simple implementation of the Snake, Water, Gun game in C. The game will allow the user to play against the computer, which will randomly choose between Snake, Water, and Gun.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateComputerChoice();
int determineWinner(int userChoice, int computerChoice);
void displayChoice(int choice);

int main() {
    int userChoice, computerChoice, result;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    do {
        // Display choices to the user
        printf("Choose an option:\n");
        printf("1. Snake\n");
        printf("2. Water\n");
        printf("3. Gun\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        // Generate computer's choice
        computerChoice = generateComputerChoice();

        // Display choices
        printf("You chose: ");
        displayChoice(userChoice);
        printf("Computer chose: ");
        displayChoice(computerChoice);

        // Determine the winner
        result = determineWinner(userChoice, computerChoice);

        // Display the result
        if (result == 0) {
            printf("It's a draw!\n");
        } else if (result == 1) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }

        // Ask if the user wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

// Function to generate computer's choice
int generateComputerChoice() {
    return rand() % 3 + 1; // Returns a random number between 1 and 3
}

// Function to determine the winner
int determineWinner(int userChoice, int computerChoice) {
    // Return 0 for draw, 1 for user win, -1 for computer win
    if (userChoice == computerChoice) {
        return 0;
    } else if ((userChoice == 1 && computerChoice == 2) ||
               (userChoice == 2 && computerChoice == 3) ||
               (userChoice == 3 && computerChoice == 1)) {
        return 1;
    } else {
        return -1;
    }
}

// Function to display the choice
void displayChoice(int choice) {
    switch (choice) {
        case 1:
            printf("Snake\n");
            break;
        case 2:
            printf("Water\n");
            break;
        case 3:
            printf("Gun\n");
            break;
        default:
            printf("Invalid choice\n");
    }
}
```

### Explanation:
1. **Choice Representation:**
   - `1` represents Snake.
   - `2` represents Water.
   - `3` represents Gun.

2. **Function `generateComputerChoice`:**
   - Generates a random number between 1 and 3, representing the computer's choice.

3. **Function `determineWinner`:**
   - Determines the winner based on the game's rules:
     - Snake (1) drinks Water (2), Snake wins.
     - Water (2) douses Gun (3), Water wins.
     - Gun (3) shoots Snake (1), Gun wins.
   - Returns `0` for a draw, `1` for a user win, and `-1` for a computer win.

4. **Function `displayChoice`:**
   - Displays the chosen option (Snake, Water, or Gun) based on the input integer.

5. **Main Function:**
   - The main loop allows the user to play multiple rounds of the game.
   - It reads the user's choice, generates the computer's choice, displays both choices, determines the winner, and displays the result.
   - It asks the user if they want to play again after each round.