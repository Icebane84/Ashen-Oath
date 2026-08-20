// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenPsychicReconstructionGASAbility.generated.h"

/**
 * UAshenPsychicReconstructionGASAbility
 * GAS ability channeling Resolve (15.0/s) to reconstitute shattered memory architecture within 1200uu.
 */
UCLASS()
class ASHENOATH_API UAshenPsychicReconstructionGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenPsychicReconstructionGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Memory")
	float ReconstructionRadius = 1200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Memory")
	float ResolveCostPerSecond = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool ChannelReconstruction(AActor* InstigatorActor, float ChannelDuration);
};
