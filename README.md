# 🍽️ Philosophers - 42 School Project

Welcome to **Philosophers**! 🎉 This is one of the most challenging projects from **Rank 3** at 42 School that introduces us to the world of **concurrent programming**, **threading**, and **synchronization**. Based on the classic "Dining Philosophers Problem" by Edsger Dijkstra, this project teaches us about deadlocks, race conditions, and how to coordinate multiple threads safely.

The challenge is to simulate philosophers who must eat, sleep, and think while sharing forks, without anyone starving to death! 🚀

---

### 📂 Project Structure

philosophers/
├── philo/                 # Main philosophers program  
│   ├── include/philo.h    # Header file (.h)  
│   ├── src/               # Source files (.c)  
│   │   ├── philo.c        # Main program entry point  
│   │   ├── dinner/        # Simulation control  
│   │   │   ├── init_params.c    # Parameter initialization  
│   │   │   ├── start_dinner.c   # Simulation startup  
│   │   │   └── join_philos.c    # Thread management  
│   │   ├── routines/      # Philosopher behaviors  
│   │   │   ├── philo_routine.c  # Main philosopher routine  
│   │   │   ├── death_routine.c  # Death monitoring  
│   │   │   ├── routine_eat.c    # Eating behavior  
│   │   │   ├── routine_sleep.c  # Sleeping behavior  
│   │   │   └── routine_think.c  # Thinking behavior  
│   │   └── utils/         # Utility functions  
│   │       ├── get_time.c       # Time management  
│   │       ├── print_action.c   # Thread-safe printing  
│   │       ├── safe_functions.c # Safe utility functions  
│   │       ├── check_simulation.c # Simulation monitoring  
│   │       ├── free_dinner.c    # Memory cleanup  
│   │       └── libft.c          # Basic utilities  
│   └── Makefile          # Makefile to compile  
├── .gitignore  
└── README.md             # This file  

---

### 🧠 The Dining Philosophers Problem

#### 🎯 The Classic Problem
The dining philosophers problem is a classic synchronization problem in computer science:

- **N philosophers** sit around a circular table
- Each philosopher has a **plate of spaghetti** in front of them
- There is exactly **one fork** between each pair of adjacent philosophers
- To eat, a philosopher must pick up **both forks** (left and right)
- Philosophers alternate between **eating**, **sleeping**, and **thinking**
- The challenge: prevent **deadlock** and **starvation**

#### 🍴 The Rules
1. **Philosophers can only do three things**: eat, sleep, think
2. **To eat**: Must acquire both left and right forks
3. **After eating**: Must put down both forks and sleep
4. **After sleeping**: Must think
5. **Goal**: No philosopher should starve (die from not eating)

---

### ⚙️ Core Concepts

#### 🧵 Threading & Synchronization
- **Threads**: Each philosopher runs in its own thread
- **Mutexes**: Forks are protected by mutex locks
- **Race conditions**: Multiple threads accessing shared resources
- **Deadlock prevention**: Strategies to avoid circular waiting
- **Critical sections**: Protected code regions

#### ⏰ Timing Management
- **Precise timing**: Microsecond-level time tracking
- **Death timer**: Each philosopher has a limited time to eat
- **Action timing**: Eating, sleeping, and thinking durations
- **Simulation control**: Monitor overall simulation state

---

### 🎮 Simulation Parameters

#### 📝 Command Line Arguments
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

- **number_of_philosophers**: Number of philosophers (and forks)
- **time_to_die**: Time in ms after which a philosopher dies if not eating
- **time_to_eat**: Time in ms it takes for a philosopher to eat
- **time_to_sleep**: Time in ms a philosopher sleeps
- **number_of_times_each_philosopher_must_eat**: [Optional] Simulation stops when all philosophers have eaten this many times

---

## 🛠️ How to Use

### 📦 Compilation

To compile the program, navigate to the philo directory and run:

```bash
cd philo
make
```

This will generate the `philo` executable.

### 🧩 Usage

Launch the simulation with the required parameters:

```bash
./philo [nb_philos] [time_to_die] [time_to_eat] [time_to_sleep] [optional: must_eat_count]
```

### 💡 Usage Examples

#### Basic Examples
```bash
# 5 philosophers, die in 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but stop when each philosopher has eaten 7 times
./philo 5 800 200 200 7

# Edge case: 1 philosopher (should die)
./philo 1 800 200 200

# Large simulation: 100 philosophers
./philo 100 800 200 200
```

#### Testing Scenarios
```bash
# Test for deadlock (should not happen)
./philo 4 410 200 200

# Test for quick death
./philo 5 100 200 200

# Test for starvation prevention
./philo 5 800 200 200 10
```

---

## 🎯 Output Format

The simulation outputs timestamped actions for each philosopher:

```
[timestamp_ms] [philosopher_id] [action]
```

### Action Types
- **"has taken a fork"**: Philosopher picked up a fork
- **"is eating"**: Philosopher is eating (has both forks)
- **"is sleeping"**: Philosopher is sleeping (released forks)
- **"is thinking"**: Philosopher is thinking
- **"died"**: Philosopher died from starvation

### Example Output
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
400 1 is thinking
400 2 has taken a fork
...
```

---

## ✅ Project Requirements

- ✅ Each philosopher is a thread
- ✅ Forks are protected by mutexes
- ✅ Precise timing with `gettimeofday()`
- ✅ Thread-safe output printing
- ✅ No data races
- ✅ No deadlocks
- ✅ No philosopher should die (unless unavoidable)
- ✅ Death detection within 10ms
- ✅ Handle edge cases (1 philosopher, invalid arguments)
- ✅ Clean program termination

---

## 🔧 Technical Implementation

### 🧵 Threading Strategy
- **Main thread**: Manages simulation and monitors for death
- **Philosopher threads**: One per philosopher, runs eating/sleeping/thinking cycle
- **Death monitor**: Continuously checks if any philosopher has died
- **Synchronization**: Mutexes for forks and shared data

### 🍴 Fork Management
- **One mutex per fork**: Prevents simultaneous access
- **Ordered acquisition**: Prevents circular waiting deadlock
- **Fair distribution**: Ensures all philosophers get chances to eat

### ⏱️ Timing Precision
- **Microsecond accuracy**: Using `gettimeofday()` for precise timing
- **Non-blocking checks**: Efficient monitoring without busy waiting
- **Death detection**: Quick detection when a philosopher dies

---

## 🚨 Common Challenges & Solutions

### 🔒 Deadlock Prevention
- **Ordered resource acquisition**: Always acquire lower-numbered fork first
- **Timeout mechanisms**: Prevent indefinite waiting
- **Careful critical section design**: Minimize lock holding time

### 🏃 Race Condition Avoidance
- **Atomic operations**: Use mutexes for shared data access
- **Thread-safe printing**: Protect output with mutex
- **State synchronization**: Consistent state across threads

### ⚡ Performance Optimization
- **Minimal locking**: Reduce mutex contention
- **Efficient timing**: Avoid unnecessary system calls
- **Smart waiting**: Use appropriate timing strategies

---

## 🧪 Testing & Validation

### Basic Functionality Tests
```bash
# Test normal operation
./philo 5 800 200 200 7

# Test edge cases
./philo 1 800 200 200
./philo 2 400 200 100

# Test large numbers
./philo 200 800 200 200
```

### Stress Tests
```bash
# Quick death scenarios
./philo 4 310 200 100

# Long-running simulations
./philo 5 800 200 200 100

# Tight timing
./philo 4 410 200 200
```

### Validation Criteria
- **No deaths** (except when unavoidable)
- **No deadlocks** (simulation doesn't hang)
- **Consistent output** (proper timestamps and actions)
- **Memory safety** (no leaks, no crashes)

---

## 💡 Key Learning Objectives

- **Concurrent Programming**: Managing multiple threads safely
- **Synchronization Mechanisms**: Mutexes, locks, and critical sections
- **Deadlock Prevention**: Understanding and avoiding circular waiting
- **Race Condition Handling**: Atomic operations and thread safety
- **Resource Management**: Fair distribution and scheduling
- **Timing & Performance**: Precision timing and efficient algorithms
- **Problem Solving**: Classic computer science problem analysis

---

## 🚀 Advanced Concepts

### Deadlock Detection
The program implements sophisticated deadlock prevention:
- **Resource ordering**: Consistent fork acquisition order
- **Timeout mechanisms**: Prevent infinite waiting
- **State monitoring**: Track philosopher states

### Performance Optimizations
- **Minimal critical sections**: Reduce lock contention
- **Efficient time tracking**: Optimized timing functions
- **Smart thread management**: Proper thread lifecycle

---

## 🔍 Debugging Tips

1. **Use timing analysis**: Check for timing-related issues
2. **Monitor thread states**: Track philosopher states carefully
3. **Test edge cases**: Single philosopher, tight timings
4. **Check for data races**: Use thread sanitizers
5. **Validate mutex usage**: Ensure proper lock/unlock pairs

---

## 🎯 Philosophy Behind the Project

This project teaches fundamental concepts in concurrent programming:

- **Resource contention**: Multiple processes competing for limited resources
- **Synchronization**: Coordinating multiple threads safely
- **Fairness**: Ensuring equal access to shared resources
- **Efficiency**: Balancing safety with performance
- **Real-world applications**: Understanding systems programming challenges

---

*Made with ❤️ at 42 Madrid*
