// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFinisherGASDialogueAdapter.generated.h"

/**
 * UAshenFinisherGASDialogueAdapter
 * Dynamic character-specific dialogue callouts during finisher execution and socket alignment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherGASDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherGASDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerFinisherGASCallout(FName AbilityName, FName SpeakerID);
};
