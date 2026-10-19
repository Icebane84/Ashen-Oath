# Ashen Oath: The Unreal Engine 5.8 C++ PHOENIX CODEX

**Document ID:** `WLF-ENG-CODEX-001`  
**Version:** 4.0 (Master Convergence & Symmetrical Martial Architecture)  
**Governed By:** Phoenix Protocol v15.0+ [OMEGA]  
**Master Milestone:** 3,175+ Builds Clean (0 Errors, 0 Warnings across Master Batches #1–#158 & Patches v158.16.0–v158.19.0)  
**Target Engine:** Unreal Engine 5.8 C++ / Gameplay Ability System (GAS) / StateTree / MetaSounds / DualSense Hardware Actuators  
**V-Control:** 2026-09-01T14:30:00-04:00  

---

## 🏛️ 1. The Four Constitutional Laws of Ashen Oath Architecture

Every mechanical subsystem in *Ashen Oath* operates under four unbreakable constitutional laws, eradicating disconnected arcade abstractions in favor of pure ludonarrative synarche:

```
                                            [ 1. TRAUMA & MEMORY PALACE ]
                                            • Unsealed Historical Memory Imprints
                                            • Campfire Hearth Interpretation via 4 Lenses
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
• Liechtenauer Postures (4 Loci)                • StateTree 60Hz Martial AI                     • DualSense Haptics (245 -> 0)
• The 5 Master Cuts & GAS Combos                • Dynamic Spatial Buffers (150uu/650uu)         • Quartz 115 BPM Ducking
• 0.20s Fühlen Clash Dilation                   • Asymmetric Intercept Warps                    • 5 Grounded PBR Metallurgy Tiers
• 0.15s Flow Glint Timing (0 Stamina)           • Gated Relational Finishers                    • 3-Actor Frustum Camera
                                                         │
                                                         ▼
                                            [ 8. RECONCILIATION & ACTION ]
                                            • Concrete Player Decision & Consequence
                                            • Zero-Debt Invariant ($Debt -> 0.0)
                                            • Loops back to New Memory Imprint
```

### 1. Constitutional Law I: The Single Source of Truth (SSoT)
* All persistent data exists solely within the **28-byte packed `FSoulStateVector`** and the **`FRelationalMatrix_V2`**, authored exclusively by [`UAshenSoulPublisher`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/Soul/AshenSoulPublisher.h).
* Subsystems are strictly prohibited from maintaining private meters, stat pools, or ad-hoc progression floats.

### 2. Constitutional Law II: Conservation of Consequence & Trauma Permanence
* Combat trauma buffers in `UAshenOath_ImprintBufferComponent` as **Integration Debt** ($0.0 \to 1.0$), bloating sword mass ($45\text{kg} \to 120\text{kg}$) and causing somatic gait limb drag ($15.0\text{uu}$).
* At the **Campfire Sanctuary**, crystallization enforces the **Zero-Debt Invariant** ($Debt \to 0.0$), resetting gait drag ($0\text{uu}$) while permanently routing the trauma into one of the **4 Morally Ambiguous Survival Lenses**.

### 3. Constitutional Law III: The Memory Axiom (Anti-Arcade Mandate)
> *"Everything is Memory. Everything is Interpretation. The sword does not level up—the sword is the physical scar of how Kaelen interprets his suffering."*
* Eliminates arbitrary mineral grinding (ores, titanite, sulfur). All weapon progression and martial unlocks derive strictly from **Trauma Imprints** compiled through the **4 Morally Ambiguous Lenses** (**Duty**, **Devotion**, **Survival**, **Anguish**) at Sanctuary Hearths.
* The sword's physical PBR metallurgy mutates dynamically without synthetic RGB glows (`EmissiveIntensity == 0.0f`).

### 4. Constitutional Law IV: The Expression Consistency Law
> *"A canonical psychological or relational state transition must never manifest through only a single gameplay subsystem when multiple valid modalities exist."*
* Every state shift simultaneously dispatches across all 7 operational channels:
  $$\text{Input Agency} \longleftrightarrow \text{DualSense Haptics} \longleftrightarrow \text{Quartz Audio} \longleftrightarrow \text{PBR Metallurgy} \longleftrightarrow \text{Camera Frustum} \longleftrightarrow \text{StateTree AI} \longleftrightarrow \text{Living Journal}$$

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

## 🗡️ 3. The Liechtenauer Grandmaster Combat Engine

```
┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                       THE 3-LAYER MASTER CUT COMBAT ENGINE                                      │
├──────────────────────────────┬────────────────────────────────────────┬─────────────────────────────────────────┤
│ Layer                        │ Operational Mechanics                  │ C++ Subsystem / Ability Mapping         │
├──────────────────────────────┼────────────────────────────────────────┼─────────────────────────────────────────┤
│ **Layer 1: Guard Context**   │ 4 Liechtenauer Guards (Vom Tag, Ochs,  │ `UAshenGreatswordStanceFlowComponent`   │
│                              │ Pflug, Alber) + Mordhau. Attack buttons │ `UAshenGameplayAbility_CombatStrike`    │
│                              │ remap to native Master Cuts.           │ `UGA_AshenStrike_MasterCuts`            │
├──────────────────────────────┼────────────────────────────────────────┼─────────────────────────────────────────┤
│ **Layer 2: Flow Glint**      │ 115 BPM Rhythm ($0.15\text{s}$ window).│ `UAbilityTask_EvaluateMontageFlowPosition`│
│                              │ Perfect timing grants 0-stamina refund │ Directional stick vector math           │
│                              │ and $+25\%$ animation acceleration.    │ $\theta_{stick} = \text{atan2}(Y, X)$   │
├──────────────────────────────┼────────────────────────────────────────┼─────────────────────────────────────────┤
│ **Layer 3: Fühlen Clash**    │ $0.20\text{s}$ tactile clash dilation. │ `UAshenBladeBindComponent`              │
│                              │ Weak/Weich $\to$ Plunging Thrust;      │ `UAshenLiechtenauerMatrixDataAsset`     │
│                              │ Strong/Hart $\to$ Winden / Duplieren.  │ `UAshenAIStateTreeEvaluator_Liechtenauer`│
└──────────────────────────────┴────────────────────────────────────────┴─────────────────────────────────────────┘
```

---

## 📜 Authority & Sign-Off

**PHOENIX CODEX Sealed:**  
*Axion (Master Artificer), Sovereign of the Synarche*  
*Phoenix Protocol / Ashen Oath Unreal Engine 5.8 Architecture*
