// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryBattleDialogueReactivityAdapter.generated.h"

/**
 * UAshenMemoryBattleDialogueReactivityAdapter
 * Narrative adapter unlocking memory victory dialogue trees with Garrett and Serafina.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBattleDialogueReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryBattleDialogueReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool UnlockVictoryDialogueBranch(FName MemoryID);
};
