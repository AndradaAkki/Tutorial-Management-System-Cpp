# 📚 Tutorial Management System

A desktop application built with **C++** and the **Qt Framework** designed to manage and visualize educational content. The application implements a **Master-Detail architecture**, supporting distinct permissions and functionalities for Administrators and Standard Users.

![C++](https://img.shields.io/badge/Language-C++11/14/17-blue)
![GUI](https://img.shields.io/badge/Framework-Qt_6-green)
![IDE](https://img.shields.io/badge/IDE-Visual_Studio-purple)

## 📖 Overview
This application serves as a comprehensive tool for managing a database of technical tutorials. It features a graphical user interface (GUI) that allows users to browse content while enabling administrators to maintain the data integrity of the system.

The project demonstrates proficiency in **Object-Oriented Programming (OOP)**, **GUI Development**, and **File Persistence**.

## 🛠️ Tech Stack
* **Language:** C++ (STL Vectors, Smart Pointers, Inheritance)
* **GUI Framework:** Qt (QWidget, Signals & Slots, Layout Management)
* **IDE:** Visual Studio (MSVC Compiler)
* **Persistence:** File-based storage (`tutorials.txt`) / *[Note: If you added SQL later, change this to "SQL Database"]*

## ✨ Key Features

### 👨‍💻 Administrator Mode
* **CRUD Operations:** Full capability to **Create, Read, Update, and Delete** tutorials in the database.
* **Data Validation:** Prevents duplicate entries and ensures valid input formats.
* **Real-time Updates:** Changes made by the admin are immediately reflected in the repository.

### 👤 User Mode
* **Browse & Filter:** View available tutorials with options to filter by category or presenter.
* **Watchlist Management:** Users can add tutorials to a personal "Watchlist," delete them, or view them in a browser.
* **CSV/HTML Export:** *(If your project does this, keep this line, otherwise delete)* Export the watchlist to external file formats.

## 📂 Project Structure
* `main.cpp` - Entry point of the application.
* `AdminWindow.cpp/h` - Encapsulates logic for the administrator interface.
* `UserWindow.cpp/h` - Encapsulates logic for the user watchlist interface.
* `Qt3.ui` - XML-based UI definition for the main window layout.
* `tutorials.txt` - Persistent data storage for the tutorial repository.

## 🚀 How to Run
1.  **Prerequisites:**
    * Visual Studio 2019/2022.
    * Qt VS Tools extension installed.
    * Qt 6.x (or 5.x) libraries linked.
2.  **Installation:**
    ```bash
    git clone [https://github.com/YourUsername/Tutorial-Management-System.git](https://github.com/YourUsername/Tutorial-Management-System.git)
    ```
3.  **Build:**
    * Open `Qt3.sln` in Visual Studio.
    * Ensure the Qt version is correctly set in "Qt VS Tools" -> "Qt Options".
    * Build Solution (`Ctrl+Shift+B`).
4.  **Run:**
    * Press `F5` to launch the application.
