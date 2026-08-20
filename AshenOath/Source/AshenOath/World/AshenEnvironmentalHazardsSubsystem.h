// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEnvironmentalHazardsSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenHazardType : uint8
{
	LavaPool        UMETA(DisplayName = "Lava Pool"),
	FrostbiteZone   UMETA(DisplayName = "Frostbite Zone"),
	ToxicMiasmaCloud UMETA(DisplayName = "Toxic Miasma Cloud"),
	VoidCollapseRift UMETA(DisplayName = "Void Collapse Rift")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHazardRegisteredSignature, FName, HazardID, EAshenHazardType, HazardType, FVector, Location);

/**
 * UAshenEnvironmentalHazardsSubsystem
 *
 * World Subsystem tracking environmental hazards (lava, frostbite, miasma, void rifts) across Frozen Tarn levels.
 */
UCLASS()
class ASHENOATH_API UAshenEnvironmentalHazardsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hazards")
	void RegisterHazard(FName HazardID, EAshenHazardType HazardType, FVector Location);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hazards")
	void DeregisterHazard(FName HazardID);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Hazards")
	int32 GetActiveHazardCount() const { return ActiveHazards.Num(); }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Hazards|Events")
	FOnHazardRegisteredSignature OnHazardRegistered;

private:
	struct FHazardRecord
	{
		EAshenHazardType Type = EAshenHazardType::LavaPool;
		FVector Location = FVector::ZeroVector;
	};

	TMap<FName, FHazardRecord> ActiveHazards;
};
