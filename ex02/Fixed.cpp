#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Overloaded operators
bool Fixed::operator>(const Fixed &other) const {
    std::cout << "Greater than operator called" << std::endl;
    return this->fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    std::cout << "Less than operator called" << std::endl;
    return this->fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    std::cout << "Greater than or equal operator called" << std::endl;
    return this->fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    std::cout << "Less than or equal operator called" << std::endl;
    return this->fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    std::cout << "Equal operator called" << std::endl;
    return this->fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    std::cout << "Not equal operator called" << std::endl;
    return this->fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
    std::cout << "Addition operator called" << std::endl;
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const{
    std::cout << "Subtraction operator called" << std::endl;
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const{
    std::cout << "Multiplication operator called" << std::endl;
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const{
    std::cout << "Division operator called" << std::endl;
    if (other.fixedPointValue == 0) {
        std::cerr << "Division by zero error" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    std::cout << "Pre-increment operator called" << std::endl;
    ++this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    std::cout << "Post-increment operator called" << std::endl;
    Fixed temp = *this;
    ++this->fixedPointValue;
    return temp;
}

Fixed &Fixed::operator--() {
    std::cout << "Pre-decrement operator called" << std::endl;
    --this->fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    std::cout << "Post-decrement operator called" << std::endl;
    Fixed temp = *this;
    --this->fixedPointValue;
    return temp;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Public member functions
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return fixedPointValue >> fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

// Other functions
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}