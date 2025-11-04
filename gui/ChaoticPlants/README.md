# Chaotic Plants Nursery Simulation GUI

A Qt-based graphical user interface that simulates the operation of a plant nursery with customers represented as blue moving dots.

## Features

- **Visual Simulation**: Customers are displayed as blue dots that move around the nursery floor
- **Real-time Updates**: The simulation updates at 20 FPS (every 50ms)
- **Interactive Controls**: Start, pause, reset, and manually add customers
- **Status Display**: Shows the current number of active customers and simulation status
- **Nursery Layout**: Visual representation of key areas:
  - Entrance (green, bottom-left)
  - Info Desk (blue, top-center)
  - Checkout (orange, bottom-right)

## Building the Application

### Prerequisites
- Qt5 or Qt6
- CMake 3.16 or higher
- C++17 compatible compiler

### Build Steps

```bash
cd gui/ChaoticPlants
mkdir -p build
cd build
cmake ..
make -j4
```

## Running the Simulation

```bash
cd gui/ChaoticPlants/build
./ChaoticPlants
```

## How to Use

1. **Start Simulation**: Click the "Start Simulation" button to begin
   - Customers will automatically spawn every 3 seconds
   - Each customer appears as a blue dot at the entrance

2. **Add Customer**: Click "Add Customer" to manually spawn a customer
   - Can be used while simulation is running or paused

3. **Pause**: Click "Pause" to temporarily stop the simulation
   - Customer positions are frozen
   - Auto-spawning stops

4. **Reset**: Click "Reset" to clear all customers and return to initial state
   - Removes all customer visuals
   - Resets the backend nursery state

## Customer Behavior

- **Movement**: Customers move continuously toward random target positions
- **Speed**: Movement speed is set to 2 pixels per frame
- **Pathfinding**: When a customer reaches their target, they pick a new random location
- **Boundaries**: Customers stay within the visible nursery area

## Technical Details

### Architecture
- **Frontend**: Qt-based GUI (`NurseryWindow` class)
- **Backend**: Integration with existing nursery simulation system (`Nursery` class)
- **Separation**: GUI class renamed to `NurseryWindow` to avoid naming conflicts

### Key Components
- `NurseryWindow`: Main window and simulation controller
- `CustomerVisual`: Structure tracking visual representation and movement
- `Nursery` (backend): Manages actual customer logic, inventory, and staff

### Simulation Parameters
- Scene size: 800x600 pixels
- Customer size: 20x20 pixels
- Movement speed: 2 pixels/update
- Update rate: 50ms (20 FPS)
- Auto-spawn interval: 3 seconds

## Current Limitations

- Staff are not yet visualized (backend integration only)
- Customer states (browsing, enquiring, purchasing) not visually differentiated
- No visual representation of plant inventory or stock
- Customers don't yet depart automatically (future enhancement)

## Future Enhancements

- Visualize staff members with different colors
- Show customer states with different colors or icons
- Display plant stock and greenhouse areas
- Add customer-staff interaction animations
- Implement customer departure after completing actions
- Add zoom and pan controls for the view
