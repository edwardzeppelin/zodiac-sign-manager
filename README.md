# Zodiac Sign Manager

A C++ console application for managing a database of personal records, including names, surnames, zodiac signs, and dates of birth.

## Features

* **Data Management:** Supports adding, editing, deleting, and displaying records dynamically.
* **Sorting:** Automatically sorts the list of profiles chronologically by their date of birth.
* **Search:** Allows filtering and finding records matching a specific zodiac sign.
* **Validation:** Includes basic input validation for calendar days and months during entry.

## Project Structure

* main.cpp — Handles the interactive menu loop, dynamic array reallocation, and sorting logic.
* sign.h — Defines the private data structures and public interface of the sign class.
* sign.cpp — Implements constructors, input validation, and overloaded I/O stream operators.
