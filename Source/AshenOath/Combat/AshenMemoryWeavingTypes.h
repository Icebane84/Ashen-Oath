// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenMemoryWeavingTypes.generated.h"

UENUM(BlueprintType)
enum class EWeavingPatternType : uint8
{
	AegisNet       UMETA(DisplayName = "Luminous Aegis Net (Poise Shielding)"),
	TraumaBridge   UMETA(DisplayName = "Trauma Light Bridge (Chasm Traversal)"),
	ResonanceChord UMETA(DisplayName = "Harmonic Resonance Chord (Symbiotic Buff)")
};

UENUM(BlueprintType)
enum class EFilamentTensionState : uint8
{
	Slack     UMETA(DisplayName = "Slack (Low Load - Golden Glow)"),
	Tense     UMETA(DisplayName = "Tense (Heavy Load - Vibrating Amber)"),
	Snapping  UMETA(DisplayName = "Snapping (Imminent Rupture - Violent Violet Flash)")
};

USTRUCT(BlueprintType)
struct FWeavingThreadPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	int32 ActiveThreadCount = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	float TensionScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	float PoiseAbsorptionRatio = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	EFilamentTensionState TensionState = EFilamentTensionState::Slack;
};

USTRUCT(BlueprintType)
struct FTraumaBridgeAnchor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	FVector StartAnchorLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	FVector EndAnchorLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	float BridgeLengthUnits = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Weaving")
	bool bIsBridgeSolidified = false;
};
