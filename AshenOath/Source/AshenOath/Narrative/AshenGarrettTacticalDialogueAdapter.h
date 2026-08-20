// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettTacticalDialogueAdapter.generated.h"

/**
 * UAshenGarrettTacticalDialogueAdapter
 * Triggers tactical banter lines during trap triggers and smoke deployments.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTacticalDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGarrettTacticalDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerTacticalBanter(FString ActionType);
};
