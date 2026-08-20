// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenNightmareIncursionSubsystem.generated.h"

/**
 * UAshenNightmareIncursionSubsystem
 * GameInstance Subsystem managing environmental Nightmare Incursions, incursion threshold triggers (Debt >= 0.75), and incursion timers.
 */
UCLASS()
class ASHENOATH_API UAshenNightmareIncursionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nightmare")
	FNightmareIncursionState CurrentIncursionState;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nightmare")
	bool EvaluateIncursionTrigger(float CurrentIntegrationDebt);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nightmare")
	void SetIncursionIntensity(float Intensity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nightmare")
	void RegisterRift(bool bOpened);
};
