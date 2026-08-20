// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLivingCodexDialogueBridge.generated.h"

/**
 * UAshenLivingCodexDialogueBridge
 * Unlocks deep lore dialogue response branches when corresponding codex records are unlocked and read.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingCodexDialogueBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingCodexDialogueBridge();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool IsDialogueNodeUnlockedByCodex(FName RequiredCodexID, bool bCodexUnlocked, bool bCodexRead);
};
