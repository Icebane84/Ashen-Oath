# PRS-001-CDTC-001: COMBAT DETERMINISM & TEMPORAL CONTRACT

**Canonical Document Identifier:** `PRS-001-CDTC-001`  
**Parent Specifications:** `PRS-001-SPEC-COMBAT-104-HARDENED`, `PRS-001-REV-SOPHIA-ANALYSIS-105`, `CONVERGENCE-SPEC-101`  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Quartz / Chaos  
**Authority Level:** Canonical Production Implementation Contract (CDTC-001)  
**V-Control:** 2026-08-30T23:45:00Z  

---

## 🏛️ I. Combat Determinism & Temporal Contract (CDTC-001)

### What

`PRS-001-CDTC-001` establishes the definitive, frame-accurate execution contract for *Ashen Oath*. It defines:

1. The **Montage-Track Position Traversal Equation** ($P_{montage}$) for hit-stop and slomo-immune Flow Glint timing.
2. The **9-Stage Intra-Frame Transaction Order** guaranteeing zero race conditions between damage, stamina, and flow state.
3. The **Spatial Convex Hull Evaluator** replacing flat distance checks with directional vector analysis.
4. The C++ interface definitions, state structs, and automated validation tests required for Unreal Engine 5.8.

---

## ⏱️ II. Authoritative Temporal Traversal & Math

### 1. Authoritative Montage-Track Position Equation

Combat timing authority is anchored to the active `UAnimMontage` instance. Rather than tracking elapsed world time ($\Delta t_{world}$), the engine calculates the exact position on the montage timeline ($P_{montage}$) in seconds:

$$P_{montage}(t) = P_{montage}(t - \Delta t) + (\Delta t_{effective} \times \text{MontagePlayRate})$$

Where:

* $\Delta t_{effective}$: Frame delta time after world dilation and hit-stop freezing are applied by the engine tick. If hit-stop is active ($\Delta t_{effective} = 0$), $P_{montage}$ does not advance.
* $\text{MontagePlayRate}$: The local playback multiplier of the montage (e.g., $1.25\times$ during Flow state).

The **$0.15\text{s}$ Flow Glint Window** is evaluated strictly as an open interval on the montage track:

$$\text{WindowActive} \iff P_{apex} \le P_{montage}(t) < (P_{apex} + W_{local})$$

* $P_{apex}$: Timestamp of `AnimNotify_FlowApex` placed on the attack montage track (in seconds).
* $W_{local}$: The normalized window duration ($0.15\text{s} \div \text{MontagePlayRate}$).

---

## ⚙️ III. Deterministic 9-Stage Intra-Frame Transaction Pipeline

```
┌────────────────────────────────────────────────────────────────────────────────────────┐
│                      DETERMINISTIC 9-STAGE FRAME TRANSACTION PIPELINE                  │
└───────────────────────────────────────────┬────────────────────────────────────────────┘
                                            │
  ┌─────────────────────────────────────────┼─────────────────────────────────────────┐
  ▼                                         ▼                                         ▼
[ STAGE 1: INPUT NORMALIZATION ]  [ STAGE 2: KINEMATICS & COLLISION ] [ STAGE 3: DAMAGE & POISE ]
• Register directional intent     • Sweep hitboxes/hurtboxes          • Deduct Health/Poise envelopes
• Strict 0ms latency buffer       • Resolve parry/deflection lines    • Apply Stagger thresholds
  │                                         │                                         │
  └─────────────────────────────────────────┼─────────────────────────────────────────┘
                                            ▼
  ┌─────────────────────────────────────────┼─────────────────────────────────────────┐
  ▼                                         ▼                                         ▼
[ STAGE 4: FLOW GLINT POSITION ]  [ STAGE 5: SPATIAL VECTOR EVAL ]    [ STAGE 6: ATOMIC DELTA COMMIT ]
• Query P_montage track position  • Evaluate companion convex hull    • Validate invariants & bounds
• Output: Early/Perfect/Late      • Reject invalid lines of sight     • Write to state transaction
  │                                         │                                         │
  └─────────────────────────────────────────┼─────────────────────────────────────────┘
                                            ▼
  ┌─────────────────────────────────────────┼─────────────────────────────────────────┐
  ▼                                         ▼                                         ▼
[ STAGE 7: STATEVERSION INCREMENT ] [ STAGE 8: SNAPSHOT BROADCAST ]    [ STAGE 9: PRESENTATION DERIVE ]
• Monotonic tick: N ──► N+1       • Immutable broadcast to observers  • BlendSpaces, MetaSounds,
• Commit schema hash              • GAS GameplayTags, AI StateTrees   • Shaders, DualSense triggers
```

### Stage Execution Invariants

* **Invariant I (Zero Upward Contamination):** Stage 9 systems (Actuators, MetaSounds, Shaders, Haptics) are strictly prohibited from writing to or modifying Stages 1–7 during the same frame.
* **Invariant II (Single Delta Commit):** Only Stage 6 may mutate `FSoulStateVector` and `FRelationalMatrix_V2`.
* **Invariant III (Version Monotonicity):** Every successful commit increments `uint64 StateVersion` by exactly `1`.

---

## 📐 IV. Companion Spatial Convex Hull Evaluator

Synergy validity is evaluated as a composite boolean:

$$\text{SynergyValid} \iff (\Vert{}\mathbf{v}_{\text{Player}} - \mathbf{v}_{\text{Ally}}\Vert{} \le D_{\text{max}}) \land (\mathbf{F}_{\text{Ally}} \cdot \mathbf{D}_{\text{Target}} \ge \cos\theta_{\text{threshold}}) \land \text{LineOfSightClear} \land \text{NavMeshReachable}$$

---

## 📋 V. Implementation Data Contract Matrix

| Domain Parameter | Source Schema & Key | Target Actuator Channel | Output Unit / Value Range | Versioning & Update Policy |
| --- | --- | --- | --- | --- |
| **A_ENGINE_LOGIC** | `FAshenStateSnapshot.Resolve` | `UCharacterMovementComponent::MaxWalkSpeed` | **1.0x – 1.35x** | Committed (`StateVersion++`) |
| **A_ENGINE_LOGIC** | `FAshenStateSnapshot.GameplayEffectiveMass` | `UCharacterMovementComponent::InertiaDamping` | **45.0 – 120.0 kg** | Committed (`StateVersion++`) |
| **A_ENGINE_LOGIC** | `UMontagePositionEvaluationTask` | `UGASAbilitySystemComponent::StaminaCost` | **0.0x (Perfect) / 1.0x** | Transient ($P_{montage}$ check) |
| **B_HARDWARE_TRIGGER** | `FAshenStateSnapshot.ActiveStanceTag` | `PlatformAdapter::AdaptiveTriggerProfile` | Stance Profile Topology | Real-Time Observer Swap |
| **B_HARDWARE_HAPTIC** | `Event.Combat.FlowGlint.Perfect` | `PlatformAdapter::BilateralVoiceCoil` | **180 Hz / 35 ms** | Transient Event Pulse |
| **B_AUDIO_MODULATION** | `Event.Combat.FlowGlint.Perfect` | `MetaSound::HarmonicTransient` | **528.0 Hz Transient / -3 dB Duck** | Transient Submix Trigger |
| **C_AI_DIRECTIVE** | `FAshenRelationalEventPayload` | `URelationalEvaluator::CommitDelta` | Struct Payload | Transactional (`StateVersion++`) |
| **C_AI_DIRECTIVE** | `UAshenSpatialEvaluator` | `GarrettStateTree::MotionWarpTarget` | Directional Vector + Transform | Evaluated in Stage 5 |
| **D_BIOMECHANICS** | `FAshenStateSnapshot.Corruption` | `AnimInstance::PosturalRigidityWeight` | **0.0 – 1.0** (Blend Weight) | Stage 9 Derived Observer |
| **D_BIOMECHANICS** | `FAshenStateSnapshot.IntegrationDebt` | `AnimInstance::GaitLimbDragOffset` | **0.0 – 15.0 uu** (Offset) | Stage 9 Derived Observer |
| **E_STATE_SYNC** | `FAshenStateSnapshot` | `UAshenSoulPublisher::TelemetryStream` | Versioned Binary Snapshot | Monotonic (`StateVersion++`) |
