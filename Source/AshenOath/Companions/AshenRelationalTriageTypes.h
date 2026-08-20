// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenRelationalTriageTypes.generated.h"

UENUM(BlueprintType)
enum class EInterpretiveTherapyLens : uint8
{
	Accountability UMETA(DisplayName = "Lens of Accountability (Defiant Martyr - Alone)"),
	Grace          UMETA(DisplayName = "Lens of Grace (Symbiotic Bond - Together)"),
	Utility        UMETA(DisplayName = "Lens of Utility (Pragmatic Execution - Necessary Price)")
};

UENUM(BlueprintType)
enum class ECompiledRelationalStance : uint8
{
	MartyrStance   UMETA(DisplayName = "Martyr Stance (+10% Solo Parry, Distance Spacing)"),
	WeaverStance   UMETA(DisplayName = "Weaver Stance (+25% Burnout Decay, Co-op Syncs)"),
	PredatorStance UMETA(DisplayName = "Predator Stance (+15% Dark Power, Soot Thickening)")
};

USTRUCT(BlueprintType)
struct FPairwiseTrustVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	float KaelenToSerafinaTrust = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	float SerafinaToKaelenTrust = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	float KaelenToGarrettTrust = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	float GarrettToKaelenTrust = 0.5f;
};

USTRUCT(BlueprintType)
struct FTriageIncidentRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	FName IncidentID = TEXT("Silent_Spire_Ambush");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	EInterpretiveTherapyLens SelectedLens = EInterpretiveTherapyLens::Grace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	ECompiledRelationalStance ResultingStance = ECompiledRelationalStance::WeaverStance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	float BurnoutDecayModifier = 1.25f;
};
