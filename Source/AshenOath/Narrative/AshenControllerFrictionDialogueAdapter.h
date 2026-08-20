// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenControllerFrictionTypes.h"
#include "AshenControllerFrictionDialogueAdapter.generated.h"

/**
 * UAshenControllerFrictionDialogueAdapter
 * Manages companion dialogue barks reacting dynamically to Kaelen's physical struggle phases (trembling hands, lunge intercepts).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenControllerFrictionDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenControllerFrictionDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerStruggleDialogueBark(EStrugglePhase Phase);
};
