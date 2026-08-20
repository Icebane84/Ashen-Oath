// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryPalaceDialogueAdapter.generated.h"

/**
 * UAshenMemoryPalaceDialogueAdapter
 * Unlocks deep narrative dialogue branches and lore exposition when specific memory loci are reconstructed.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool IsLoreDialogueUnlocked(FName LoreID, int32 UnsealedLocusCount);
};
