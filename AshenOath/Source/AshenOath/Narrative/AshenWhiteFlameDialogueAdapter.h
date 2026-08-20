// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhiteFlameDialogueAdapter.generated.h"

/**
 * UAshenWhiteFlameDialogueAdapter
 * Manages triumphant, emotionally cathartic companion dialogue lines during White Flame activation and pyre cleaves.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlameDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerCatharsisDialogue();
};
