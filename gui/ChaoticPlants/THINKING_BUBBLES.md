# Thinking Bubble Feature - User Guide

## Overview
Each customer in the nursery simulation now has a **thinking bubble** that appears above them, displaying detailed information about their current state, desired plants, and shopping preferences.

## How It Works

### Visual Indicators
- **Small White Bubble**: Always visible above each customer
- Indicates that the customer has thoughts/intentions
- Appears as a classic comic-style thought bubble (small dots leading to main bubble)

### Hover Interaction (When Paused)
When the simulation is **paused**, you can hover your mouse over any thinking bubble to see expanded information:

1. **Pause the simulation** (click "Pause" button)
2. **Hover** your mouse over a thinking bubble
3. An **information box** will expand, showing:
   - Customer ID
   - Current state (Browsing, Enquiring, or Purchasing)
   - Plants they're looking for
   - Quantity of each plant
   - Desired decorations (if any)
   - Current basket contents

### Information Displayed

#### For Browsing Customers
```
Customer #3

State: Browsing

Looking for:
  • 5 x Rose
    → Wants: Gift Wrap
  • 2 x Lavender
    → Wants: Pot
```

#### For Enquiring Customers
```
Customer #7

State: Enquiring

Asking about:
  Type: Advice Question
  Q: What plants are good for summer?
  • Sunflower
  • Cactus
```

#### For Purchasing Customers
```
Customer #12

State: Purchasing

Ready to checkout

Basket (7 items):
  • 5 x Rose
  • 2 x Lavender
```

## Customer States

### 1. Browsing
- Customer is looking at plants
- Shows which plants they want
- Displays quantities
- Shows if they want decorations:
  - **Gift Wrap**: Special wrapping
  - **Pot**: Plant in a pot
  - **Special Arrangement**: Custom arrangement

### 2. Enquiring
- Customer has questions
- Two types of questions:
  - **Advice Question**: General plant care, seasonal recommendations
  - **Information Question**: Stock availability queries
- Shows plants of interest

### 3. Purchasing
- Customer is ready to check out
- Shows basket contents
- Displays total number of items

## Decoration Types

Customers may want their plants decorated:

- **Gift Wrap** 🎁: Decorative wrapping for gifts
- **Pot** 🪴: Plant comes in a decorative pot
- **Special Arrangement** 💐: Custom floral arrangement

## Tips for Using This Feature

1. **Pause Before Hovering**: The expanded info box only appears when the simulation is paused
2. **Plan Customer Service**: See what customers need before they reach checkout
3. **Track Customer Intent**: Understand what brought them to the nursery
4. **Monitor Basket Changes**: See how customers' baskets fill up over time

## Technical Details

- Thinking bubbles move with their customers
- Bubble position: 30 pixels above customer dot
- Info box appears above and to the right of the bubble
- Info box auto-resizes based on content
- Bubbles are cleaned up when customers leave

## Why Pause-Only?

The hover expansion only works when paused because:
- Prevents information flickering during movement
- Gives you time to read customer details
- Makes the UI less cluttered during active simulation
- Allows focused analysis of customer behavior

## Example Workflow

1. Start simulation and let customers spawn
2. Watch them move around (thinking bubbles visible)
3. Pause the simulation
4. Hover over different customers to see:
   - What they're shopping for
   - Their current state
   - Their basket contents
5. Resume simulation to continue

This feature helps you understand the customer journey and make the simulation more informative and engaging!
