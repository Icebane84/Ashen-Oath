// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenCompetingMonologueEvaluatorComponent.generated.h"

/**
 * UAshenCompetingMonologueEvaluatorComponent
 * Evaluates psychological tension by routing conflicting voices across channels (e.g. Garrett TV "Fall back!" vs Kaelen Controller "I can take it").
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompetingMonologueEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompetingMonologueEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerCompetingMonologuePair(const FString& ExternalWorldVoice, const FString& InternalControllerVoice);
};
