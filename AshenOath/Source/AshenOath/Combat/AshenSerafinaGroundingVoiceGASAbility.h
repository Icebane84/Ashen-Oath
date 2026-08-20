// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSerafinaGroundingVoiceGASAbility.generated.h"

/**
 * UAshenSerafinaGroundingVoiceGASAbility
 * Emergency psychological grounding ability routed through the DualSense speaker ("Kaelen. Come back.") to halt unchained vessel burnout.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaGroundingVoiceGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSerafinaGroundingVoiceGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float CorruptionReductionPercent = 0.20f; // -20% corruption purge

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool TriggerGroundingVoice(AActor* InstigatorActor, AActor* TargetKaelen);
};
