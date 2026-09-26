# 🌑 Silent Hill 1 PC — Nightmare Mode Overhaul

An authentic Survival Horror Difficulty & Immersion Plugin for the **Silent Hill 1 PC Port (`SilentHillPC`)**.

---

## 📦 Downloads & Packages

| Package | Contents | Description |
| :--- | :--- | :--- |
| **`Nightmare_Mode_v1.3.4.zip`** | `plugins/nightmare_mode.dll`, `mod.json` | Standalone C Plugin for Silent Hill PC Port. |

---

## 🚀 Installation Guide

### Option 1: Direct Plugin Install (Recommended)
1. Download **`Nightmare_Mode_v1.3.4.zip`**.
2. Copy `nightmare_mode.dll` into your game's `plugins/` directory:
   ```text
   SilentHillPC/
   ├── SilentHillPC.exe
   ├── config.cfg
   └── plugins/
       └── nightmare_mode.dll
   ```
3. Open `config.cfg` and make sure plugins are enabled:
   ```ini
   enable_plugins = 1
   ```
4. Run `SilentHillPC.exe`!

---

### Option 2: Via Mod Manager
1. Extract **`Nightmare_Mode_v1.3.4.zip`** into your game's `mods/` directory.
2. Open `SilentHillPC_Launcher.exe`, go to the **Mod Manager** tab.
3. Check **Nightmare Mode** and click **Apply** / **Play**.

---

## 🎮 Features

- 💀 **2x Combat Damage**: High-stakes combat where every encounter demands careful positioning and resource management.
- ⚡ **1.8x Stalker Speed Boost**: Grey Children, Mumblers, and Stalkers pursue Harry with 1.8x movement and synchronized animation speed.
- 👻 **Translucent Shadow Stalkers**: School enemies (Grey Children & Mumblers) spawn as ominous translucent shadow stalkers rendered with subtractive material blending.
- 🌧️ **Atmospheric Darkness & Heavy Rain**: Enforces perpetual Otherworld darkness, storm rain, and active flashlight across town.
- 🩸 **Dynamic Low-Health Heartbeat Vignette**: Pulsing blood-red edge vignette synchronized with player heartbeat when health drops to critical levels.
- 📻 **Radio Frequency & Pitch Distortion**: Low player health destabilizes the pocket radio with pitch wobbles and acoustic interference.
- ⏱️ **Real-Time World Simulation**: Enemies continue to advance and stalk Harry in real time while navigating inventory or maps (*Configurable*).
- 🎛️ **In-Game Settings Menu**: Press **N** or **F7** at any time to open the live configuration overlay.

---

## ⚙️ In-Game Configuration

Press **N** or **F7** during gameplay to toggle real-time options:
- **`LIVE_GAME`**: Enable/disable real-time NPC simulation while in inventory/map screens.
- **`LOW_HEALTH_FX`**: Enable/disable the pulsing blood-red edge vignette.

---

## 📜 License
MIT License — Developed by **WhoisMiau0x1**
