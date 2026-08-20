// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNullZoneDialogueAdapter.generated.h"

/**
 * UAshenNullZoneDialogueAdapter
 * Narrative barks and warning dialogues when approaching corruption hotspots.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNullZoneDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNullZoneDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerNullZoneBark(FName SpeakerID, float ProximityRatio);
};
