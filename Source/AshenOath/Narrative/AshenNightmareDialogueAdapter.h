// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenNightmareDialogueAdapter.generated.h"

/**
 * UAshenNightmareDialogueAdapter
 * Triggers fractured vocal barks and delirium responses when Kaelen experiences Catastrophic strain or high incursion debt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmareDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmareDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerIncursionPanicBark(FName SpeakerID, ETransferenceStrainStage StrainStage);
};
