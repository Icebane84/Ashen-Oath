// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenShepherdsGambitDialogueAdapter.generated.h"

/**
 * UAshenShepherdsGambitDialogueAdapter
 * Manages frantic companion dialogue barks when Kaelen is in the Unchained state (Garrett warning calls, Serafina grounding prayers).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShepherdsGambitDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShepherdsGambitDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerContainmentBark(EUnchainedHazardLevel HazardLevel);
};
