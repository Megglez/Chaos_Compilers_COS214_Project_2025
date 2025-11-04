# Chaotic Plants
<p>Step into a world bursting with life in this simulation game where you can manage your very own plant nursery, inspired by the vibrant growth of spring, you are in complete control of a bustling green enterprise!</p>

## GitHub and Google Doc Report

https://docs.google.com/document/d/1pNxXny8WA27NGEMK5c35jEXHrr4iKFu1k3Qw_p5Tn5Q/edit?usp=sharing

https://github.com/Megglez/Chaos_Compilers_COS214_Project_2025

## Documentation

* [Report](https://github.com/Megglez/Chaos_Compilers_COS214_Project_2025/blob/Documentation/Report.md)
* [README](https://github.com/Megglez/Chaos_Compilers_COS214_Project_2025/blob/main/README.md)

## Compiling and Running Chaotic Plants
### Prerequisites

Before building and running Chaotic Plants, ensure you have the following installed:

- **CMake** (version 3.16 or higher)
- **Qt5** or **Qt6** (Core and Widgets modules)
- **C++ Compiler** with C++17 support (g++, clang++)
- **Make** build system

### Installation Instructions

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install cmake build-essential qt5-default qtbase5-dev
```

#### Fedora/RHEL
```bash
sudo dnf install cmake gcc-c++ qt5-qtbase-devel
```

#### macOS
```bash
brew install cmake qt@5
```

### Building the Project

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Megglez/Chaos_Compilers_COS214_Project_2025.git
   cd Chaos_Compilers_COS214_Project_2025
   ```

2. **Build Using Makefile (Recommended)**
   ```bash
   make
   ```
   This will:
   - Build the GUI application in `gui/ChaoticPlants/build/`
   - Compile all source files
   - Link Qt libraries
   - Generate the executable

3. **Alternative: Build Using CMake Directly**
   ```bash
   cd gui/ChaoticPlants
   mkdir -p build
   cd build
   cmake ..
   make
   ```

### Running the Application

After building, run the application with:

```bash
# From the project root directory
cd gui/ChaoticPlants/build
./ChaoticPlants
```

Or use the makefile target:
```bash
make run
```

### Running Unit Tests

To build and run the unit test suite:

```bash
# Build tests
make unit_tests

# Run tests
./run_tests
```

Or from the build directory:
```bash
cd build
cmake ..
make
./run_tests
```

### Project Structure

```
Chaos_Compilers_COS214_Project_2025/
├── src/                    # Source code
│   ├── Customer/          # Customer management
│   ├── Greenhouse/        # Plant and inventory systems
│   ├── Nursery/          # Main facade and GUI
│   └── Staff/            # Staff and iterator pattern
├── gui/ChaoticPlants/    # Qt GUI application
├── tests/                # Unit tests
├── CMakeLists.txt        # CMake configuration
├── makefile              # Build automation
└── README.md             # This file
```

### Troubleshooting

**Qt Libraries Not Found**
```bash
# Set Qt path explicitly
export CMAKE_PREFIX_PATH=/path/to/qt5
cmake ..
```

**Build Errors**
```bash
# Clean build
make clean
make
```

**Permission Denied**
```bash
# Make executable runnable
chmod +x gui/ChaoticPlants/build/ChaoticPlants
```

### Features

- **Plant Nursery Simulation** - Manage a virtual plant nursery
- **Customer Management** - Handle customer arrivals and requests
- **Seasonal Changes** - Plants adapt to different seasons
- **Staff Management** - Assign staff to assist customers
- **Iterator Pattern** - Process customer queues efficiently
- **Real-time Updates** - Clock-based event system

## Technologies

<p align="center">
 <img width="50" height="65" alt="C++" src="https://github.com/user-attachments/assets/d10c8289-d73d-4c46-9d0d-7c12a9a70bcd" />
 <img width="65" height="45" alt="QT" src ="https://github.com/user-attachments/assets/945aba5e-c0fe-437b-ade5-6417aa04ba18" />
</p>


## Chaos Compilers Crew

| Name | GitHub | LinkedIn | Description |
|:------|:-----:|:-----:|:------|
| Megan Lai | [![GitHub](https://github.com/user-attachments/assets/050f18aa-f67f-4341-aa21-d31e286f71e6)](https://github.com/Megglez)| [![LinkedIn](https://github.com/user-attachments/assets/efe5faca-b4f1-4708-9e15-d1999d78c77c)](https://www.linkedin.com/in/megan-lai-720685368/) |Team Lead, Code Implementation, Documentation, GitHub|
| Inge Keyser | [![GitHub](https://github.com/user-attachments/assets/050f18aa-f67f-4341-aa21-d31e286f71e6)](https://github.com/IngeKeyser) | [![LinkedIn](https://github.com/user-attachments/assets/efe5faca-b4f1-4708-9e15-d1999d78c77c)](https://www.linkedin.com/in/inge-keyser)|Code Implementation |
| Blessing Gibendi | [![GitHub](https://github.com/user-attachments/assets/050f18aa-f67f-4341-aa21-d31e286f71e6)](https://github.com/u24827313) | [![LinkedIn](https://github.com/user-attachments/assets/efe5faca-b4f1-4708-9e15-d1999d78c77c)]() |Code Implementation |
| Divo Köhler | [![GitHub](https://github.com/user-attachments/assets/050f18aa-f67f-4341-aa21-d31e286f71e6)](https://github.com/u24607526) | [![LinkedIn](https://github.com/user-attachments/assets/efe5faca-b4f1-4708-9e15-d1999d78c77c)](http://www.linkedin.com/in/divo-kohler-1023b6397) |Code Implementation, Documentation |
| Langa Vakalisa | [![GitHub](https://github.com/user-attachments/assets/050f18aa-f67f-4341-aa21-d31e286f71e6)](https://github.com/langa-vk)| [![LinkedIn](https://github.com/user-attachments/assets/efe5faca-b4f1-4708-9e15-d1999d78c77c)]() |Code Implementation | 


