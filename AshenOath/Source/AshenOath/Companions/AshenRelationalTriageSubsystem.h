// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenRelationalTriageSubsystem.generated.h"

/**
 * UAshenRelationalTriageSubsystem
 * GameInstance Subsystem managing the Soul Compilation Cycle, tracking unintegrated memories and active relational stances.
 */
UCLASS()
class ASHENOATH_API UAshenRelationalTriageSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Narrative")
	ECompiledRelationalStance ActiveStance = ECompiledRelationalStance::WeaverStance;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Narrative")
	TArray<FTriageIncidentRecord> ResolvedIncidents;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void RecordTriageResolution(FName IncidentID, EInterpretiveTherapyLens Lens, ECompiledRelationalStance ResultingStance);
};
