# GroupProject1
To run, g++ -std=c++17 -Iinclude src/*.cpp -o groupProj

./groupProj

# Repo Link
https://github.com/Draconeez/GroupProject1

# Project workers
Aryn 
Will
KC

## UNT Server Deployment & Final System Testing
*Execution Environment: Ubuntu 22.04 LTS (cell01-cse.eng.unt.edu)*
*Compiler: GCC (g++) natively built via UNT terminal*

**Validation Testing Conducted:**
* **Cancellation History Integrity (Option 10):** Verified that the stack records valid deleted IDs while blocking fake inputs before they enter the stack.
* **Duplicate ID Prevention (Option 7):** Verified duplicate validation correctly blocks the "Undo" function from overriding reassigned reservations.
* **Core Functionality (Options 1, 5, 6, 9):** Verified resource loading, search logic, and sorting execute without segmentation faults.

<details>
<summary>Click here to expand terminal outputs</summary>

```text
uk0110@cell01-cse:~$ cd GroupProject1
uk0110@cell01-cse:~/GroupProject1$ 
uk0110@cell01-cse:~/GroupProject1$ ./program
Reached end of file.
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
4
Enter Reservation ID to delete (Ex. 001): 999
 == Error: Reservation ID 999 not found. ==
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
10
 == Cancellation history is empty. ==
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
4
Enter Reservation ID to delete (Ex. 001): 301
 == Reservation added to cancellation history. ==
 == Reservation 301 canceled successfully. ==
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
10
 == Cancellation History (Most Recent First) ==
 - Reservation ID: 301
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
13
 *===== Exiting the program. =====* 
uk0110@cell01-cse:~/GroupProject1$ ./program
Reached end of file.
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
1
Reservation ID: 301
Resource ID: R101
Student ID: 1001
Student Name: Alice Smith
Listed Date : 09/15/2026
----------------------------------------
Reservation ID: 302
Resource ID: R103
Student ID: 1002
Student Name: Bob Johnson
Listed Date : 09/16/2026
----------------------------------------
Reservation ID: 303
Resource ID: R105
Student ID: 1003
Student Name: Sara Lee
Listed Date : 09/17/2026
----------------------------------------
Reservation ID: 304
Resource ID: R107
Student ID: 1004
Student Name: David Kim
Listed Date : 09/18/2026
----------------------------------------
Reservation ID: 305
Resource ID: R109
Student ID: 1005
Student Name: Emma Davis
Listed Date : 09/19/2026
----------------------------------------
Reservation ID: 306
Resource ID: R111
Student ID: 1006
Student Name: Noah Wilson
Listed Date : 09/20/2026
----------------------------------------
Reservation ID: 307
Resource ID: R113
Student ID: 1007
Student Name: Mia Brown
Listed Date : 09/21/2026
----------------------------------------
Reservation ID: 308
Resource ID: R115
Student ID: 1008
Student Name: Liam Garcia
Listed Date : 09/22/2026
----------------------------------------
Reservation ID: 309
Resource ID: R117
Student ID: 1009
Student Name: Olivia Martinez
Listed Date : 09/23/2026
----------------------------------------
Reservation ID: 310
Resource ID: R119
Student ID: 1010
Student Name: Ethan Miller
Listed Date : 09/24/2026
----------------------------------------
Reservation ID: 311
Resource ID: R101
Student ID: 1011
Student Name: Ava Anderson
Listed Date : 09/25/2026
----------------------------------------
Reservation ID: 312
Resource ID: R103
Student ID: 1012
Student Name: Lucas Taylor
Listed Date : 09/26/2026
----------------------------------------
Reservation ID: 313
Resource ID: R105
Student ID: 1013
Student Name: Sophia Moore
Listed Date : 09/27/2026
----------------------------------------
Reservation ID: 314
Resource ID: R107
Student ID: 1014
Student Name: James Thomas
Listed Date : 09/28/2026
----------------------------------------
Reservation ID: 315
Resource ID: R109
Student ID: 1015
Student Name: Isabella Jackson
Listed Date : 09/29/2026
----------------------------------------
Reservation ID: 316
Resource ID: R111
Student ID: 1016
Student Name: Henry White
Listed Date : 09/15/2026
----------------------------------------
Reservation ID: 317
Resource ID: R113
Student ID: 1017
Student Name: Amelia Harris
Listed Date : 09/16/2026
----------------------------------------
Reservation ID: 318
Resource ID: R115
Student ID: 1018
Student Name: Daniel Martin
Listed Date : 09/17/2026
----------------------------------------
Reservation ID: 319
Resource ID: R117
Student ID: 1019
Student Name: Charlotte Thompson
Listed Date : 09/18/2026
----------------------------------------
Reservation ID: 320
Resource ID: R119
Student ID: 1020
Student Name: William Garcia
Listed Date : 09/19/2026
----------------------------------------
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
9
Resource ID: R101
Resource Name: Study Room 101
Resource Type: Study Room
Resource is available.
----------------------------------------
Resource ID: R102
Resource Name: Study Room 102
Resource Type: Study Room
Resource is available.
----------------------------------------
Resource ID: R103
Resource Name: Study Room 103
Resource Type: Study Room
Resource is not available.
----------------------------------------
Resource ID: R104
Resource Name: Study Room 104
Resource Type: Study Room
Resource is available.
----------------------------------------
Resource ID: R105
Resource Name: Laptop 01
Resource Type: Laptop
Resource is available.
----------------------------------------
Resource ID: R106
Resource Name: Laptop 02
Resource Type: Laptop
Resource is not available.
----------------------------------------
Resource ID: R107
Resource Name: Laptop 03
Resource Type: Laptop
Resource is available.
----------------------------------------
Resource ID: R108
Resource Name: Laptop 04
Resource Type: Laptop
Resource is available.
----------------------------------------
Resource ID: R109
Resource Name: Calculator 01
Resource Type: Calculator
Resource is not available.
----------------------------------------
Resource ID: R110
Resource Name: Calculator 02
Resource Type: Calculator
Resource is available.
----------------------------------------
Resource ID: R111
Resource Name: 3D Printer
Resource Type: Lab Equipment
Resource is available.
----------------------------------------
Resource ID: R112
Resource Name: Oscilloscope
Resource Type: Lab Equipment
Resource is not available.
----------------------------------------
Resource ID: R113
Resource Name: Arduino Kit
Resource Type: Lab Equipment
Resource is available.
----------------------------------------
Resource ID: R114
Resource Name: Math Tutoring
Resource Type: Tutoring Appointment
Resource is available.
----------------------------------------
Resource ID: R115
Resource Name: CS Tutoring
Resource Type: Tutoring Appointment
Resource is not available.
----------------------------------------
Resource ID: R116
Resource Name: Study Room 201
Resource Type: Study Room
Resource is available.
----------------------------------------
Resource ID: R117
Resource Name: Laptop 05
Resource Type: Laptop
Resource is available.
----------------------------------------
Resource ID: R118
Resource Name: Calculator 03
Resource Type: Calculator
Resource is not available.
----------------------------------------
Resource ID: R119
Resource Name: VR Headset
Resource Type: Lab Equipment
Resource is available.
----------------------------------------
Resource ID: R120
Resource Name: Physics Tutoring
Resource Type: Tutoring Appointment
Resource is available.
----------------------------------------
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
5
Enter Reservation ID to search (Ex. 001): 1001
Reservation ID 1001 not found.
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
6
Sorting resources...
Resources successfully sorted by ID.
====== Welcome to the Resource Reservation System! =====
Select an option from the menu below:
1. Display All Reservations
2. View Waitlist
3. Create a Reservation
4. Cancel Reservation
5. Search Reservations
6. Sort Resources
7. Undo Reservation Cancellation
8. Generate Full Report
9. View Resources
10. View Cancellation History
11. Search Resources
12. Remove Waitlist Entry
13. Exit
