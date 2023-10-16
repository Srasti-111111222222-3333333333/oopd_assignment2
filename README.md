# oopd_assignment2
# Library Management Application

The Library Management Application is a console-based program written in C++. It serves as a tool for managing library operations, including user registration, item search, item borrowing, and tracking issued items. This application is designed to work with books, journals, and publications and allows users to interact with the library system efficiently.

## Features

- User Registration: Users can register as either faculty members or students. The system generates a unique user ID for each registered user.

- Search Item:  Users can search for items (books, journals, and publications) by providing a keyword. The system displays a list of matching items.

- Request Item: Users can request to borrow an available item by providing the book ID and user ID. The system checks the availability of the item and records the issue details, including due dates.

- Display Issued Items: Users can view a list of all issued items, including their issue dates, return dates, and user information.

- Display All Users: Users can view a list of all registered users, including their user IDs, usernames, and user types.

- Data Loading: The application reads data from CSV files for books, publications ranks, and journals during initialization. This data is used for searching and issuing items.

## Data Files

- books.csv : Contains data for books, including details like book ID, title, author, ISBN, and more.

- publications_rank.csv : Contains data for publication ranks, including details like publication name, rank, total paid, and more.

- journals.csv : Contains data for journals, specifically IEEE Latin America Transactions.

## Usage
 
1. Compile the program:
   for 1st question: g++ -o S1.cpp
   for 2nd question: g++ -o S2.cpp
Run the program:
./S1
Choose the mode (Librarian or Member) and follow the on-screen menu to perform various library operations.

Sample Data
The application comes with sample data in the CSV files. You can customize these files with your own data as needed.

Notes
The application uses C++ classes to model physical library items (books, magazines) and electronic items (ebooks).

Users can register and borrow items, and the system keeps track of borrowed items and their locations.

Librarians can purchase books to add to the library's inventory.

You can expand this code by adding more item types (e.g., magazines, newspapers) and implementing more sophisticated borrowing and returning logic.

Error handling and input validation are intentionally minimal in this example. Consider enhancing these aspects for a production-ready system.


Enjoy using the Library Management Application!
