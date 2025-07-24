# Elevator Backend

This project is a demo inspired by a coding exercise I was given during an interview. It is a
software simulation of a bank of elevators.

## Code Requirements

- A building may have a bank of one or more elevators
- An elevator may stop at two or more floors (why put in an elevator for only
  one floor?), but need not stop at all floors.
- An elevator moves at one unit per "tick". Floors are multiple units apart, and a tick is the 
  amount of time between a central timer firing. 
- Each elevator is controlled by a single thread.

## Configuration

An elevator bank is configured with a JSON file.
