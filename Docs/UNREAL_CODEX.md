# Ashen Oath: The Unreal Engine 5.8 C++ PHOENIX CODEX

**Document ID:** `WLF-ENG-CODEX-001`  
**Version:** 3.0 (Master Convergence & Closed-Loop Causal Architecture)  
**Governed By:** Phoenix Protocol v15.0+ [OMEGA]  
**Master Milestone:** 3,175+ Builds Clean (0 Errors, 0 Warnings across Master Batches #1–#158 & 23 Master Test Suites)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / Quartz Audio Subsystem / DualSense Hardware Actuators  
**V-Control:** 2026-08-30T15:15:00-04:00  

---

## 🏛️ 1. The Four Constitutional Laws of Ashen Oath Architecture

Every mechanical subsystem in *Ashen Oath* operates under four unbreakable constitutional laws, eradicating disconnected arcade abstractions in favor of pure ludonarrative synarche:

```
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
• 0.15s Flow Glint Timing                       • Gated Relational Finishers                    • 3-Actor Frustum Camera
                                                         │
                                                         ▼
                                            [ 8. RECONCILIATION & ACTION ]
                                            • Concrete Player Decision & Consequence
                                            • Commit Delta ──► Compiles to Living Journal (UMB-UI-004)
                                            • Loops back to New Memory Imprint
```

### 1. Constitutional Law I: The Single Source of Truth (SSoT)
* All persistent data exists solely within the **28-byte packed `FSoulStateVector`** and the **`FRelationalMatrix_V2`**, authored exclusively by [`UAshenSoulPublisher`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Soul/AshenSoulPublisher.h).
* Subsystems are strictly prohibited from maintaining private meters, stat pools, or ad-hoc progression floats.

### 2. Constitutional Law II: Conservation of Consequence & Trauma Permanence
* Trauma is never erased or zeroed out ($H = 0.00$ is a forbidden state).
* Systemic recovery stabilizes at **Contained ($H \approx 0.15 - 0.35$)**, never **Purged**. Scars remain permanently integrated across movement recovery frames, blade shaders, and journal marginalia.

### 3. Constitutional Law III: The Memory Axiom (Anti-Arcade Mandate)
> *"Everything is Memory. Everything is Interpretation. The sword does not level up—the sword is the physical scar of how Kaelen interprets his suffering."*
* Eliminates arbitrary mineral grinding (ores, titanite, sulfur). All weapon progression and martial unlocks derive strictly from **Trauma Imprints** compiled through **Ontological Lenses** (*Wrath, Trust, Accountability, Defiance*) at Sanctuary Hearths.

### 4. Constitutional Law IV: The Expression Consistency Law
> *"A canonical psychological or relational state transition must never manifest through only a single gameplay subsystem when multiple valid modalities exist."*
* Every state shift simultaneously dispatches across all 7 operational channels:
  $$\text{Input Agency} \longleftrightarrow \text{DualSense Haptics} \longleftrightarrow \text{Quartz Audio} \longleftrightarrow \text{Procedural Shaders} \longleftrightarrow \text{Camera Frustum} \longleftrightarrow \text{Companion AI} \longleftrightarrow \text{Living Journal}$$

---

## 📐 2. The Core Data Engine & Somatic Mathematics

### 1. The Canonical 28-Byte Struct (`AshenSoulStateVector.h`)
```cpp
#pragma pack(push, 4)
USTRUCT(BlueprintType)
struct ASHENOATH_API FSoulStateVector
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") float Resolve = 0.50f;          // 4 bytes [0.0, 1.0]
	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") float Corruption = 0.0f;         // 4 bytes [0.0, 1.0]
	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") float IntegrationDebt = 0.0f;    // 4 bytes [0.0, 1.0]
	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") float Isolation = 0.0f;          // 4 bytes [0.0, 1.0]
	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") float GarrettTrust = 0.50f;     // 4 bytes [0.0, 1.0]
	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") float SerafinaTrust = 0.50f;    // 4 bytes [0.0, 1.0]
	UPROPERTY(BlueprintReadOnly, Category = "Soul|Canonical") EInterpretiveLens PrimaryLens;   // 4 bytes [Enum]
};
#pragma pack(pop)
static_assert(sizeof(FSoulStateVector) == 28, "FSoulStateVector must remain exactly 28 bytes.");
```

### 2. Normalized Non-Saturating Manifolds ($\sum \text{coefficients} = 1.00$)
To prevent gameplay functions from slamming into mathematical clamps prematurely, all positive derivation coefficients sum exactly to $1.00$:
* **Internal Friction ($\Phi_{\text{internal}}$):**
  $$\Phi_{\text{internal}} = \text{Clamp}\Big(0.25 \cdot D + 0.25 \cdot \text{Isolation} + 0.20 \cdot \text{LensShift} + 0.15 \cdot \text{Threat} + 0.15 \cdot (1.0 - R), \,\, 0.0, \,\, 1.0\Big)$$
* **Parasite Pressure ($H$ — Blade Hunger):**
  $$H = \text{Clamp}\Big(0.40 \cdot C + 0.35 \cdot \Phi_{\text{internal}} + 0.25 \cdot (1.0 - R), \,\, 0.0, \,\, 1.0\Big)$$
* **Relational Flow ($\Psi_{\text{relational}}$):**
  $$\Psi_{\text{relational}} = \text{Clamp}\Big(0.45 \cdot \text{TrioResonance} + 0.25 \cdot \text{ProximityFactor} + 0.20 \cdot (1.0 - \text{Threat}) + 0.10 \cdot \text{bSupportActive}, \,\, 0.0, \,\, 1.0\Big)$$
* **Isolation Pressure ($I$):**
  $$I = \text{Clamp}\Big(0.55 \cdot (1.0 - \Psi_{\text{relational}}) + 0.45 \cdot (1.0 - \text{ProximityFactor}), \,\, 0.0, \,\, 1.0\Big)$$

---

## ⚔️ 3. Martial Kinematics & The Deference Fulcrum

### 1. Calculated Deference vs. The Martyrdom Trap
* **"Don't confuse suffering with responsibility."**
* **Martyrdom Trap:** Kaelen drops guard and eats raw damage as a passive meat shield (punished via Guard Crush and companion terror).
* **Calculated Deference:** Kaelen locks into an immovable high longsword bind (*Ochs/Mordhau*). He surrenders offensive DPS ($0.60\text{s}$ lockout) and absorbs $80\%$ poise strain to create an opening for Garrett's vault flank or Serafina's conduit burst.
* **Post-Strike Stabilization:** When the strike lands, Integration Debt drops ($-0.15$), Trust climbs ($+0.25$), and Parasite Pressure stabilizes into the **Contained** range ($[0.15, 0.35]$).

### 2. Euclidean Spatial Invariants & 0.15s Flow Glint Timing
* **Intimate Pocket ($\le 200\text{uu}$):** Party members in synchronized flow hold a close combat pocket, enabling the $0.15\text{s}$ Flow Glint dual-sigil finisher.
* **Retraction Buffer ($650\text{uu}$):** When terrified or alienated, companions pull back to $650\text{uu}$, physically locking out the finisher because they cannot bridge $650\text{uu}$ in $0.15\text{s}$.

---

## ⚡ 4. The Sentinel Protocol & Anti-Theater Law

1. **Non-Negotiable Value-Asserting Exit Criterion:**
   * A real automation test must fail when the mechanic is broken on purpose, and pass when fixed.
   * Zero tautologies: Never author `TestTrue(..., Orchestrator->ValidateX())` where `ValidateX()` returns hardcoded `true`.
   * Every test must assert against actual resulting game state (coordinates, damage, material parameters, delegates, packed memory).
2. **Data-Driven Balancing & Invariant Safety Law (Zero-Recompile Protocol):**
   * Decouple tuning from mechanics: Combat scalars are encapsulated in dedicated `UPrimaryDataAsset` classes with explicit `ClampMin/ClampMax` metadata.
   * Defensive C++ boundary clamping (`FMath::Clamp`) prevents mechanical desynchronization or arithmetic anomalies.
3. **The Faraday Cage SLM Governance Firewall (Law 11):**
   * Zero external cloud transmission. All offline SLM outputs pass through `UAshenIdentityGovernanceValidator`:
     * JSON Schema Validation
     * Provenance Audit (Rejects citations absent from authoritative imprint buffers)
     * Delta Hard-Clamping ($\pm 0.25$)
     * Asymmetric Memory Decay ($S(t) = S_0 \cdot e^{-\lambda t}$)

---

## 🏛️ 5. The 12 Domain-Driven Vertical Slices Hierarchy

```
Source/AshenOath/
├── Core/         (Base contracts, save game serialization, state enforcers)
├── Soul/         (FSoulStateVector, UAshenSoulPublisher, UAshenSoulDerivationSubsystem)
├── Memory/       (Memory Palace graph, Memory Battles, Lorekeeper beacons)
├── Companions/   (Garrett, Serafina, FRelationalMatrix_V2, fatigue, resonance)
├── Combat/       (GAS abilities, Oathbringer Greatsword, DeferenceComponent, RunicForge)
├── Narrative/    (Dialogue adapters, narrative barks, choice tree gates, Governance)
├── UI/           (UMG backing widgets, Somatic HUDs, Living Journal UMB-UI-004)
├── Audio/        (Quartz 6-stem dynamic conductor, spatial whispers, MetaSound triggers)
├── World/        (Null Zones, consecrated anchors, memory fragments, altars, Chaos)
├── Orchestration/(SoulExpressionDispatcher, macro-systemic event spines)
├── AI/           (EQS directors, memory battle enemies, flanking interceptors)
└── QA/           (ProductFilter FAutomationTestBase value-asserting test suites)
```

---

## 📦 6. Master Production Batches (The 20-Build Cadence)

Every Master Batch follows the rigid **20-Build Cadence** across 4 systematic gameplay phases:

```
[ Phase 1: Builds 1–5  ] ──► Core Domain Subsystems, State Machines & Mathematical Components
[ Phase 2: Builds 6–10 ] ──► Gameplay Abilities (GAS), Combat Stances, Motion Warping & World Actors
[ Phase 3: Builds 11–15] ──► AI Perception/EQS Flanking, Diegetic Audio, Somatic UMG & Shaders
[ Phase 4: Builds 16–20] ──► Cross-Domain Adapters, Narrative Bridges, SaveGame & Value-Asserting QA Suites
```

---

**Status:** Canonical North Star for all Ashen Oath C++ Architecture. Adherence is mandatory for maintaining Zero Entropy.
