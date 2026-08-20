// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionDialogueNPCReactivityAdapter.generated.h"

/**
 * UAshenCompanionDialogueNPCReactivityAdapter
 * Adapter synchronizing companion dialogue state with town NPC ambient banter.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionDialogueNPCReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionDialogueNPCReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerTownBanterForCompanionState(FName CompanionID, FString Mood);
};
