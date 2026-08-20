// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBrotherMalakorDialogueAdapter.generated.h"

/**
 * UAshenBrotherMalakorDialogueAdapter
 * Inquisitorial condemnation voice lines and scripture accusations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBrotherMalakorDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBrotherMalakorDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerInquisitionCondemnation(uint8 PhaseIndex);
};
