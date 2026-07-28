# Bank Management System

A **Bank Management System** developed in **C** that simulates essential banking operations through a secure, menu-driven console application. The project uses modular programming and file handling to manage customer accounts, process transactions, and maintain persistent records using CSV files.

---

## Overview

This project demonstrates the implementation of a banking system with separate **Admin** and **User** modules. It focuses on secure account management, transaction processing, input validation, and persistent data storage without relying on external databases.

---

## Key Features

### Admin
- Create customer accounts
- Search existing accounts
- Edit account information
- Delete accounts
- View all customer accounts
- Automatic account number generation

### User
- Login using Account Number, Phone Number, or Email
- Deposit funds
- Withdraw funds
- Transfer money between accounts
- Balance enquiry
- View the latest transaction history
- Export mini statements as text files

### Transaction Management
- Unique transaction ID generation
- Date and time stamped transactions
- CSV-based transaction history
- Last 10 transactions displayed as a mini statement

### Validation
- Name validation
- Phone number validation
- Email validation
- PIN validation
- Duplicate phone and email detection

### Data Storage
- Account information stored in `accounts.csv`
- Transaction history stored in `history.csv`
- Statements exported to the `statements/` directory

---

## Technologies Used

- C Programming
- Structures
- Modular Programming
- File Handling
- CSV Storage

---

## Project Structure

```text
.
├── main.c
├── atm.c
├── atm.h
├── transaction.c
├── transaction.h
├── validation.c
├── validation.h
├── file.c
├── file.h
├── accounts.csv
├── history.csv
├── statements/
└── README.md
```

---

## Build

```bash
gcc main.c atm.c transaction.c validation.c file.c -o bank_management_system
```

## Run

```bash
./bank_management_system
```

---

## Screenshots

Add screenshots here:

- Main Menu
- Admin Module
- User Dashboard
- Transaction Menu
- Mini Statement
- Exported Statement

---

## Future Enhancements

- PIN change functionality
- Password encryption
- Account lock after multiple failed login attempts
- Database integration (SQLite/MySQL)
- Graphical User Interface (GUI)

---

## Author

**Deekshith**

Third Year Electronics Engineering Student

---

If you found this project useful, consider giving it a **⭐** on GitHub.
