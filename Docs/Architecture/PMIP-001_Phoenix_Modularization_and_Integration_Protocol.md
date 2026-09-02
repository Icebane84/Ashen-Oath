# PMIP-001: Phoenix Modularization & Integration Protocol
## (Internal Designation: PSAP-001 — Phoenix System Assimilation Protocol)

**Standard:** PMIP-001 / PSAP-001  
**Status:** CANONICAL / FROZEN  
**Revision:** 1.0.0  
**Domain:** Macro-Systemic Architecture & Autonomous Agent Governance  
**Companion Standards:** [`VSRP-001`](file:///c:/Users/Chris/Synarche_Workspace/docs/00_ARCHITECTURE/VSRP-001_Universal_Module_Contract.md), [`MRA-001`](file:///c:/Users/Chris/Synarche_Workspace/docs/00_ARCHITECTURE/MRA-001_Module_Readiness_Assessment.md), [`MVP-001`](file:///c:/Users/Chris/Synarche_Workspace/docs/00_ARCHITECTURE/MVP-001_Module_Verification_Protocol.md)  

---

## 1. Executive Summary & Core Philosophical Breakthrough

The Phoenix Modularization & Integration Protocol (PMIP-001) defines the formal engineering methodology for turning independently developed, monolithic, or experimental game systems into verified, composable runtime modules without requiring them to have been architected together from the beginning.

### 🏛️ The Cardinal Law of Assimilation
> **"The legacy slice doesn't have to become modular. The adapter makes it modular from the outside."**

When building games with AI pair programmers, demanding that an agent *"build this entire game correctly according to our eventual macro-architecture"* guarantees context-window explosion, shallow mock boilerplate, and fragile code.

Instead, PMIP-001 mandates:
> **"Build an excellent, self-contained vertical slice according to its slice contract. Then make its external boundary VSRP-001 compliant via an enclosing adapter."**

### ⚠️ The Cardinal Rule of Integration
> **"Integration must never silently repair a module."**

If a module passes standalone verification but exhibits unexpected behavior when connected to the Master Orchestrator, **the orchestrator must never inject special-cased, silent workarounds**. The incompatibility must be explicitly triaged: either the module's contract/input chord is revised, or the integration layer is corrected, followed by an immediate regression pass.

---

## 2. The 10-Phase Assimilation Lifecycle

Every vertical slice progressing from raw prototype into the production runtime moves through 10 deterministic phases:

```text
PHASE 0 — CONTRACT (Define inputs, state, and expected events)
    ↓
PHASE 1 — BUILD (Develop isolated prototype or HTML/JS canvas sim)
    ↓
PHASE 2 — ISOLATE (Sever global DOM/window hooks and hardcoded assumptions)
    ↓
PHASE 3 — ASSESS (Execute MRA-001 12-point audit: Green / Yellow / Red)
    ↓
PHASE 4 — ADAPT (Wrap with VSRP-001 adapter, translating bitmasks & events)
    ↓
PHASE 5 — INSTRUMENT (Separate getState() authoritative data from getDiagnostics())
    ↓
PHASE 6 — VERIFY (Execute MVP-001 acceptance criteria in isolation)
    ↓
PHASE 7 — FREEZE (Lock module version and export Unreal Engine 5.8 C++ headers)
    ↓
PHASE 8 — INTEGRATE (Mount into MasterOrchestrator multi-module runtime)
    ↓
PHASE 9 — REGRESSION VERIFY (Execute Sentinel Suite Pass 7 Live Integration Loop)
```

---

## 3. Two First-Class Architectural Citizens

PMIP-001 recognizes two valid paths into the Phoenix runtime. **Neither path is inferior; both are first-class citizens**:

```text
                     VSRP-001 CONTRACT
                             │
              ┌──────────────┴──────────────┐
              │                             │
        Native Module                 Legacy Module
              │                             │
    Implements IVSRPModule        Raw HTML/JS Prototype
         directly                           │
              │                      VSRP-001 Adapter
              │                    (Encloses prototype)
              │                             │
              └──────────────┬──────────────┘
                             │
                     Master Orchestrator
```

1. **Native Modules:** Newly authored systems designed from day one to implement `IVSRPModule<TConfig, TState>`.
2. **Assimilated Legacy Modules:** Monolithic prototypes (e.g. Claude/Gemini generated single-file HTML simulations) enclosed by a TypeScript adapter that bridges:
   - 10-bit bitmasked inputs (`InputActions`) $\to$ Legacy keys (`KeyD`, `Space`, `Click`).
   - Legacy callbacks (`onHit()`, `onStagger()`) $\to$ Semantic event bus tokens (`GameEvents.COMBAT_HIT_LANDED`).
   - Internal prototype variables $\to$ Immutable `getState()` snapshots.

---

## 4. Operational Boundaries

### A. Input Decoupling
The Master Orchestrator transmits inputs strictly as an immutable 10-bit bitmask (`context.input.currentMask`, `context.input.previousMask`). 
- Modules and adapters **must never** directly poll the DOM (`window.addEventListener('keydown')`) or hardware drivers directly during simulation ticks.
- The adapter translates bit positions into prototype-specific triggers.

### B. Event-Driven Cross-Wiring
Modules never hold direct pointers or call methods on other modules.
- Inter-system consequences (e.g., Combat heavy attack causing camera shake, dualsense rumble, and companion stagger) flow exclusively across `context.events.publish(token, payload)`.
- The Master Orchestrator buffers events published during `module.update(dt, context)` and flushes them deterministically at the sub-step boundary.

### C. Authoritative State vs. Telemetry Diagnostics
Every module enforces a strict separation:
- `getState()`: Returns the exact, authoritative gameplay data required for save states, network replication, and game rules (e.g. `health`, `poise`, `stance`, `stamina`).
- `getDiagnostics()`: Returns volatile profiling and debug telemetry (e.g. `drawCalls`, `fps`, `subTickLatencyMs`, `debugFlags`).

---

## 5. Provenance & Audit Trail

Every assimilated vertical slice must document its complete lineage in its source header:

```typescript
/**
 * VSRP-001 Assimilated Vertical Slice Adapter
 * Protocol: PMIP-001 / PSAP-001 (Phoenix System Assimilation Protocol)
 * Source Prototype: Docs/Prototypes/<name>.html
 * Readiness Assessment: MRA-001 [GREEN - Adapter Ready]
 * Verification: MVP-001 Verified via test_master_integration.ts (Pass 7 AFFIRMED)
 */
```
