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

	/** Relieves Serafina's burnout fatigue (e.g. 50% during White Flame Resolution) */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void RelieveSerafinaBurnout(float ReliefRatio = 0.50f)
	{
		SerafinaFatigue = FMath::Clamp(SerafinaFatigue * (1.0f - ReliefRatio), 0.0f, 1.0f);
	}

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void SetSerafinaFatigue(float NewFatigue)
	{
		SerafinaFatigue = FMath::Clamp(NewFatigue, 0.0f, 1.0f);
	}

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	bool IsCompanionVulnerable(FName CompanionID) const;
};
