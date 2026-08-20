// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenShepherdsGambitSubsystem.generated.h"

/**
 * UAshenShepherdsGambitSubsystem
 * GameInstance Subsystem managing the symmetrical party collapse (The Shepherd's Gambit) when Kaelen's corruption C >= 0.70.
 */
UCLASS()
class ASHENOATH_API UAshenShepherdsGambitSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Containment")
	bool bIsUnchainedContainmentActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Containment")
	EUnchainedHazardLevel CurrentHazardLevel = EUnchainedHazardLevel::Safe;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Containment")
	void EvaluateCorruptionThreshold(float CorruptionAmount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Containment")
	void ResolveContainmentCrisis();
};
