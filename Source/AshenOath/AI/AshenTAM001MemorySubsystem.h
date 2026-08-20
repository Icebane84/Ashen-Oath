// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AI/AshenCombatEcosystemTypes.h"
#include "AshenTAM001MemorySubsystem.generated.h"

/**
 * UAshenTAM001MemorySubsystem
 * GameInstance Subsystem managing the 7-stage Trust Accumulation Model (TAM-001) memory pipeline and Emergent Mastery state.
 */
UCLASS()
class ASHENOATH_API UAshenTAM001MemorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | TAM")
	FTAM001MemoryWeights ActiveWeights;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | TAM")
	void RecordCooperativeAction(bool bSuccessfulCoordination, float FailureSeverity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | TAM")
	bool EvaluateSymbioticResonance() const;
};
