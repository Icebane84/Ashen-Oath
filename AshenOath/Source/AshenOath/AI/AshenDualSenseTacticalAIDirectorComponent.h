// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenProximityOfConsciousnessTypes.h"
#include "AshenDualSenseTacticalAIDirectorComponent.generated.h"

/**
 * UAshenDualSenseTacticalAIDirectorComponent
 * AI Director coordinating companion attack state machines with DualSense tactical audio cues.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseTacticalAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualSenseTacticalAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void NotifyPostureBreakOpportunity(FName MonsterID);
};
