// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenOathReactivityDialogueAdapter.generated.h"

/**
 * UAshenOathReactivityDialogueAdapter
 * Narrative adapter altering NPC dialogue trees based on player's sworn and breached oath records.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathReactivityDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathReactivityDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool EvaluateDialogueNodeForOathState(FName RequiredOathID, bool bMustBeFulfilled);
};
