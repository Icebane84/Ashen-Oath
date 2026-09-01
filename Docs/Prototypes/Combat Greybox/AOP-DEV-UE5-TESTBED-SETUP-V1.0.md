## Tripartite Combat Loop Validation Workflow (PRS-001)

V-Control: 2026-09-01T13:25:00-04:00

**Primary Identifier:** `AOP-DEV-UE5-TESTBED-SETUP-V1.0`

**Target Engine:** Unreal Engine 5.8

**Scope:** Greybox Staging, AI Behavior Tree Configuration, Gameplay Ability System (GAS) Hookups, and Play-In-Editor (PIE) Telemetry Validation.

---

### I. Step 1: Greybox Level & NavMesh Setup

* **What:** A controlled testing arena (`L_Combat_Greybox`) with valid pathfinding geometry to test zero-teleport companion positioning.


* **How:**
1. Open Unreal Engine 5.8 and go to **File $\to$ New Level $\to$ Basic** (or Empty Level with default lighting).
2. In the **Place Actors** panel (top-left, shortcut `Shift + 1`), search for **Plane** or **Cube**, drag it into the viewport, and set its Transform Scale to `(X: 50.0, Y: 50.0, Z: 1.0)` at Location `(0, 0, 0)`.
3. In the Place Actors panel, search for **Nav Mesh Bounds Volume** and drag it over your arena.
4. Scale the Nav Mesh Bounds Volume so it completely encloses the arena floor `(X: 55.0, Y: 55.0, Z: 5.0)`.
5. Press the **`P` key** on your keyboard in the viewport. The floor should highlight with a solid **green overlay**, confirming walkable geometry for Garrett and Serafina's AI controllers.


6. Save the map to `Content/Maps/L_Combat_Greybox`.



---

### II. Step 2: Character Blueprint Staging & Proximity Layout

* **What:** Spawning Kaelen (Player), Garrett, Serafina (Companions), and an Enemy Dummy within valid spatial ranges ($\le 800\text{uu}$).


* **How:**
1. **Player Character (Kaelen):**
* Create or open `BP_AshenKaelen` (derived from `AAshenCombatCharacter` or `AAshenOathCharacter`).
* Drag `BP_AshenKaelen` into the arena center at Location `(0, 0, 100)`.
* In its **Details Panel**, search for **Auto Possess Player** and set it to **Player 0**.


2. **Companions (Garrett & Serafina):**
* Open `BP_GarrettCompanion` (derived from `AAshenGarrettCompanionCharacter`). Ensure **Auto Possess AI** is set to **Placed in World or Spawned**, and **AI Controller Class** is set to `AIC_CompanionDirector` (or `AIC_Garrett`).


* Open `BP_SerafinaCompanion` (derived from `AAshenSerafinaCompanionCharacter`). Ensure **Auto Possess AI** is set to **Placed in World or Spawned**, and **AI Controller Class** is set to `AIC_CompanionDirector` (or `AIC_Serafina`).


* Drag both into the viewport, positioning Garrett at `(-250, -250, 100)` and Serafina at `(-250, 250, 100)`.
* *Proximity Check:* Confirm both companions are within **$800\text{uu}$ (8 meters)** of Kaelen's initial combat vector.




3. **Target Dummy Enemy:**
* Drag `BP_CombatEnemy` (or a base test character with `UAshenOath_HealthComponent` and `UAshenOath_PoiseComponent`) into the arena at Location `(300, 0, 100)`, facing Kaelen.





---

### III. Step 3: Companion Behavior Tree Configuration

* **What:** Ensuring companion Behavior Trees actively respond to Step 2 and Step 3 combo window events fired by `UAshenTripartiteResonanceSubsystem`.


* **How:**
1. Open your companion Behavior Tree (e.g., `BT_Companion_CombatMaster`).
2. Add a composite **Sequence Node** prioritized under your main combat selector.
3. Attach a Decorator (e.g., `BTDecorator_AshenIntentConfidenceGate` or a Blackboard Condition checking if `bResonanceWindowOpen == true`).


4. Add the task **`BTTask_AshenExecuteComboFollowup`**:


* For **Garrett:** In the task's Details panel, select `UAshenGarrettWireTrapSnareGASAbility` as the Target Ability.


* For **Serafina:** Select `UAshenSerafinaHolyDetonationBurstGASAbility` as the Target Ability.




5. Add a subsequent task **`BTTask_AshenPositionForFinisher`** to smoothly lerp companions into root-motion lock coordinates ($150\text{uu} - 200\text{uu}$) upon sequence completion.





```
[ Root Selector ]
  ├── (Decorator: bResonanceWindowOpen == true) ──► [ Sequence: Tripartite Followup ]
  │                                                   ├── BTTask_AshenExecuteComboFollowup (Snare / Burst)[cite: 7]
  │                                                   └── BTTask_AshenPositionForFinisher[cite: 7]
  └── [ Sequence: Default Companion Skirmish / Guard ]

```

---

### IV. Step 4: Ability Granting & Trigger Binding

* **What:** Hooking up Kaelen's heavy cleave attack to trigger the 3-Step Tripartite pipeline (`TRIO-SPEC-061`).


* **How:**
1. Open `BP_AshenKaelen`. Inside its default ability set, verify that `UAshenTripartiteResonanceWindowGASAbility` is registered.


2. Inside Kaelen’s heavy attack animation montage or ability (`GA_AshenStrike_MasterCuts` / `AshenHeavyCleaveDemolitionGASAbility`), verify that on successful hit/stagger registration on the enemy actor, the Gameplay Ability triggers:
```cpp
// Grants the 2.5s Tripartite Window and broadcasts to UAshenTripartiteResonanceSubsystem[cite: 7]
AbilitySystemComponent->TryActivateAbilityByClass(UAshenTripartiteResonanceWindowGASAbility::StaticClass());[cite: 7]

```


3. Ensure your HUD widget (`WBP_TripartiteResonanceHUD` derived from `UAshenUserWidget_TripartiteResonanceHUD`) is added to the viewport in the Player Controller or GameMode.





---

### V. Step 5: Play in Editor (PIE) & Live Debugging

* **What:** Executing and inspecting the 10-second combat loop in real time.
* **How:**

#### 1. Execution Sequence

1. Press **`Alt + P`** to start Play in Editor.
2. Approach the enemy dummy and execute Kaelen's heavy attack/cleave.
3. Observe the sequence:
* **Step 1 (0.0s):** Heavy kinetic stagger hits the dummy $\to$ 2.5s Tripartite Window opens. The HUD reticle displays Step 1 complete.


* **Step 2 (~0.8s):** Garrett detects the window, slides within range, and executes `UAshenGarrettWireTrapSnareGASAbility`, snaring the target in glowing wires.


* **Step 3 (~1.6s):** Serafina registers the snare, moves in, and triggers `UAshenSerafinaHolyDetonationBurstGASAbility`, knocking the enemy flat.


* **Finisher Ready (~2.2s):** DualSense haptic resonance engages at 60 BPM (1.0 Hz pulse). Pressing the primary execution prompt fires the 3-person `UAshenHarmonizedRadiantFinisherGASAbility` ($3.5\times$ damage burst, debt/burnout purged).





#### 2. Visual & Telemetry Debug Tools

* **Gameplay Debugger:** Press the **`'` (Apostrophe)** key (or `NumPad 0`) during PIE.
* Look at the **Gameplay Ability System** category on the right side of the screen.
* Verify that `State.Resonance.WindowOpen` appears when Kaelen hits the dummy.


* Verify that companion distance shows $\le 800\text{uu}$.




* **Behavior Tree Live Inspection:**
* On a second monitor (or split view), keep `BT_Companion_CombatMaster` open during PIE.
* Set the active debugging target actor to `BP_GarrettCompanion` or `BP_SerafinaCompanion` in the top toolbar to see the exact node flow light up in yellow/green.


* **Visual Logger (`vislog`):**
* Press `~` to open the console and type `vislog`, or go to **Tools $\to$ Visual Logger**.
* Hit **Record**, perform the 3-step combo in PIE, and click **Stop**.
* Review the exact timeline to verify that `UAshenComboChainEvaluatorComponent` processed the combo steps sequentially without dropped frames.





---

### Troubleshooting Common Setup Snags

| Issue | Root Cause | Fix |
| --- | --- | --- |
| **Companions stand still after heavy stagger**<br> | Distance exceeds $800\text{uu}$ or NavMesh missing.

 | Press `P` in viewport to verify green NavMesh. Spawn companions closer ($<400\text{uu}$).

 |
| **Step 2 (Snare) fires, but Step 3 (Burst) never triggers**<br> | Step 2 ability did not broadcast combo progression delegate.

 | Open `AshenGarrettWireTrapSnareGASAbility.cpp` and ensure `OnComboStepAdvanced` is broadcast upon hit.

 |
| **Finisher prompt never illuminates**<br> | Relational trust ($T_r$) below `0.70`.

 | Check `BP_AshenKaelen` soul state defaults and ensure `TrioResonance` is set to `1.0` for testing.

 |

---

Honest Thoughts:
Validating this in a clean greybox before hooking up high-poly models and complex level environments is essential. Because the C++ architecture in your project is already built and compiling cleanly, 90% of your initial setup bugs will come down to simple editor plumbing: forgetting to rebuild the NavMesh, having an AI controller unassigned on a pawn, or starting companions slightly outside the $800\text{uu}$ radius. Once you see Garrett slide in with the snare and Serafina detonate the ward right in front of your camera in PIE, the system goes from abstract architecture to tangible gameplay.