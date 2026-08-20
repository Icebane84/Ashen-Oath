// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingJournalConsequenceTypes.h"
#include "AshenLivingJournalDialogueAdapter.generated.h"

/**
 * UAshenLivingJournalDialogueAdapter
 * Triggers Kaelen's internal monologues and companion banter when traveling through Ley-Conduit vs Obsidian-Fracture map sectors.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingJournalDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingJournalDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerConstellationSectorDialogue(EConstellationNodeVisual SectorState);
};
