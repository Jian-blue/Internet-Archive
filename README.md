# Internet Archive – C++ OOP Project

This C++ project simulates a virtual archive of major internet events like tech launches and viral memes. It demonstrates core Object-Oriented Programming (OOP) principles such as abstraction, encapsulation, inheritance, and polymorphism — with additional use of file handling and terminal color formatting.

---

## Features

- Load internet events from a text file (`events.txt`)
- Display events using polymorphic formatting:
  - Tech events appear in blue
  - Meme events appear in green
- Console-based application
- Clear demonstration of OOP concepts
- Lightweight and beginner-friendly

---

## OOP Concepts Used

| Concept       | How It's Used                                                                 |
|---------------|--------------------------------------------------------------------------------|
| Abstraction   | `InternetEvent` class is abstract via a virtual method                        |
| Inheritance   | `TechLaunchEvent` and `MemeEvent` inherit from `InternetEvent`                |
| Polymorphism  | `displayDetails()` behaves differently based on the actual event type         |
| Encapsulation | `Archive` and `InternetEvent` manage private members via public methods       |

---

## Input File Format (`events.txt`)

Each event should follow this 3-line format:

![image](https://github.com/user-attachments/assets/a24d2ea6-9756-41cf-8e7f-00f71af269e0)

- The app detects "Meme" in the title to classify as a Meme event.
- All others are treated as Tech events.

---

## How to Run

1. **Set up your environment:**
   - Use Windows for full color support (or any ANSI-compatible terminal)
   - Install a C++ compiler (e.g., `g++`)

2. **Compile the project:**

   ```bash
   g++ -std=c++17 Internet_Archive.cpp -o Internet_Archive

3. **Create a file named `events.txt`** and add your internet events as described above.

4. **Run the program:**

   ```bash
   ./Internet_Archive

### Terminal Output Preview:
![image](https://github.com/user-attachments/assets/cee4d52d-ac8b-4ec6-9548-5824ed43ebfa)
Note: Colors will appear only in supported terminals — blue for tech, green for memes.

---

## Author  

Shafayat Yeamin Jian  
B.Sc. in Computer Science & Engineering  
  
This project is open-source and free to use for any work. Contributions and creative applications of this project are highly appreciated.
