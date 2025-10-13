[Project Name]
AddressBook - Student Information Manager
-------------------------------------------

[Development Environment]
- OS: Windows 11
- Compiler: Microsoft Visual C++ 
- IDE: Visual Studio 2022 
- Language Standard: C++17

[How to Compile]
1. Open the solution (.sln) file in Visual Studio.
2. Make sure all .cpp and .h source files are included in the project.
3. Select "Build → Build Solution" (or press Ctrl + Shift + B).

[How to Execute]
1. After successful build, an executable file (oopAddressBook.exe) will be generated in the project directory (e.g., /x64/Debug/ or /x86/Debug/).
2. Click the "Run" button (▶) in Visual Studio, or press F5 to start execution.
3. The console window will open automatically.

[Program Features Overview]
The program operates through a console-based menu (options 1–6).
Each option triggers a specific feature such as adding, removing, searching, sorting, and printing student records.

[Program Description]
1. Add
Prompts the user to enter five fields:
Name, Student ID, Birth Year, Department, and Tel.
The input data are stored in the CUserData class,
linked as a singly linked list through CMyNode → CMyList.
This allows dynamic storage and traversal of all student records.

2. Remove
Prompts the user to input a StudentID.
Traverses the linked list to find and delete the node with a matching name.

3. Search
Search student records based on various criteria:
Search Type	Description
Name	Finds records with exact matching name
Student ID	Finds by unique student ID
Admission Year	Extracted from the first 4 digits of Student ID
Birth Year	Finds by year of birth
Department	Finds all students in the same department
Partial Name	Finds records containing a given substring

After displaying the results:
The user is prompted with
[1] Save and return or [2] Return without saving.
When saved, results are appended to file1.txt along with a timestamp.

4. Print All
Displays all student records currently stored in the list.
After output, the user can choose to save the list to file1.txt.
Functionally identical to Search → List All,
but provided as a dedicated main-menu option for readability.

5. Sort
Sorts all student data in ascending order by a selected field.
The user chooses the sort key:
Option	Sort Criterion
1	Name
2	Student ID
3	Birth Year
4	Department
Sorting is implemented using the STL std::sort() function on a temporary vector<CMyNode*>,
then re-linked to the original list via fromVector().
After sorting, all records are displayed and the user may save the results to file1.txt.

6. Statistics
Displays summary counts of students categorized by:
Admission Year (first 4 digits of Student ID)
Birth Year
Department
This feature provides quick population insights for each classification.

0. Exit
Terminates the program and returns to the system console.

-Additional Notes
All file outputs are appended to file1.txt with timestamps.