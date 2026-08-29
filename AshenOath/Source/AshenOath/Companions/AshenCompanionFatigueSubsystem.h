// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCompanionFatigueSubsystem.generated.h"

/**
 * UAshenCompanionFatigueSubsystem
 * GameInstance Subsystem managing Tripartite Fatigue (Garrett Control, Serafina Poise, Kaelen Transference) and recovery pacing.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionFatigueSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float GarrettFatigue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float SerafinaFatigue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float KaelenFatigue = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void AccumulateFatigue(FName CompanionID, float Delta);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void RecoverFatigue(float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void ResetAllFatigue();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	bool IsCompanionVulnerable(FName CompanionID) const;
};
