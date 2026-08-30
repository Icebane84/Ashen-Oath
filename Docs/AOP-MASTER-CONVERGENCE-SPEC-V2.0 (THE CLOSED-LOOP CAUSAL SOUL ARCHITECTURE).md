# ARCHITECTURAL SPECIFICATION: THE MASTER CONVERGENCE BLUEPRINT (V2.0)

**Document ID:** `AOP-MASTER-CONVERGENCE-SPEC-V2.0`  
**V-Control:** `2026-08-30T14:00:00-04:00`  
**Primary Index:** `PRS-001` / `MASTER-SPEC-ASHEN-OATH-2026`  
**Architecture Alignment:** `CONTRACT-SPEC-051` / `FSoulStateVector` / `TAM-001` / `RUNIC-FORGE-SPEC-098` / `AOP-COMBAT-SPEC-101-PROD-HARDENED` / `AOP-REWORK-HUNGER-103` / `UMB-UI-004` / `ENGINE-SPEC-001`  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Quartz Audio Subsystem / DualSense Hardware Actuators  
**Status:** Canon-Locked Production Blueprint (23 Master Test Suites Passing Clean, 0 Errors, 0 Warnings)  

---

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                   THE CLOSED-LOOP CAUSAL SOUL ARCHITECTURE                                      │
└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
                                                         │
                                                         ▼
                                            [ 1. TRAUMA & MEMORY PALACE ]
                                            • Unsealed Historical Memory Imprints
                                            • Campfire Hearth Interpretation via Lenses
                                                         │
                                                         ▼
                                   [ 2. CANONICAL STATE: UAshenSoulPublisher ]
                                   • 28-Byte Packed FSoulStateVector (R, C, D, N, etc.)
                                   • Multi-Dimensional FRelationalMatrix_V2
                                                         │
                                                         ▼
                                 [ 3. DERIVATION LAYER: UAshenSoulDerivationSubsystem ]
                                 • Continuous Derivation of FSomaticState:
                                   Φ_internal (Friction), H (Parasite Pressure), Ψ (Relational Flow), I (Isolation)
                                                         │
                                                         ▼
                                   [ 4. DISPATCH GATE: USoulExpressionDispatcher ]
                                   • Threshold & Meaningful Delta Gating (No Per-Tick Floods)
                                                         │
         ┌───────────────────────────────────────────────┼───────────────────────────────────────────────┐
         ▼                                               ▼                                               ▼
[ 5. MOTOR & COMBAT ]                           [ 6. RELATIONAL AI ]                            [ 7. SOMATIC CHANNELS ]
• Liechtenauer Postures (4 Loci)                • Multi-Dimensional Dynamics                    • DualSense Haptics (245 -> 0)
• Predatory Momentum Over-Swings                • Dynamic Spatial Buffers (150uu/650uu)         • Quartz 115 BPM Ducking
• Calculated Deference Bind (Ochs)              • Asymmetric Intercept Warps                    • MPC Shaders (ThermalSlag)
• 0.15s Flow Glint Timing                       • Gated Relational Finishers                    • 3-Actor Frustum Probe Camera
                                                         │
                                                         ▼
                                            [ 8. RECONCILIATION & ACTION ]
                                            • Concrete Player Decision & Consequence
                                            • Commit Delta ──► Compiles to Living Journal (UMB-UI-004)
                                            • Loops back to New Memory Imprint
```

---

## 🏛️ SECTION I: Ontological Baseline & The Four Constitutional Laws

### What: The Causal Architecture
*Ashen Oath* rejects extrinsic RPG abstractions (e.g., leveling up weapons via ore grinding, arbitrary "+5 Strength" stat sticks, or isolated quick-time event meters). The game operates as a **closed-loop causal simulation** where psychology drives mechanics:

$$\text{Memory} \longrightarrow \text{Interpretation} \longrightarrow \text{Soul State} \longrightarrow \text{Derived Pressure} \longrightarrow \text{Motor/Spatial Expressions} \longrightarrow \text{Player Action} \longrightarrow \text{Consequence} \longrightarrow \text{New Memory}$$

### How: The Four Constitutional Laws
* **Constitutional Law I: The Single Source of Truth (SSoT)**
  All persistent state exists solely within the **28-byte `FSoulStateVector`** and the **`FRelationalMatrix_V2`**, authored exclusively by `UAshenSoulPublisher`. Subsystems are strictly prohibited from maintaining private meters, stat pools, or ad-hoc progression floats.
* **Constitutional Law II: Conservation of Consequence & Trauma Permanence**
  Trauma is never erased or zeroed out. Systemic recovery stabilizes at **Contained ($H \approx 0.15 - 0.35$)**, never **Purged ($H = 0.00$)**. Scars remain permanently integrated across movement recovery frames, blade shaders, and journal marginalia.
* **Constitutional Law III: The Memory Axiom**
  > *"Everything is Memory. Everything is Interpretation. The sword does not level up—the sword is the physical scar of how Kaelen interprets his suffering."*
  > All weapon progression and martial unlocks derive strictly from **Trauma Imprints** compiled through **Ontological Lenses** at Sanctuary Hearths.
* **Constitutional Law IV: The Expression Consistency Law**
  > *"A canonical psychological or relational state transition must expose itself synchronously through every applicable modality for which a meaningful mapping has been defined."*
  > A state transition never leaks through an isolated widget; it manifests across the full matrix:
  > 
  > $$\text{Input Agency} \longleftrightarrow \text{DualSense Haptics} \longleftrightarrow \text{Quartz Audio} \longleftrightarrow \text{Procedural Shaders} \longleftrightarrow \text{Camera Frustum} \longleftrightarrow \text{Companion AI} \longleftrightarrow \text{Living Journal}$$

---

## 📐 SECTION II: State Architecture — Canonical vs. Derived Topology

### 1. The Canonical 28-Byte Structure (`AshenSoulStateVector.h` / `AshenSoulTypes.h`)
```cpp
USTRUCT(BlueprintType)
struct ASHENOATH_API FSoulStateVector
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	float Resolve = 0.50f;              // Core willpower and grounding

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	float Corruption = 0.0f;             // Shadow exposure and taint

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	float IntegrationDebt = 0.0f;        // Unprocessed somatic trauma

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	float Isolation = 0.0f;              // Self-sacrificing detachment / Dysregulation

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	float GarrettTrust = 0.50f;         // Tactical cohesion anchor for Garrett

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	float SerafinaTrust = 0.50f;        // Empathic resonance anchor for Serafina

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical")
	EInterpretiveLens PrimaryLens = EInterpretiveLens::Accountability;
};
static_assert(sizeof(FSoulStateVector) == 28, "FSoulStateVector must remain exactly 28 bytes.");
```

### 2. The Derived Somatic Structure (`FSomaticState`)
```cpp
USTRUCT(BlueprintType)
struct ASHENOATH_API FSomaticState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Derived")
	float InternalFriction = 0.0f;      // Phi: Resistance between intention and execution

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Derived")
	float ParasitePressure = 0.0f;      // H: Eldrin's predatory momentum / Blade Hunger

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Derived")
	float RelationalFlow = 0.0f;        // Psi: Moment-to-moment cooperative bandwidth

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Derived")
	float IsolationPressure = 0.0f;     // I: Psychological and spatial detachment

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Derived")
	float WillCapacity = 0.5f;          // Derived active willpower reservoir
};
```

### 3. Normalized Mathematical Manifolds ($\sum \text{coefficients} = 1.00$)
* **Internal Friction ($\Phi_{\text{internal}}$):**
  $$\Phi_{\text{internal}} = \text{Clamp}(0.25 \cdot D + 0.25 \cdot \text{Isolation} + 0.20 \cdot \text{LensShift} + 0.15 \cdot \text{Threat} + 0.15 \cdot (1.0 - R), 0.0, 1.0)$$
* **Parasite Pressure ($H$ — Blade Hunger):**
  $$H = \text{Clamp}(0.40 \cdot C + 0.35 \cdot \Phi_{\text{internal}} + 0.25 \cdot (1.0 - R), 0.0, 1.0)$$
* **Relational Flow ($\Psi_{\text{relational}}$):**
  $$\Psi_{\text{relational}} = \text{Clamp}(0.45 \cdot \text{TrioResonance} + 0.25 \cdot \text{ProximityFactor} + 0.20 \cdot (1.0 - \text{Threat}) + 0.10 \cdot \text{bSupportActive}, 0.0, 1.0)$$
* **Isolation Pressure ($I$):**
  $$I = \text{Clamp}(0.55 \cdot (1.0 - \Psi_{\text{relational}}) + 0.45 \cdot (1.0 - \text{ProximityFactor}), 0.0, 1.0)$$

---

## 👥 SECTION III: Multi-Dimensional Relational Topology (`TAM-001`)

```cpp
USTRUCT(BlueprintType)
struct ASHENOATH_API FCompanionProfile_V2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float InterpersonalTrust = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float TacticalConfidence = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float SomaticDread = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul|Relational")
	float TransferenceBurnout = 0.0f;
};
```

### Relational Predicate Evaluation:
```cpp
bool FRelationalMatrix_V2::IsEligibleForRelationalFinisher() const
{
	const bool bGarrettReady = (GarrettProfile.TacticalConfidence >= 0.60f) && (GarrettProfile.SomaticDread < 0.50f);
	const bool bSerafinaReady = (SerafinaProfile.TacticalConfidence >= 0.60f) && (SerafinaProfile.TransferenceBurnout < 0.80f);
	return (TrioResonance >= 0.70f) && bGarrettReady && bSerafinaReady;
}
```

---

## 🛡️ SECTION IV: Calculated Deference & The Martial Fulcrum (`COMBAT-101`)

* **"Don't confuse suffering with responsibility."**
* **Martyrdom Trap:** Kaelen drops guard and eats raw damage as a passive meat shield (punished via Guard Crush).
* **Calculated Deference:** Kaelen locks into an immovable high longsword bind (*Ochs/Mordhau*). He surrenders offensive agency ($0.60\text{s}$ lockout) and absorbs $80\%$ poise strain to create an opening for Garrett's vault flank or Serafina's conduit burst.
* **State Stabilization:** When the strike lands, Integration Debt drops ($-0.15$), Trust climbs ($+0.25$), and Parasite Pressure stabilizes in the **Contained** range ($[0.15, 0.35]$).

---

## 🧪 SECTION V: Value-Asserting QA Test Matrix

1. [`FAshenMasterConvergenceV2AutomationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenMasterConvergenceV2AutomationTest.cpp): Unit math invariants, closed-loop Calculated Deference integration, SSoT contract reflection tests.
2. [`FAshenRunicForgeConvergenceIntegrationTest`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/QA/AshenRunicForgeConvergenceIntegrationTest.cpp): 5-Tier Ascension derivation, Flow Glint spatial gating ($\le 200\text{uu}$ vs $650\text{uu}$).
