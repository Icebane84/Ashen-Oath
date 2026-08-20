// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryBattleDialogueAdapter.generated.h"

/**
 * UAshenMemoryBattleDialogueAdapter
 * Dynamic voice whispers and companion support callouts during memory battles and lorekeeper communions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBattleDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryBattleDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerMemoryDialogue(FName EchoID, bool bVictory, FName SpeakerID);
};
