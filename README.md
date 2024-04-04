# Sports Facility Booking System

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Screenshots](#screenshots)
6. [Contributing](#contributing)
7. [License](#license)
   

## Introduction

The Sports Facility Booking System is a command-line application designed to manage the booking of sports facilities at a university. It provides a simple and efficient way for students to book facilities, view their booking history, and delete their bookings. The system also supports user authentication, ensuring that only registered students can make bookings.

## Features

- **User Authentication**: Students can log in using their roll number and password. New students can be added to the system by an administrator. The system also automatically adds some students when it starts.

- **Booking Facilities**: Students can book a facility for a specific date and timeslot. The system checks for booking conflicts and only allows bookings if the facility is available.

- **Viewing Booking History**: Students can view their past bookings, providing a convenient way to keep track of their activities.

- **Deleting Bookings**: Students can delete their bookings if they no longer need them, freeing up the facility for other students.

## Installation

To install the Sports Facility Booking System, follow these steps:

1. Clone the repository: `git clone https://github.com/might-guy106/Mastering-web-3.0-Recruitment-Task.git`
2. Navigate to the project directory: `cd sports-facility-booking-system`
3. Compile the program using g++: `g++ main.cpp -o main`

## Usage

To run the Sports Facility Booking System, use the following command: `./main`

When you run the program, you will be asked to enter your roll number and password. If you are a new student, an administrator can add you to the system.

Once you are logged in, you can choose from the following options:

1. Book a facility: You will be asked to enter the facility type, date, and timeslot.
2. View your booking history: Your past bookings will be displayed.
3. Delete a booking: You will be asked to enter the details of the booking you want to delete.

## Screenshots

![Login Screen](/images/login.png)

Here's what the login screen looks like.

![Home Screen](/images/home.png)

Here you can see all the functionalities that student have.

![Booking Screen](/images/booking.png)

This is the screen where you can book a facility.

![History Screen](/images/history.png)

You can view your booking history on this screen.

![Delete Booking Screen](/images/delete.png)

This is where you can delete a booking.

## Contributing

Contributions are welcome! Please read the [contributing guidelines](CONTRIBUTING.md) before getting started.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.md) file for details.
