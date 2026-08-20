// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenCompanionResonanceSyncEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResonanceSyncStateChanged, bool, bIsResonanceSyncActive);

/**
 * UAshenCompanionResonanceSyncEvaluator
 * World subsystem evaluating companion alignment (|SerafinaTrust - GarrettTrust| < 0.15f, Fatigue < 0.4f, Resolve > 0.5f); fires 15s GAS GameplayEffect damage bonus.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionResonanceSyncEvaluator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Companions")
	FOnResonanceSyncStateChanged OnResonanceSyncStateChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	bool bResonanceSyncActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	bool EvaluateResonanceSync(float GarrettTrust, float SerafinaTrust, float GarrettFatigue, float SerafinaFatigue, float ResolveScore);
};
