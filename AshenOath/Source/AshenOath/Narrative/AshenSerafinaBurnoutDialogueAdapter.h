// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaBurnoutDialogueAdapter.generated.h"

/**
 * UAshenSerafinaBurnoutDialogueAdapter
 * Plays weary dialogue lines and coughs when burnout exceeds 70%.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaBurnoutDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaBurnoutDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerWearyDialogue(float BurnoutLevel);
};
