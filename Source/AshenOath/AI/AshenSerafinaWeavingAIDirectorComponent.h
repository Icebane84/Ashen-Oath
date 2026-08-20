// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenSerafinaWeavingAIDirectorComponent.generated.h"

/**
 * UAshenSerafinaWeavingAIDirectorComponent
 * AI Director scanning Kaelen's poise health in real time, commanding Serafina to deploy an Aegis Net when poise drops below 25%.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaWeavingAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaWeavingAIDirectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | AI")
	float CriticalPoiseThreshold = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool EvaluateWeavingPriority(float KaelenPoisePercentage, bool& bShouldDeployAegis);
};
