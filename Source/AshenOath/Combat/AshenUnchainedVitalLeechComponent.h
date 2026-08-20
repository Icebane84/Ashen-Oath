// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnchainedVitalLeechComponent.generated.h"

/**
 * UAshenUnchainedVitalLeechComponent
 * Evaluates Kaelen's 180° indiscriminate unchained greatsword sweeps and drains 15% vital reserves from companions caught in the arc.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnchainedVitalLeechComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnchainedVitalLeechComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float CompanionVitalLeechPercentage = 0.15f; // 15% drain

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ProcessUnchainedCleaveHit(AActor* HitTarget, bool bIsCompanion, float& OutVitalDrained);
};
