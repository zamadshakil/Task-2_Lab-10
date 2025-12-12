# Task-2_Lab-10

Lab 10 C++ exercises collected in one place.

## Files
- Task#1.cpp — `Book` and `Library`; prints two book titles and authors.
- Task#2.cpp — `Patient` and `Hospital`; hospital admits two patients and prints their details.
- Task#3.cpp — `Trainer` works with multiple `Member` objects and prints training messages.
- Task#4.cpp — `Car` composed with an `Engine`; prints car brand/model and engine details.
- Task#5.cpp — Student Management (`Student`, `Instructor`, `Course`); enforces 30-student cap and displays enrollments and instructor.

## Build
```
mkdir -p output
g++ -std=c++17 -Wall -Wextra -O2 Task#1.cpp -o output/Task#1
g++ -std=c++17 -Wall -Wextra -O2 Task#2.cpp -o output/Task#2
g++ -std=c++17 -Wall -Wextra -O2 Task#3.cpp -o output/Task#3
g++ -std=c++17 -Wall -Wextra -O2 Task#4.cpp -o output/Task#4
g++ -std=c++17 -Wall -Wextra -O2 Task#5.cpp -o output/Task#5
```

## Run
```
./output/Task#1
./output/Task#2
./output/Task#3
./output/Task#4
./output/Task#5
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

Task #3 (Trainer/Member):
```
Trainer John is training Alice
Trainer John is training Bob
Trainer John is training Charlie
```

Task #4 (Car/Engine):
```
=== Car 1 Information ===
Car Brand: Toyota
Car Model: Camry
Horsepower: 301
Fuel Type: Gasoline

=== Car 2 Information ===
Car Brand: Tesla
Car Model: Model S
Horsepower: 670
Fuel Type: Electric
```

Task #5 (Student/Instructor/Course):
```
Total students in oopLabSecC4: 0
Total students after adding: 3

-- oopLabSecC4 --
Course: OOPFall2023SecC4Lab
Instructor: AASMA ABDUL WAHEED (MPHIL)
Total Students: 3
No.     Registration No         Student Name
1.      L1F1YBSCS1ABC   Ali
2.      L1F1YBSCS2ABC   Ahmad
3.      L1F1YBSCS3ABC   Ammar

-- oopLabSecC2 (after deleting oopLabSecC4) --
Course: OOPFall2023SecC2Lab
Instructor: USAMA PERVAIZ (MPHIL)
Total Students: 2
No.     Registration No         Student Name
1.      L1F1YBSCS1ABC   Ali
2.      L1F1YBSCS3ABC   Ammar

inst1 still accessible: AASMA ABDUL WAHEED
```