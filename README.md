# Tutorial Management System

A C++ and Qt Framework desktop application for managing educational tutorials, supporting two user roles with different capabilities.

## Features

### Administrator
- Full CRUD operations (Create, Read, Update, Delete) on tutorials
- Data validation to prevent duplicates
- Undo/Redo support (Ctrl+Z / Ctrl+Y)
- Toggle between detailed and short view modes

### User
- Browse and filter tutorials by presenter
- Manage a personal watch-later list
- Export watchlists to CSV or HTML formats
- Open tutorial links directly in browser

## Tech Stack
- **C++17** — STL, smart pointers, inheritance, template classes
- **Qt 6** — GUI framework (signals/slots, QListWidget, QInputDialog)
- **Visual Studio 2022** — IDE
- **File-based persistence** — `tutorials.txt`

## Architecture
- **Repository pattern** — `Repo` handles file I/O
- **Service layer** — `Service` and `UserService` handle business logic
- **Command pattern** — `Action`, `ActionAdd`, `ActionRemove`, `ActionUpdate` for undo/redo
- **MVC** — Separate model (`Tutorial`), views (`AdminWindow`, `UserWindow`), controllers (services)

## Project Structure
```
Qt3/
├── main.cpp                  # Entry point
├── Qt3.h / Qt3.cpp           # Main window
├── AdminWindow.h/.cpp        # Admin UI
├── UserWindow.h/.cpp         # User UI
├── TutorialTableModel.h      # Qt table model
├── functionalities/
│   ├── Tutorial.h/.cpp       # Data model
│   ├── Repo.h/.cpp           # File persistence
│   ├── Service.h/.cpp        # Admin business logic + undo/redo
│   ├── UserService.h/.cpp    # User business logic
│   ├── Action.h              # Abstract command
│   ├── ActionAdd/Remove/Update.h
│   ├── DynamicArray.h        # Generic dynamic array
│   ├── FileWriter.h          # Abstract file export
│   ├── HTMLFileWriter.h      # HTML export
│   ├── CVS.h                 # CSV export
│   └── Exception.h           # Custom exceptions
└── tutorials.txt             # Tutorial database
```

## How to Run
1. Install **Visual Studio 2022** and **Qt VS Tools** extension
2. Install **Qt 6.x** libraries
3. Open `Qt3.sln`
4. Configure the Qt version in Qt Options
5. Build and run with **F5**
