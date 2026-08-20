// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenLivingOathDialogueAdapter.generated.h"

/**
 * UAshenLivingOathDialogueAdapter
 * Triggers dynamic companion dialogue callouts during oath swearings, fulfillment milestones, and oathbreaker failures.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingOathDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingOathDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerOathDialogue(EAshenLivingOathType OathType, EAshenOathState State, FName CompanionID);
};
