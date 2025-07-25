# 💳 Bank Account Management System

A simple **Bank Account Management System** built using **C++**, applying **Object-Oriented Programming (OOP)** and **File Handling**. This is a console-based application that allows users to create accounts, deposit cash, and withdraw cash with persistent storage through text files.

## 🚀 Features

- Create a new bank account
- Deposit cash into an existing account
- Withdraw cash with password verification
- Persistent data storage using `.txt` files
- Console-based UI with user prompts and feedback

## 🛠️ Tech Stack

- **Language:** C++
- **Concepts Used:** 
  - Object-Oriented Programming (Encapsulation, Abstraction)
  - File Handling (`fstream`)
  - Command-Line Interface (CLI)
  - Windows API for console control (`windows.h`)


## ✅ How It Works

1. **Open Account**  
   User enters account number and sets a password. A new account is initialized with `0` balance and saved to `Account.txt`.

2. **Add Cash**  
   Enter the account number → If found, prompt for amount → Add to balance → Update file.

3. **Withdraw Cash**  
   Enter account number and password → If authenticated, prompt for amount → Deduct from balance if sufficient funds → Update file.

## 📌 Notes

- All account data is stored in plain text format with delimiters.
- Uses temporary file overwrite method to safely update data.
- Console is cleared and paused using `system("cls")` and `Sleep()` for a better user experience.

## 🧠 Concepts Demonstrated

- Class design with private members and public methods
- File I/O using `ifstream`, `ofstream`
- String manipulation using `stringstream`
- Condition-based file rewriting (updating specific entries)

## 💡 Future Improvements

- Add transaction history logging
- Enable fund transfers between accounts
- Replace file handling with a database (e.g., SQLite)
- Implement user login sessions
- GUI using Qt or C++/CLI for better interface



