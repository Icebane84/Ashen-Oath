# MRA-001: Module Readiness Assessment

**Standard:** MRA-001  
**Status:** CANONICAL / FROZEN  
**Revision:** 1.0.0  
**Parent Standard:** [`PMIP-001`](file:///c:/Users/Chris/Synarche_Workspace/docs/00_ARCHITECTURE/PMIP-001_Phoenix_Modularization_and_Integration_Protocol.md)  
**Domain:** Systemic Triage & Prototype Ingestion  

---

## 1. Purpose & Scope

The Module Readiness Assessment (MRA-001) provides a deterministic, 12-point audit checklist for evaluating whether an independently developed gameplay prototype or vertical slice can be safely enclosed by a `VSRP-001` adapter and assimilated into the production runtime.

---

## 2. The 12-Point Readiness Checklist

Before authoring an adapter or attempting runtime integration, the architect or AI agent must evaluate the prototype against these 12 criteria:

| # | Check Item | Evaluation Question |
| :---: | :--- | :--- |
| **1** | **Initialization Isolated** | Can the prototype's state machine be instantiated on demand without relying on DOM load events? |
| **2** | **Reset Possible** | Can the prototype be returned to its baseline state cleanly without reloading the web page or restarting the host process? |
| **3** | **Update Loop Identifiable** | Is the core simulation tick cleanly callable with an external delta time ($\Delta t$), free from unmanaged `requestAnimationFrame` loops? |
| **4** | **Rendering Separable** | Can the mathematical simulation run headless without throwing errors if a graphical canvas/renderer is not attached? |
| **5** | **Input Dependencies Identified** | Are all keyboard, mouse, or gamepad triggers known and map-able to the 10-bit `InputActions` bitmask? |
| **6** | **Global State Identified** | Are all mutable variables confined within an instance or closure, rather than polluting `window.*` or global namespace? |
| **7** | **External Dependencies Identified** | Does the prototype avoid unmanaged external CDN scripts, network sockets, or remote font loaders? |
| **8** | **Side Effects Identified** | Are file I/O, audio playback, and storage writes interceptable by the adapter? |
| **9** | **Events Identifiable** | Can key gameplay transitions (e.g. hit landed, poise broken, lens selected) emit events to an external subscriber? |
| **10** | **State Extractable** | Can the authoritative gameplay metrics be read synchronously via a pure data getter (`getState()`)? |
| **11** | **Timing Model Understood** | Is the prototype's physics/math stable at a fixed 60Hz step ($\Delta t = 0.01667\text{s}$)? |
| **12** | **Cleanup Possible** | Does the prototype have a teardown path that clears timers, event listeners, and WebGL/audio contexts? |

---

## 3. Triage Verdicts

Based on the 12-point evaluation, every prototype receives one of three formal classifications:

```text
       ┌───────────────────────────────────────────────┐
       │     MRA-001 MODULE READINESS ASSESSMENT       │
       └───────────────────────┬───────────────────────┘
                               │
            ┌──────────────────┼──────────────────┐
            ▼                  ▼                  ▼
      [🟢 GREEN]          [🟡 YELLOW]        [🔴 RED]
     Adapter-Ready      Seams Required    Reconstruction
```

### 🟢 GREEN: Adapter-Ready
* **Condition:** 10 to 12 checks pass cleanly.
* **Action:** Enclose prototype immediately with a `VSRP-001` adapter. Zero modifications to prototype source code required.

### 🟡 YELLOW: Seam Extraction Required
* **Condition:** 7 to 9 checks pass; minor blockers present (e.g., hardcoded `requestAnimationFrame` or variables bound to `window`).
* **Action:** Refactor prototype entry points slightly to extract the update loop and input listeners, then proceed with adapter.

### 🔴 RED: Architectural Reconstruction Required
* **Condition:** $\le 6$ checks pass; deeply tangled asynchronous code, unmanaged global state, or non-deterministic timing loops.
* **Doctrine:** **RED does not mean failure.** It is an honest, objective determination that the prototype cannot be safely enclosed as-is. The prototype serves as an aesthetic and mathematical reference while the logic is rebuilt natively under `IVSRPModule`.
