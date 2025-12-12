# Task-2_Lab-10

Lab 10 C++ exercises collected in one place.

## Files
- Task#1.cpp — `Book` and `Library`; prints two book titles and authors.
- Task#2.cpp — `Patient` and `Hospital`; hospital admits two patients and prints their details.

## Build
```
mkdir -p output
g++ -std=c++17 -Wall -Wextra -O2 Task#1.cpp -o output/Task#1
g++ -std=c++17 -Wall -Wextra -O2 Task#2.cpp -o output/Task#2
```

## Run
```
./output/Task#1
./output/Task#2
```

## Expected output
Task #1 (Book/Library):
```
Title: The Great Gatsby
Author: F. Scott Fitzgerald
------------------------
Title: 1984
Author: George Orwell
------------------------
```

Task #2 (Patient/Hospital):
```
Hospital admits Alice, age 30
Hospital admits Bob, age 45
```