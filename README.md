# 🩸 Silent Hill 1 PC - Nightmare Mode Overhaul

An authentic Survival Horror Difficulty & Immersion Overhaul for the **Silent Hill 1 PC Port (SilentHillPC)**.

---

## 📥 Installation Guide

### Option 1: Via Mod Manager (Recommended)
1. Download **Nightmare_Mode_v1.0_Release.zip** from the Releases section.
2. Extract the zip into your game's **mods** folder:
   - Target: mods/Nightmare_Overhaul_Mod/plugins/nightmare_mode.dll
3. Open the **Launcher**, go to the **Mod Manager** tab, check **Nightmare Mode Overhaul**, and click **Apply**.
4. Start the game and select **New Game**!

---

### Option 2: Manual Installation (Direct)
1. Download **Nightmare_Mode_v1.0_Release.zip** and extract it.
2. Copy **nightmare_mode.dll** directly into your game's **plugins** folder:
   - Target: plugins/nightmare_mode.dll
3. Start **SilentHillPC.exe** and select **New Game**!

---

## 🎮 What's Included

- 💀 **2x Combat Damage**: High-stakes combat where every encounter demands respect.
- 🏃 **Aggressive Stalker Speed**: Grey Children and Mumblers move 50% faster in school corridors.
- 🎯 **Refined Enemy AI**: Fixed jittering and dancing in Split Head, nurses, and doctors.
- ⏱️ **Real-Time Inventory & Map**: The world keeps running while browsing your items or checking your map (*Can be toggled in Options -> PC Options*).
- 💓 **Dynamic Heartbeat Vignette**: SH2 Remake inspired pulsing low-health edge vignette (*Can be toggled in Options -> PC Options*).
- 🧪 **Twinfeeler Acid Poisoning**: Acid spit causes toxic poisoning cured by First Aid Kits or Ampoules.
- 🌧️ **Atmospheric Darkness & Rain**: Heavy rain and dark atmospheric Otherworld ambience across town.
- 🕹️ **Revamped Controller Menu**: Modern 2-pane interactive keyboard and gamepad rebinding.

---

## ⚙️ In-Game Options

You can customize your experience at any time from the in-game menu:
- Go to **Options** -> **Screen Position (PC Options)** -> **Page 2 (System)**
- **Live_Game**: ON / OFF *(Enable or disable real-time inventory)*
- **Low_Health_FX**: ON / OFF *(Enable or disable pulsing low-health vignette)*

## 🧠 Design Philosophy: Why Predictive AI Was Removed

During development, experimental predictive lead targeting (extrapolating Harry's velocity vector to intercept him) was tested. However, it has been **completely removed** in favor of authentic engine navigation:

- **State Machine Integrity**: In the original PSX engine, enemy state machines, turn rates, and attack wind-ups are tuned around exact trigonometric relative angles.
- **Elimination of Pathing Glitches**: Velocity prediction caused discrete fixed-point limit cycles (enemies oscillating back-and-forth near thresholds or walking endlessly into collision hulls).
- **Authentic Difficulty**: The overhaul achieves intense difficulty through higher aggression, increased movement velocity, lethal damage scaling, and atmospheric tension without breaking core PSX pathfinding mechanics.

---

## 📜 License
MIT License - Developed by **WhoisMiau0x1**
