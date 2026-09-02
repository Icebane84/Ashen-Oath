# MVP-001: Module Verification Protocol

**Standard:** MVP-001  
**Status:** CANONICAL / FROZEN  
**Revision:** 1.0.0  
**Parent Standard:** [`PMIP-001`](file:///c:/Users/Chris/Synarche_Workspace/docs/00_ARCHITECTURE/PMIP-001_Phoenix_Modularization_and_Integration_Protocol.md)  
**Domain:** Anti-Theater Quality Assurance & Autonomous Verification Gates  

---

## 1. Executive Mandate: Anti-Theater Verification

> **"We have no use for test theater."**

The Module Verification Protocol (MVP-001) outlaws decorative tests, static string checks, and superficial mock assertions. In the Phoenix Protocol and Ashen Oath ecosystems, **a module is never declared verified, canonical, or frozen unless its real gameplay logic and event cross-wirings are actively exercised under execution.**

---

## 2. Structure of Module Acceptance Criteria (`AC-***`)

Every vertical slice and assimilated adapter must be audited against explicit, verifiable criteria in its corresponding test harness or documentation.

Criteria must be written as objective, falsifiable assertions:

```markdown
### Acceptance Criteria Table

| ID | Title | Input / Trigger | Expected State Assertion | Pass/Fail Gate |
| :--- | :--- | :--- | :--- | :---: |
| **AC-001** | Attack Initiation | `mask & HEAVY_ATTACK` | `state.state === 'Attacking'` within 1 tick ($\le 16.7\text{ms}$) | PASS |
| **AC-002** | Contact Frame Event | Tick step 30 (500ms mark) | Emits exactly 1 `COMBAT_HIT_LANDED` event | PASS |
| **AC-003** | Poise Depletion | Consecutive cuts landed | `enemyPoise <= 0.0` triggers `COMBAT_POISE_BROKEN` | PASS |
| **AC-004** | Determinism Parity | 600 continuous ticks | Zero heap leaks, identical state vector across runs | PASS |
```

---

## 3. The 4 Verification Rules

### Rule 1: Live Multi-Adapter Integration (Pass 7 Gate)
Unit tests that only exercise an isolated mock class are insufficient. All assimilated vertical slices must participate in a live multi-adapter simulation harness (such as [`packages/isomorphic-orchestration/src/test_master_integration.ts`](file:///c:/Users/Chris/Synarche_Workspace/packages/isomorphic-orchestration/src/test_master_integration.ts)) where:
1. Inputs are chorded through the `MasterOrchestrator`.
2. Inter-module events flow through the buffered event bus.
3. Downstream hardware and simulation effects (e.g. DualSense trigger resistance, companion dialogue barks, NavMesh carving) are asserted against ground truth.

### Rule 2: Strict Fixed-Timestep Budget
Every module's `update(dt, context)` execution budget must strictly adhere to the 60Hz frame deadline:
$$\text{Execution Time} \le 16.6667\text{ms}$$
Any module that exceeds this threshold during sustained gameplay is rejected by Sentinel Core (`CODEX.LATENCY.003`).

### Rule 3: 600-Tick Determinism & Memory Stability
The module must be stepped through 600 consecutive ticks ($10.0$ seconds of simulated 60Hz time):
- Heap allocations during the steady-state loop must remain bounded.
- Zero `NaN` or unconstrained float values in the authoritative `getState()` snapshot.

### Rule 4: Unforgiving Verdicts
If even a single assertion fails:
```text
VERDICT: ADMONISH / FAIL
The module is NOT frozen. Silent fixes inside integration layers are strictly forbidden.
```
