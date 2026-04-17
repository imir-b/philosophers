*This project has been created as part of the 42 curriculum by vbleskin.*

# Philo

## Description

**Philo** is a 42 school project focused on the concepts of multi-threading and process synchronization. It is an implementation of the classic **Dining Philosophers problem** originally formulated by Edsger W. Dijkstra.

The premise is simple: Philosophers sit around a circular table doing one of three things: eating, thinking, or sleeping. While eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.

There are as many forks on the table as there are philosophers. Because serving and eating spaghetti is highly inconvenient with a single fork, a philosopher needs to take their right and their left forks to eat, one in each hand.

The main challenge of this project is to design a concurrent algorithm to ensure that no philosopher will starve, strictly avoiding **Deadlocks** and **Data Races**.

✨ **Mandatory Part**
- **Architecture:** One thread per philosopher.
- **Concepts:** Threads, shared memory.
- **Tools:** Mutexes (`pthread_mutex_t`).

🚀 **Bonus Part**
- **Architecture:** One process per philosopher.
- **Concepts:** Processes, distributed memory.
- **Tools:** Semaphores (`sem_t`), `fork()`.

## Instructions

### 🌧 Compilation

The project uses a `Makefile` to compile the source files.

* **Compile the project:**
    `make`
    -> This generates the `philo` executable for the mandatory part.

* **Compile the bonus:**
    `make bonus`
    -> This generates the `philo_bonus` executable for the bonus part.

* **Clean object files:**
    `make clean`

* **Full clean (objects + executables):**
    `make fclean`

* **Clean and compile :**
    `make re`

### 🌟 Execution

To run the program:
`./philo [n_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [n_meals(optional)]`

**Arguments details:**
* `number_of_philosophers`: The number of philosophers and also the number of forks.
* `time_to_die` (in milliseconds): If a philosopher didn't start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
* `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
* `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
* `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

**Example:**
`./philo 5 800 200 200 7`

## Resources & AI Usage
* `man gettimeofday`, `man usleep`, `man pthread_mutex_init`, `man pthread_create`.

**AI Usage**
* **Debugging Guidance:** AI was used to help analyze `Valgrind` and `-fsanitize=thread` logs, and to pinpoint logic flaws in thread communication (e.g., identifying misplaced mutex unlocks and race conditions on shared variables).
