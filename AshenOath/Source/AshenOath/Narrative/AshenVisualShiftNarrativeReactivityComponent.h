// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVisualShiftNarrativeReactivityComponent.generated.h"

/**
 * UAshenVisualShiftNarrativeReactivityComponent
 * Component triggering NPC fear reactions when Kaelen's Shadow Mark C emissive is high.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVisualShiftNarrativeReactivityComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenVisualShiftNarrativeReactivityComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool EvaluateNPCFearReaction(float CorruptionIntensity);
};
