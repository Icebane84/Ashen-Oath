// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenEpistemicDialogueAdapter.generated.h"

/**
 * UAshenEpistemicDialogueAdapter
 * Triggers companion contextual voice barks referencing specific historical Milestone combat outcomes recorded in Layer 0.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEpistemicDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEpistemicDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerHistoricalEventBark(FName CompanionID, FName EncounterID, bool bWasSynarchy);
};
