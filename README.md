# cpp-robot-fleet-manager
A C++ console application demonstrating Object-Oriented Programming (Polymorphism) and custom Linked Lists for dynamic robotic fleet management.
# C++ Dynamic Robot Fleet Manager

## Overview
This project is a console-based management system designed to register and operate a fleet of different robotic units. It is built entirely in **C++** from scratch, avoiding standard template libraries (like `<vector>`) to demonstrate a deep understanding of low-level memory management and data structures.

## 🚀 Key Features
* **Object-Oriented Programming (OOP):** Utilizes inheritance to create specific robot types (`Drone`, `IndustrialRobot`) from a base abstract class (`Robot`).
* **Polymorphism:** The system can issue a generic `operate()` command to the entire fleet, and each robot executes its specific, overridden behavior.
* **Custom Data Structures:** Implements a custom **Singly Linked List** (`NodoFlota`) to store objects dynamically in the Heap.
* **Dynamic Memory Management:** Safe allocation (`new`) and deallocation (`delete`) of memory to prevent memory leaks during runtime and upon system exit.
* **Input Validation:** Robust handling of standard input buffer (`cin.clear()`, `cin.ignore()`) to prevent infinite loops on invalid user inputs.

## Technologies
* C++ (Standard Console Application)
* Windows API (`<windows.h>` for console manipulation)

## Concepts Demonstrated
- Abstract Classes and Pure Virtual Functions (`= 0`).
- Base Class Constructor Initialization.
- Pointers, References, and Heap Memory Management.
- Structs nested within Classes.

## ⚙️ Software Architecture & C++ Features

This project was built using modern C++ standards, focusing on memory safety and modular Object-Oriented Programming (OOP) principles:

* **Modular Design:** Strict separation of interfaces (`.h` files), implementations (`.cpp` files), and control flow (`main.cpp`).
* **Dynamic Memory Management:** Custom Linked List (`NodoFlota`) implementation to manage the fleet in the Heap. Includes a robust garbage collection routine (`releaseFleet`) to prevent memory leaks upon system shutdown.
* **Polymorphism:** Virtual methods allow a single `operateFleet()` controller to dynamically resolve instructions for different hardware types (Drones vs. Industrial Robots) at runtime.
* **Constructor Overloading:** Implemented flexible instantiation pathways. The system simulates real-world hardware registration by allowing both full-diagnostic initialization (custom battery/status) and "Quick Factory Registration" (assuming default 100% capacity parameters).

## Author
**Juan Pablo Quezada** *B.Sc. in Intelligent Computing Engineering Universidad Autónoma de Aguascalientes (UAA)*

