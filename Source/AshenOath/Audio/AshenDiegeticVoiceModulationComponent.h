// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticVoiceModulationComponent.generated.h"

/**
 * UAshenDiegeticVoiceModulationComponent
 * Audio component modulating voice filter parameters (muffled in Mindscape, panicked during high debt).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticVoiceModulationComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticVoiceModulationComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void ApplyVoiceDSPFilter(bool bInMindscape, float DebtLevel);
};
