# CPP_00
# 📖 C++ Module 00 — Introduction to C++

This project is the first step in learning C++ at 42 school.  
It introduces the basics of object-oriented programming (OOP), C++ syntax, and common conventions.  

The exercises progress from very simple programs to structured class-based designs, helping me move from a C mindset to a C++ mindset.

---

## 🔹 What I Learned
- The difference between C and C++ in terms of structure and style.
- How to use **classes**, **objects**, **member functions**, and **access specifiers** (private/public).
- Proper use of **constructors**, **destructors**, and initialization.
- Using **header (`.hpp`) and source (`.cpp`) files** with include guards.
- Handling **basic input/output** with `std::cin` and `std::cout`.
- Formatting console output with `<iomanip>`.
- How to organize code into multiple files and compile with a **Makefile**.
- Building good habits for **readability, modularity, and maintainability**.

---

## 🔹 Exercises Overview

### **ex00 — Megaphone**
- A simple program that takes arguments from the command line and prints them in **uppercase**.  
- If no arguments are provided, it prints a default loud noise message.  
- Purpose: get comfortable with `main`, command-line arguments, and `std::string`.

---

### **ex01 — My Awesome PhoneBook**
- A small **interactive program** that stores up to 8 contacts.  
- Commands supported:
  - `ADD` → add a new contact (first name, last name, nickname, phone number, darkest secret).  
  - `SEARCH` → list saved contacts in a formatted table and show details of a chosen one.  
  - `EXIT` → quit the program.  
- Oldest contacts are overwritten when adding beyond 8.  
- Purpose: learn **classes (`Contact`, `PhoneBook`)**, arrays of objects, and formatted output.

---

### **ex02 — The Job of Your Dreams**
- Re-implementing a missing source file (`Account.cpp`) based on a header and a log file.  
- Purpose: practice reading code specifications, reconstructing class behavior, and ensuring output matches requirements.  
- This simulates working in a real dev team where you might have to rebuild missing code.

---

## 🔹 How to Use

### Build
Inside each exercise folder:
```sh
make
