# Ashen Oath: Unreal Editor Content Setup Guide
**V-Control:** 2026-07-30T08:34:33-04:00  
**Governed By:** PHOENIX CODEX v1.0 + ENGINE-SPEC-001 (DEFINITIVE CANON)

---

## Part 1: Creating & Wiring `MPC_AshenOath`

The **Material Parameter Collection (`MPC_AshenOath`)** allows the `USoulConstellationSubsystem` to drive global visual effects (screen distortion, corruption masks, vignette, despair grading) in a single pass without modifying individual dynamic material instances on frame render.

### 🛠️ Step-by-Step Instructions in Unreal Editor

1. Open **Unreal Engine 5.8 Editor**.
2. In the **Content Browser**, navigate to your desired folder (e.g., `Content/Materials/Collections/` or `Content/Core/`).
3. **Right-click** in an empty space in the Content Browser:
   - Select **Materials → Material Parameter Collection**.
   - Name the new asset: `MPC_AshenOath`.
4. Double-click `MPC_AshenOath` to open the **Material Parameter Collection Editor**.
5. Under the **Scalar Parameters** panel on the left, click the **`+` (Add Element)** button 8 times to add 8 scalar parameters.
6. Configure each parameter with the exact names below:

| # | Parameter Name | Default Value | Driven By (C++ Subsystem) | Effect in Shaders / Post-Process |
|:--|:---------------|:--------------|:--------------------------|:---------------------------------|
| 1 | `MPC_Corruption` | `0.0` | `StateVector.Corruption` | Visual corruption mask opacity & dark-mode mesh lerp |
| 2 | `MPC_Resolve` | `1.0` | `StateVector.Resolve` | Light intensity & Mindscape pillar height scale |
| 3 | `MPC_IntegrationDebt` | `0.0` | `StateVector.IntegrationDebt` | Screen edge chromatic aberration & HUD jitter |
| 4 | `MPC_Isolation` | `0.0` | `StateVector.Isolation` | Desaturation & ambient whisper particle density |
| 5 | `MPC_GarrettTrust` | `0.5` | `StateVector.GarrettTrust` | Companion aura warmth & tactical indicator color |
| 6 | `MPC_SerafinaTrust` | `0.5` | `StateVector.SerafinaTrust` | Empathic shield glow & grace bloom intensity |
| 7 | `MPC_Despair` | `0.0` | `Kernel.DespairAccumulator` | Global blue color grade tint on repeated death |
| 8 | `MPC_NullZoneProximity` | `0.0` | `AAshenNullZoneVolume` | Proximity radial distortion around Null Zones |

7. Click **Save** and close the editor window.
8. **Assign to Kernel**:
   - In Editor, open your GameInstance or Subsystem settings (or set `MPC_AshenOath` in `DefaultGame.ini` under `/Script/AshenOath.AshenSoulConstellationSubsystem`).

---

## Part 2: Authoring Your First `UAshenDialogueGraph` DataAsset

The `UAshenDialogueSubsystem` natively executes Lens-gated dialogue trees authorable via DataAssets.

### 🛠️ Step-by-Step Instructions in Unreal Editor

1. In the **Content Browser**, navigate to `Content/Dialogue/` (create folder if needed).
2. **Right-click** in the Content Browser:
   - Select **Miscellaneous → Data Asset**.
   - In the class picker dialog, search for **`AshenDialogueGraph`** and click **Select**.
   - Name the new asset: `DA_Dialogue_Shadowfen_TrioRest`.
3. Double-click `DA_Dialogue_Shadowfen_TrioRest` to open the Details panel.
4. Set the header fields:
   - **Conversation ID**: `Shadowfen_TrioRest`
   - **Start Node ID**: `Node_Opening`
5. Click **`+` (Add Element)** under **Nodes** to create dialogue nodes:

---

### 📝 Example Dialogue Node Structure

#### **Node 1: `Node_Opening`**
- **Node ID**: `Node_Opening`
- **Speaker Name**: `Garrett`
- **Dialogue Text**: *"We've been pushing through the marsh for three hours, Kaelen. Serafina is exhausted. We need to pause."*
- **Required Lens**: `Any`
- **Min Trust Required**: `0.0`
- **Min Resolve Required**: `0.0`
- **Choices**: Add 3 elements:

  - **Choice 1 (Accountability Path)**:
    - **Choice Text**: *"We keep moving. Stopping in the Shadowfen is an invitation for ambush."*
    - **Target Node ID**: `Node_Garrett_Accountability`
    - **Required Lens**: `Accountability`
    - **Min Trust Required**: `0.0`

  - **Choice 2 (Grace Path)**:
    - **Choice Text**: *"Serafina, take a moment. We rest at the next hearth."*
    - **Target Node ID**: `Node_Serafina_Grace`
    - **Required Lens**: `Grace`
    - **Min Trust Required**: `0.0`

  - **Choice 3 (Utility Path)**:
    - **Choice Text**: *"Check our remaining rations and stamina. If we have the reserves, we press on."*
    - **Target Node ID**: `Node_Trio_Utility`
    - **Required Lens**: `Utility`
    - **Min Trust Required**: `0.0`

---

#### **Node 2A: `Node_Garrett_Accountability`**
- **Node ID**: `Node_Garrett_Accountability`
- **Speaker Name**: `Garrett`
- **Dialogue Text**: *"Pragmatic as always. Fine. But if we run into a Null Zone, I'm holding you to that call."*
- **Required Lens**: `Accountability`
- **Choices**: 1 element:
  - **Choice Text**: *"[End Conversation]"* → **Target Node ID**: `None`

---

#### **Node 2B: `Node_Serafina_Grace`**
- **Node ID**: `Node_Serafina_Grace`
- **Speaker Name**: `Serafina`
- **Dialogue Text**: *"Thank you, Kaelen. The whispers here... they're louder than usual. I appreciate the breathing room."*
- **Required Lens**: `Grace`
- **Choices**: 1 element:
  - **Choice Text**: *"[End Conversation]"* → **Target Node ID**: `None`

---

#### **Node 2C: `Node_Trio_Utility`**
- **Node ID**: `Node_Trio_Utility`
- **Speaker Name**: `Garrett`
- **Dialogue Text**: *"Rations are at forty percent. We have enough for one more engagement before we must rest."*
- **Required Lens**: `Utility`
- **Choices**: 1 element:
  - **Choice Text**: *"[End Conversation]"* → **Target Node ID**: `None`

---

### 🧪 How to Trigger Dialogue in C++ or Blueprint

To start this conversation anywhere in game logic:

```cpp
if (UAshenDialogueSubsystem* Dialogue = GetGameInstance()->GetSubsystem<UAshenDialogueSubsystem>())
{
    // Load the DataAsset and start
    UAshenDialogueGraph* GraphAsset = LoadObject<UAshenDialogueGraph>(nullptr, TEXT("/Game/Dialogue/DA_Dialogue_Shadowfen_TrioRest.DA_Dialogue_Shadowfen_TrioRest"));
    Dialogue->StartConversation(GraphAsset);
}
```

The `UAshenDialogueSubsystem` will automatically query `USoulConstellationSubsystem` and **only display the choice matching Kaelen's currently selected Lens** (`Accountability`, `Grace`, or `Utility`)!
