// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenFinisherDialogueReactivityAdapter.generated.h"

/**
 * UAshenFinisherDialogueReactivityAdapter
 * Companion voice lines celebrating fellowship, relief from crisis interventions, and commenting on Kaelen's vulnerability.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherDialogueReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherDialogueReactivityAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerFinisherDialogueReaction(EAshenPartyFinisherType FinisherType, FName CompanionID);
};
