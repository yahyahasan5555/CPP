# Hospital System (Console App)

My **first project ever**, written in **November 2025**, using only the very basics of C++.

A small console program that manages a hospital waiting queue for **20 specializations**, with up to **5 patients per specialization**.

## What it does

1. **Add new patient**: enter the specialization (1-20), the name, and the status (`0` = regular, `1` = urgent). Urgent patients are placed at the front of the queue.
2. **Print all patients**: shows each specialization that has patients, in queue order.
3. **Get next patient**: calls the first patient in a specialization and removes them from the queue.
4. **Exit**

It also handles wrong input (letters instead of numbers, out-of-range choices) and tells you when a specialization is full or empty.

## Screenshots

| Adding patients                                                                                         | Printing the queue                                                                                          |
| ------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| [add](https://github.com/yahyahasan5555/CPP/blob/main/00-projects/01-hospital/demo/01-add-patients.png) | [print](https://github.com/yahyahasan5555/CPP/blob/main/00-projects/01-hospital/demo/02-print-patients.png) |
|                                                                                                         |                                                                                                             |

| Calling the next patient                                                                                     | Invalid input                                                                                                |     |
| ------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------ | --- |
| [next](https://github.com/yahyahasan5555/CPP/blob/main/00-projects/01-hospital/demo/03-get-next-patient.png) | [invalid](https://github.com/yahyahasan5555/CPP/blob/main/00-projects/01-hospital/demo/04-invalid-input.png) |     |

| Specialization is full                                                                                          |
| --------------------------------------------------------------------------------------------------------------- |
| [full](https://github.com/yahyahasan5555/CPP/blob/main/00-projects/01-hospital/demo/05-specialization-full.png) |

## What I knew when I wrote it

Only the basics: data types, variables, `if` / `else`, loops, 1D and 2D arrays, functions, and printing/reading with `cout` / `cin`. No structs, classes, or STLs yet, so the data is stored in plain global arrays:

```cpp
int specializations[20];   // how many patients in each specialization
string names[20][5];       // patient names
bool status[20][5];        // 0 = regular, 1 = urgent
```

Urgent patients are inserted by shifting the array to the right, and removing a patient shifts it to the left.

## Run it

```bash
g++ hospital.cpp -o hospital
./hospital
```

## What I would improve now

- Use a `struct` for a patient instead of parallel arrays.
- Use `std::deque` so the 5-patient limit and manual shifting go away.
