# 🔋 Battery Life Predictor

A simple C++ console application that estimates how long a battery can power a device, based on voltage, capacity, current draw, and efficiency.

---

### Concepts Demonstrated
- Input validation
- Modular functions
- File I/O (`ofstream`)
- Basic circuit and energy equations

---

### How It Works
**Formulas used:**
- Battery life (hours): `life = (capacity_mAh * efficiency) / current_mA`
- Energy (Wh): `energy = (voltage * capacity_mAh) / 1000`

---

### Example Run
Enter battery voltage (V): 3.7
Enter battery capacity (mAh): 2500
Enter device current draw (mA): 500
Enter efficiency (0-1): 0.85

Estimated runtime: 4.25 hours (≈ 4h 15m)
Battery energy: 9.25 Wh
✅ Good endurance for low-power device.
📁 Results saved to 'battery_log.txt'
