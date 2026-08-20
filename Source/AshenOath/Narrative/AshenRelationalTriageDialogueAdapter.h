// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenRelationalTriageDialogueAdapter.generated.h"

/**
 * UAshenRelationalTriageDialogueAdapter
 * Manages narrative dialogue barks and confrontation lines for the Chapter 4 garden triage scene and subsequent encounters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalTriageDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRelationalTriageDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerTriageBark(EInterpretiveTherapyLens Lens);
};
