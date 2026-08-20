// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenControllerFrictionTypes.h"
#include "AshenControllerFrictionAIDirectorComponent.generated.h"

/**
 * UAshenControllerFrictionAIDirectorComponent
 * Modulates AI aggression and elite overhead attack telegraphing to synchronize with Kaelen's struggle phases.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenControllerFrictionAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenControllerFrictionAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void NotifyStrugglePhaseChanged(EStrugglePhase Phase);
};
