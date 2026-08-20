# Production Blueprint: 3D Combat Model & Shader Implementation

**Document Reference:** WLF-TECH-3D-COMBAT-PIPELINE
**Temporal Anchor:** 2026-07-20T05:51:00-07:00
**Status:** Approved for Core Game Engine Deployment

---

## 1. Modular Character Geometry & Rigging Specifications

To prevent vertex clipping during high-intensity combat animations (e.g., combat rolls, heavy parries, jump strikes) and support seamless material-based state swaps, the character models must be constructed as modular, separated static meshes bound to a unified skeleton [p156, p198].

``` text
Unified Skeleton (Joint Hierarchy)
 └── SM_Kaelen_Body_Base (Hidden Underlayer)
      ├── SM_Kaelen_Head (Hair Cards, Face Mesh) [p198]
      ├── SM_Kaelen_Breastplate [p198]
      ├── SM_Kaelen_Pauldrons_L / Pauldrons_R [p198]
      ├── SM_Kaelen_Gauntlets_L / Gauntlets_R [p198]
      ├── SM_Kaelen_Legs_Plate_L / Legs_Plate_R [p198]
      └── SM_Kaelen_Tabard_Back (Deformable Cloth Mesh) [p198]
```

### 1.1 Kaelen of the Sundered Soul

* **Anatomical Silhouette:** A tall, athletic build (approx. 6'2") displaying a hunched, tense posture that conveys the heavy psychological load of his burden [p154, p186, p251]. The neck is subtly elongated to emphasize a stern, mournful silhouette from a third-person camera perspective [p154, p186, p224].
* **Hair Card Setup:** Shoulder-length, dark black hair, modeled as a floating geometry card group hovering precisely above the collar to ensure clean neck bone rotation without vertex tearing [p154, p157, p226]. The roots utilize a desaturated, matte soot-dark vertex color pass [p154, p158].
* **Facial Shader:** Expresses a constant state of "restrained pain" via tense brow mapping and jaw gauntness [p154, p158]. The cornea shader features a faint, rim-lit crimson noise noise-generator channel that flickers near transformation thresholds [p154, p158, p187].
* **Armor Separation Rules:** Complete physical mesh seams must be placed at the shoulder-to-bicep, elbow-to-forearm, waist-to-hip, and knee-to-shin boundaries [p157]. Keep a distinct silhouette gap between the off-white tabard cloth and the leg plates to allow for physics-based cloth simulation without clipping into the metal [p154, p156, p232].
* **The Left Forearm "Shadow Mark":** Center the desaturated, greyscale spiderweb-like vein pattern on the left forearm's secondary UV channel, leaving it at a faint baseline opacity (0.05 - 0.15) during Light Mode [p154, p161, p188].

### 1.2 Garrett Alerion (The Pragmatic Sentinel)

* **Physique:** A lean, wiry "climber's build" of medium height (approx. 1.78m) [p582].
* **Anatomical Details:** Dark brown hair kept short and practical, warm green eyes (moss/emerald) featuring a sharp, assessing glint, and a distinct, thin scar running diagonally across his left cheek [p582, p584].
* **Armor Kit:** Reject the polished, shiny silver plate of the Order entirely [p583, p585]. Garrett wears darkened leather jerkins over a flexible chainmail underlayer [p583].
* **Utility & Weapons:** A highly detailed utility belt containing spring-loaded wrist-grapple components, alchemical smoke balm globes, and tripwires [p583, p584]. He carries twin, matte, unadorned short-swords/cutlasses and a visible bandolier of weighted, black-handled throwing knives [p583].

### 1.3 Serafina of the Lorekeepers

* **Physique & Face:** A slender, athletic build displaying a warm but resolute expression, flowing blonde hair, and warm green eyes dusted with faint facial freckles [p587].
* **Armor Kit:** Serafina is *not* a robed, fragile mage. She wears polished white plate armor (breastplate, structured gauntlets, and greaves) with elegant gold filigree accents over practical white garments [p587, p589].
* **Weaponry:** Carries the elegant *Lorekeeper's Staff* (a magic focus topped with a crystal flame motif, never styled as a physical spear/halberd) and wears a simple silver locket close to her collarbone [p588, p589].

---

## 2. The Duality Engine: Dynamic Shader State Swapping

To avoid abrupt, immersion-breaking mesh swaps during Kaelen's combat transformations, the entire Light Mode ↔ Dark Mode transition must be executed in real-time through a single mesh set utilizing material parameter interpolation [p201, p208, p246].

``` text
Gameplay Event (Trigger) ──> Scalar Parameter (corruption_amount 0.0 -> 1.0)
                                 │
         ┌───────────────────────┴───────────────────────┐
         ▼                                               ▼
   Phase 1 (0.00 -> 0.55)                          Phase 2 (0.35 -> 1.00)
   - Left Arm Shadow Mark Darkens                  - Total Armor Soot Infiltration
   - Seam Grime Accumulates                        - Tabard Blackens & Tears (Opacity Mask)
   - Cornea Shader Rim-Lits Red                    - Wolf Pommel & Blade Seams Glow Blazing Crimson
```

### 2.1 The Channel-Packed Mask Texture (`T_CorruptionMasks`)

For performance optimization, compile a single RGBA mask texture map to drive the transition parameters across all armor and garment shaders [p209, p247]:

* **Red Channel (R):** Armor Soot Mask (governs where polished metal darkens and loses reflectivity) [p209, p247].
* **Green Channel (G):** Shadow Seam Grime (governs dark, oily residue buildup along plate lines) [p209, p247].
* **Blue Channel (B):** Tabard Raggedness/Char Mask (governs cloth blackening and tearing) [p209, p247].
* **Alpha Channel (A):** Eye and Blade Emissive Mask (isolates the emissive channels of Kaelen's eyes and Oathbringer's runes) [p209, p247].

### 2.2 Material Parameter Remapping (Two-Phase Transition)

To create a visceral, non-linear "soulslike" transformation, split the `corruption_amount` parameter into two offset curves [p213, p251]:

```glsl
// GLSL / Godot 4 Shader Implementation Example
uniform float corruption_amount : hint_range(0.0, 1.0);
uniform sampler2D T_CorruptionMasks;

void fragment() {
    vec4 masks = texture(T_CorruptionMasks, UV);
    
    // Remap transition curves to prevent linear blending
    float t1 = smoothstep(0.00, 0.55, corruption_amount); // Early effects
    float t2 = smoothstep(0.35, 1.00, corruption_amount); // Late effects
    
    // 1. Armor Metal Adjustment
    float current_roughness = mix(0.20, 0.85, masks.r * t2); // Soot increases roughness [p160, p211]
    float current_metalness = mix(1.00, 0.10, masks.r * t2); // Soot masks metalness [p196, p211]
    vec3 base_metal_color = mix(vec3(0.8), vec3(0.05), masks.r * t2); // Darken albedo [p211]
    
    // 2. Seam Grime Darkening
    base_metal_color = mix(base_metal_color, vec3(0.01), masks.g * t1);
    
    // 3. Tabard / Cloth Raggedness (Alpha scissor tearing)
    float tabard_opacity = 1.0 - (masks.b * t2);
    if (tabard_opacity < 0.1) {
        discard; // Real-time geometric tearing [p212, p250]
    }
}
```

### 2.3 Unreal Engine Material Instance Dynamics (MIDs) Updates

For Unreal Engine configurations, the transition should be managed through an Update loop utilizing Material Instance Dynamics [p221]. The scalar update logic must bind directly to his skeletal mesh components:

```cpp
// AshenSomaticCorruptionComponent.h
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticCorruptionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAshenSomaticCorruptionComponent();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnStateVectorInvalidated(const FSoulStateVector& NewState);

    UPROPERTY()
    TObjectPtr<UMaterialParameterCollection> MPC_AshenOath;

    float TargetCorruption = 0.0f;
    float CurrentCorruption = 0.0f;
    float CorruptionInterpSpeed = 1.2f; // Corresponds to 0.83s transition time
};

// AshenSomaticCorruptionComponent.cpp
void UAshenSomaticCorruptionComponent::BeginPlay()
{
    Super::BeginPlay();
    // Subscribe to the kernel's state changes
    if (UAshenSoulConstellationSubsystem* Kernel = GetWorld()->GetGameInstance()->GetSubsystem<USoulConstellationSubsystem>())
    {
        Kernel->OnStateVectorInvalidated.AddDynamic(this, &UAshenSomaticCorruptionComponent::OnStateVectorInvalidated);
    }
    // Load the MPC asset
    MPC_AshenOath = LoadObject<UMaterialParameterCollection>(nullptr, TEXT("/Game/Materials/Collections/MPC_AshenOath.MPC_AshenOath"));
}

void UAshenSomaticCorruptionComponent::OnStateVectorInvalidated(const FSoulStateVector& NewState)
{
    // Set the new target for interpolation
    TargetCorruption = NewState.Corruption;
}

void UAshenSomaticCorruptionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Smoothly interpolate the current value towards the target
    CurrentCorruption = FMath::FInterpTo(CurrentCorruption, TargetCorruption, DeltaTime, CorruptionInterpSpeed);

    // Update the global MPC value
    if (MPC_AshenOath)
    {
        UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_AshenOath, FName("MPC_Corruption"), CurrentCorruption);
    }
}
```

---

## 3. Creature Material & Mesh Guidelines

The creatures of the Shattered Lands are physical manifestations of the world's spiritual blight [p642, p894]. To ensure they are rendered with complete fidelity to the source material, design pipelines must adhere to the following physiological rules:

### 3.1 Blight Ghoul (The Skirmisher)

* **Mesh Rules:** An emaciated, skeletal humanoid mesh with elongated limbs and claws [p643, p721].
* **Material Pass:** Sickly greyish-green skin with an active emissive mask centered in the chest cavity, simulating a pulsing, glowing green energy core [p643, p721].

### 3.2 Ashen Abomination (The Brute)

* **Mesh Rules:** A hulking, multi-limbed brute standing 8–10 feet tall with broad shoulders, asymmetric arm structures, and sharp bone spurs jutting from the spine and joints [p642, p724, p1113].
* **Material Pass:** The skin must use a deeply displacement-mapped, cooled-ash texture resembling cracked volcanic rock or petrified bark [p642, p724, p1113]. The fractures must reveal raw, glowing red/orange ember-light beneath [p1113, p1126].
* **Body Horror Features:** The back-shoulder socket must support independent skeletal joints for writhing, reddish-brown claw-tipped tentacles [p1113, p1126].

### 3.3 Aether-Weaver (Alien Predation)

* **Mesh Rules:** A massive, spider-like silhouette [p730].
* **Material Pass:** A custom translucent, semi-ethereal material that utilizes a "screen-space glitch" or vertex displacement distortion shader [p730]. This must make the model's outline appear to phase, tear, and flicker as it moves in and out of reality [p730].

### 3.4 Geode-Lurker (Perverted Symbiosis)

* **Mesh Rules:** An armored, silicon-based beast encased in interlocking, geometric crystalline plates [p734]. The claws are modeled as massive, sharp geodes [p734].
* **Material Pass:** High-refractivity anisotropic crystal shaders mapped to the outer plates [p734]. The inner geode cavities must utilize intense, self-illuminated blue/violet emissive masks that pulse during physical impacts [p734].

---

## 4. Skeleton Animation Sockets & Combat VFX Anchors

To ensure that magical abilities (such as *Purifying Light*, *Warden's Bulwark*, and *Nyx's Grasp*) align flawlessly with character combat movements, precise animation sockets must be baked directly into the skeletal hierarchies during rigging [p195, p206]:

``` text
      SOCKET_Eyes (L/R corneas) ─── [Crimson Flicker/Glow Align] [p195, p206]
                 │
      SOCKET_Emblem (Chest) ─────── [Order Cross/Star Light Burst] [p195, p206]
                 │
      SOCKET_ShadowMark (L Forearm) [Violet Corruption Vein Glow] [p195, p206]
                 │
      SOCKET_Weapon_Hilt ────────── [Oathbringer Active Blade VFX]
```

### 4.1 Complete Rigging Sockets Manifest

1. **`SOCKET_Eyes_L` / `SOCKET_Eyes_R`:** Mapped directly to Kaelen's corneas. Anchors the subtle crimson rim-light particle system that flares when `corruption_amount` climbs past 0.7 [p195, p206, p210].
2. **`SOCKET_Emblem`:** Centered on Kaelen's silver breastplate cross. Used for the soft, warm golden glow of the White Flame starburst [p195, p206].
3. **`SOCKET_ShadowMark_LeftForearm`:** Placed directly beneath the skin of Kaelen's left forearm. Used as the particle attractor and emissive source for the writhing, violet shadow-veins [p195, p206].
4. **`SOCKET_BladeSeam`:** Positioned along the fuller channel of Oathbringer's Nightsteel blade. Anchors the fiery crimson embers that ignite during Dark Mode [p195, p206].
5. **`SOCKET_Locket`:** Baked onto Serafina's collarbone joint. Used to anchor the faint golden light particles emitted from her silver locket when she channels *Lorekeeper's Intuition* [p588].
6. **`SOCKET_Wrist_Grapple`:** Placed on Garrett's left gauntlet to anchor the line-trace and spring-loaded cable asset during traversal maneuvers [p584].

---

## 5. Animation Constraints & Silhouette Readability

In third-person combat gameplay, visual information must be parsed instantly. To preserve the somber, tactile atmosphere of the Shattered Lands, combat animations and models must respect key physical limits [p205]:

* **Oathbringer's Silhouette:** The greatsword's crossguard and blade width are scaled specifically to read clearly from shoulder height at typical mid-distance camera angles [p205]. The blade material must never "shine" or "gleam" in its baseline state; its default Nightsteel metal must remain dark and matte [p580].
* **Collision Clearance Zones:** The pauldrons, tabard cloth, and shoulder gear must be weighted with strict rotational limits [p205]. pauldrons must be configured with a sliding offset on the bicep bone to prevent the armor from clipping directly into Kaelen's neck or disheveled hair during heavy overhead swings and combat dodges [p194, p205].
* **The Weight of Steel:** Avoid floaty, weightless animations. The strike frames of Oathbringer and the Geode-Lurker must have heavy, impactful deceleration curves on contact to physically sell the preternatural mass of the equipment [p205].
