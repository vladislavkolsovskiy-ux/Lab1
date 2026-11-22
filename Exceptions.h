// Exceptions.h
#pragma once
#include <exception>
#include <string>

class FileOpenException : public std::exception {
    std::string message;
public:
    FileOpenException(const std::string& msg) : message("File error: " + msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class EmptyContainerException : public std::exception {
public:
    const char* what() const noexcept override { return "Error: Container is empty!"; }
};

class InvalidInputException : public std::exception {
    std::string message;
public:
    InvalidInputException(const std::string& msg) : message("Invalid input: " + msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};