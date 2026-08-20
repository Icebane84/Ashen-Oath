// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAdvancedCombatDialogueAdapter.generated.h"

/**
 * UAshenAdvancedCombatDialogueAdapter
 * Companion reaction lines during parries, executions, and void shatters.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAdvancedCombatDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAdvancedCombatDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerCombatReactionDialogue(FName CompanionID, FString CombatEventType);
};
