// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenTrialOfWillAIDirectorComponent.generated.h"

/**
 * UAshenTrialOfWillAIDirectorComponent
 * AI Director modulating companion tactical positioning based on Kaelen's stagger choices (Defiance -> Flank Cover, Trust -> Positional Anticipation).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrialOfWillAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTrialOfWillAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void NotifyStaggerChoiceExecuted(ETrialOfWillChoice Choice);
};
