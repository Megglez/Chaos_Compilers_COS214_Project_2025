## Quick Reference: Chaotic Plants GUI

### Run the Application
```bash
cd gui/ChaoticPlants
./run.sh
```

OR

```bash
cd gui/ChaoticPlants/build
./ChaoticPlants
```

### Controls
- **Start Simulation**: Begin auto-spawning customers every 3 seconds
- **Pause**: Stop simulation and customer spawning
- **Reset**: Clear all customers and restart
- **Add Customer**: Manually add a customer (blue dot)

### What You'll See
- 🔵 **Blue Dots** = Customers moving around
- 🟢 **Green Box** = Entrance (bottom-left)
- 🔷 **Blue Box** = Info Desk (top-center)
- 🟠 **Orange Box** = Checkout (bottom-right)

### Customer Behavior
- Spawn at entrance
- Move to random locations
- Keep moving continuously
- Speed: 2 pixels/frame @ 20 FPS

### Files Modified/Created
```
gui/ChaoticPlants/
├── nursery.h          (updated - renamed to NurseryWindow)
├── nursery.cpp        (updated - full simulation logic)
├── nursery.ui         (updated - window properties)
├── main.cpp           (updated - uses NurseryWindow)
├── CMakeLists.txt     (updated - includes backend sources)
├── run.sh             (new - convenience script)
├── README.md          (new - user documentation)
└── IMPLEMENTATION.md  (new - technical details)
```

### Status Display
- **Customer Count**: Shows active customers (top of window)
- **Status**: Shows "Ready", "Running", or "Paused"

### Technical Details
- Scene Size: 800x600 pixels
- Customer Size: 20x20 pixels
- Update Rate: 50ms (20 FPS)
- Spawn Rate: 3 seconds
- Max Customers: 20 (backend limit)

### Notes
- Staff are NOT visualized (backend only, as requested)
- Customers don't depart automatically yet
- Some console warnings are normal (Qt threading)
