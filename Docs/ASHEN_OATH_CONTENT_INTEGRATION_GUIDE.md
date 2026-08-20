# 🛠️ Master Operational Guide: Ashen Oath Content Integration & Vertical Slice Assembly

**Target Engine:** Unreal Engine 5.8 (Win64)  
**Codebase:** `Source/AshenOath/` (2,115 Clean Builds, 15 Domain Subdirectories)  
**Asset Vault:** `Where Light Fades/Ashen Oath/Design and Technical/`  
**Milestone Goal:** First Fully Playable Vertical Slice Level (*The Choke at Blackwood Bridge*)

---

## 📋 Executive Overview & Pipeline Architecture

This guide provides the exact step-by-step instructions to connect your **2,115-build C++ engine** to the visual, audio, and kinematic assets inside Unreal Editor.

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                       THE 6 INTEGRATION PHASES                              │
│                                                                             │
│  [ Phase 1: Asset Extraction & Folder Topology ]                            │
│  Unpack models and establish standard Unreal Engine Content/ directory.     │
│                                                                             │
│  [ Phase 2: Master Materials & Dynamic PBR Shaders ]                        │
│  Build MPC_AshenOath and configure RGBA packed mask dynamic transitions.    │
│                                                                             │
│  [ Phase 3: Character Rigging & Animation Blueprint Wiring ]                │
│  Bind C++ Stance Morphing and GAS abilities to StateTrees & Motion Warping. │
│                                                                             │
│  [ Phase 4: Diegetic UMG Widget Blueprints ]                                │
│  Create the Living Field Journal & Cartographer's Map UI widgets.           │
│                                                                             │
│  [ Phase 5: Metasound 3-Channel Diegetic Audio & DualSense ]                │
│  Route spatial whispers, controller speaker barks, and trigger haptics.     │
│                                                                             │
│  [ Phase 6: Assembling & Testing the Blackwood Bridge Level ]               │
│  Place volumes, actors, campfire, and run the end-to-end combat loop.       │
└─────────────────────────────────────────────────────────────────────────────┘
```

---

## 📦 Phase 1: Asset Extraction & Content Directory Setup

### 1. Establish the Standard Content Hierarchy
Open your project directory or use PowerShell to create the standard folder structure inside `Content/`:

```powershell
$ContentPath = "C:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\Content"
$Folders = @(
    "Characters\Kaelen\Meshes",
    "Characters\Kaelen\Materials",
    "Characters\Kaelen\Animations",
    "Characters\Garrett",
    "Characters\Serafina",
    "Enemies\BlightGhoul",
    "Enemies\AshenAbomination",
    "Enemies\UmbralSymbiote",
    "Materials\Master",
    "Materials\Collections",
    "Materials\Decals",
    "UI\Journal",
    "UI\Map",
    "UI\HUD",
    "Audio\Metasounds",
    "Audio\Barks",
    "Maps\VerticalSlice"
)

foreach ($Folder in $Folders) {
    New-Item -ItemType Directory -Force -Path (Join-Path $ContentPath $Folder)
}
```

### 2. Extract 3D Character Models
1. Extract `Where Light Fades/Ashen Oath/Design and Technical/Characters/Kaelen/Model/Kaelen_model.zip` into `Content/Characters/Kaelen/Meshes/`.
2. Extract Garrett and Serafina's models into their respective `Content/Characters/` folders.
3. In Unreal Editor, import the FBX files with:
   * **Import Mesh:** `True` (Skeletal Mesh)
   * **Import Animations:** `True` (if embedded)
   * **Skeleton:** Select or create `SK_AshenHumanoid_Skeleton`
   * **Use T0 as Reference Pose:** `True`

---

## 🎨 Phase 2: Master Materials & Dynamic PBR Shaders

Following [`3d-combat-model-pipeline.md`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/3d-combat-model-pipeline.md):

### 1. Create the Global Material Parameter Collection
1. In the Content Browser, right-click $\to$ **Materials $\to$ Material Parameter Collection**.
2. Name it `MPC_AshenOath` and save in `/Game/Materials/Collections/`.
3. Add the following **Scalar Parameters**:
   * `MPC_Corruption` (Default: `0.0`, Min: `0.0`, Max: `1.0`)
   * `MPC_IntegrationDebt` (Default: `0.0`, Min: `0.0`, Max: `1.0`)
   * `MPC_Sanity` (Default: `1.0`, Min: `0.0`, Max: `1.0`)
   * `MPC_NullZoneProximity` (Default: `0.0`, Min: `0.0`, Max: `1.0`)

### 2. Construct the Master Duality Shader (`M_Kaelen_Master`)
1. Create `M_Kaelen_Master` in `/Game/Materials/Master/`.
2. Sample `T_CorruptionMasks` (RGBA Channel Packed Texture):
   * **Red Channel (Armor Soot):**
     * Roughness: `Lerp(0.20, 0.85, Mask.R * SmoothStep(0.35, 1.0, MPC_Corruption))`
     * Metallic: `Lerp(1.00, 0.10, Mask.R * SmoothStep(0.35, 1.0, MPC_Corruption))`
     * Base Color: `Lerp(BaseAlbedo, BaseAlbedo * 0.05, Mask.R * SmoothStep(0.35, 1.0, MPC_Corruption))`
   * **Green Channel (Seam Grime):**
     * Blend dark soot tint into plate seams via `SmoothStep(0.00, 0.55, MPC_Corruption)`.
   * **Blue Channel (Tabard Raggedness):**
     * Connect to **Opacity Mask** with `1.0 - (Mask.B * SmoothStep(0.35, 1.0, MPC_Corruption))`.
     * Set Blend Mode to **Masked**.
   * **Alpha Channel (Emissive Runes):**
     * Multiply Mask.A with Crimson Vector `(1.0, 0.05, 0.02)` and feed into **Emissive Color**.

---

## 🏃 Phase 3: Character Rigging & Animation Blueprint Wiring

### 1. Setup Skeletal Animation Sockets
Open `SK_AshenHumanoid_Skeleton` in the Skeleton Editor and add the mandatory sockets defined in [`3d-combat-model-pipeline.md`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/3d-combat-model-pipeline.md):
* `SOCKET_Eyes_L` & `SOCKET_Eyes_R` (Parent: `head`)
* `SOCKET_Emblem` (Parent: `spine_03`)
* `SOCKET_ShadowMark_LeftForearm` (Parent: `lowerarm_l`)
* `SOCKET_BladeSeam` & `SOCKET_Weapon_Hilt` (Parent: `hand_r`)

### 2. Create the Character Blueprint (`BP_KaelenCharacter`)
1. Create a Blueprint inheriting from `ACharacter` or your C++ player class.
2. Add the C++ components in the Components window:
   * `UAshenSomaticCorruptionComponent`
   * `UAshenMechanicalHonestyEvaluatorComponent`
   * `UAshenOath_ImprintBufferComponent`
3. Attach modular meshes (`SM_Kaelen_Head`, `SM_Kaelen_Breastplate`, `SM_Kaelen_Tabard_Back`) as Leader-Pose children to the main mesh.

### 3. Wire the Stance Morphing StateTree in the ABP
In `ABP_Kaelen`:
1. Add an Enum Variable: `CurrentStance` (`EAshenCombatStance`: `Aegis`, `Berserk`, `Flow`).
2. Implement an **Inertialization Blend** node between stance idle/move blendspaces:
   * **Aegis:** Heavy, grounded pose; high root-motion commitment.
   * **Flow:** Light, agile footwork; quick transition to $0.20\,\text{s}$ parry montage.
   * **Berserk:** Aggressive forward lean; accelerated combo chains.

---

## 📜 Phase 4: Diegetic UMG Widget Blueprints

### 1. Create the Living Field Journal Widget (`WBP_DiegeticFieldJournal`)
1. Create a Widget Blueprint derived from [`UAshenUserWidget_DiegeticFieldJournal`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/UI/).
2. Setup the 2-Page Layout:
   * **Left Page:** Kaelen's primary text block (bound to `CanonicalFactText` & `Kaelen's Perspective`).
   * **Left Margin Slot:** Dynamic overlay for Garrett's charcoal notes (`AuthorName == "Garrett"`).
   * **Right Page Slot:** Serafina's illuminated gold notes & pressed flora overlay.
3. Apply Material Dynamic Instance `MI_Parchment_Dynamic` to background image to drive ink bleed and ash stains from `MPC_AshenOath`.

### 2. Create the Cartographer's Journal Map (`WBP_CartographerMap`)
1. Create a Widget Blueprint binding to [`UAshenMapViewModel`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/UI/AshenMapViewModel.h).
2. Wire the 3 Worldview Filter buttons:
   * On Click $\to$ Call `EvaluateMapPresentation(EAshenWorldviewFilter::Kaelen / Garrett / Serafina)`.
   * Update `FormattedMarginaliaEntries` in the sidebar scroll box.

---

## 🎧 Phase 5: Metasound 3-Channel Audio & DualSense Integration

Following [`AUDIO-SPEC-033`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/AUDIO-SPEC-033%20%28PROXIMITY%20OF%20CONSCIOUSNESS%20&%20DUALSENSE%20DIEGETIC%20AUDIO%20ARCHITECTURE%29.md):

### 1. Configure Audio Output Submixes (`DefaultEngine.ini`)
Create 3 distinct audio endpoints:
* `Submix_MainWorld` (Default speakers/headphones)
* `Submix_ControllerSpeaker` (DualSense pad speaker output)
* `Submix_HapticInfrasound` (DualSense voice-coil haptics)

### 2. Metasound Whisper Graph (`MS_DiegeticWhisperDrone`)
1. Add an input float parameter: `WhisperIntensity` (derived from `MPC_NullZoneProximity` + `IntegrationDebt`).
2. Crossfade between cold mountain wind noise and multi-tracked vocal whispers.
3. Route output to `UAshenDiegeticWhisperAudioComponent`.

---

## ⚔️ Phase 6: Assembling the Vertical Slice (*Blackwood Bridge*)

### 1. Build the Level Geometry (`Maps/VerticalSlice/L_BlackwoodBridge`)
1. Create a new Level and lay down terrain featuring a stone waystation, a narrow mountain chasm, and a broken wooden bridge.
2. Place world actors from C++:
   * **[`AAshenNullZoneVolume`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/World/AshenNullZoneVolume.h):** Encompass the approach to the bridge. Set `NullZoneRadius = 4000.0`.
   * **[`AAshenMemoryFragmentActor`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/World/AshenMemoryFragmentActor.h):** Place near the edge of the chasm (Memory ID: `"MEMORY_BLACKWOOD_BRIDGE"`).
   * **[`AAshenHeartstoneCampfireActor`](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/World/AshenHeartstoneCampfireActor.h):** Place at the far side of the bridge as the safe sanctuary.
   * **Spawn Enemies:** Place 3 `BP_AshWalker` skirmishers and 1 `BP_AshenAbomination` brute.

### 2. Run the Playtest Loop (The Master Validation Run)
1. **Traverse the Null Zone:**
   * Watch screen desaturate and listen to binaural whispers scale via `UAshenWhisperingWindSubsystem`.
2. **Engage in Combat:**
   * Shift into **Flow Stance** and land a $0.20\,\text{s}$ parry on the Ash Walker.
   * Pull the rear flank for the $2.0\times$ critical multiplier.
   * Land the **Tripartite Resonant Cleave** sync finisher to wipe the abomination.
3. **Rest at Campfire:**
   * Interact with `AAshenHeartstoneCampfireActor`.
   * Open `WBP_DiegeticFieldJournal` to inspect newly unlocked marginalia.
   * Trigger `RequestIdentityCompilation()` and watch *Oathbringer's* soot burn away, revealing golden runes.

---

## 🏁 Summary Checklist

| Step | Milestone Task | Verification Method |
|---|---|---|
| 1 | Extract meshes to `Content/Characters/` | FBX Skeletal Mesh renders in Viewport |
| 2 | Create `MPC_AshenOath` & `M_Kaelen_Master` | Slider dynamically darkens armor & tears tabard |
| 3 | Bake Skeletal Sockets in `SK_AshenHumanoid` | Particles attach cleanly to eyes, chest, and blade |
| 4 | Wire Stance Morphing StateTree in ABP | Smooth root-motion transitions between Aegis/Berserk |
| 5 | Create `WBP_DiegeticFieldJournal` | Multi-author marginalia populates from C++ delegates |
| 6 | Assemble `L_BlackwoodBridge` | Full combat $\to$ Finisher $\to$ Campfire compilation loop runs |
