// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionDistressDialogueAdapter.generated.h"

/**
 * UAshenCompanionDistressDialogueAdapter
 * Dynamic character vocal callouts when companions enter Vulnerable fatigue or drop below 15% health.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDistressDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionDistressDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerCompanionDistressCallout(FName DistressedID, float HealthPercent, float FatigueLevel);
};
