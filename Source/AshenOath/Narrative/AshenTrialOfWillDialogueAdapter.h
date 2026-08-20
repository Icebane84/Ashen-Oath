// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenExistentialMeaningTypes.h"
#include "AshenTrialOfWillDialogueAdapter.generated.h"

/**
 * UAshenTrialOfWillDialogueAdapter
 * Manages companion dialogue barks triggered dynamically by Kaelen's choices in the Trial of Will.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrialOfWillDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTrialOfWillDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerStaggerDialogueBark(ETrialOfWillChoice Choice);
};
